//Cracked by Roath
// publisher.c
// by snowbird 1999


#include <ansi.h>
#include <localtime.h>

inherit NPC;
inherit F_SKILL;

int ask_book();
int ask_sell();
void check_book();
void enough_rest();
void clear_book();

string is_vendor_good(string arg);
string query_book_file( string arg);

mapping *sell_list;

void create()
{
	set_name("书贾", ({ "shu jia", "publisher", "jia"}));
	set_color(YEL);
	set("long", "这是一位白白胖胖的中年人，身子微微发福，是个富商豪绅模样。\n"
	"他手中提着一个小箱子，正笑眯眯地上下打量着你。\n"
        "据说他曾经试过科举，但几次不中后便改行以贩书为业了。\n");
	set("gender", "男性");
	set("age", 45);
    set("weight", 50000);
    set("str", 25);
    set("dex", 25);
	set("attitude", "peaceful");

    set("combat_exp", 75000);
    set("shen_type", 0);

    set_skill("unarmed", 60);
    set_skill("force", 60);
    set_skill("literate", 300);

    set("neili", 4000); 
    set("max_neili", 4000);
    set("jiali", 500);

    set("owner", 1);
    set("no_clean_up", 1);

    set("inquiry", ([
	    "profit" : (: ask_book :),
	]));

    set("vendor_goods", ({
                                        
		  "/d/city/obj/newbook1",
    }));

//    set("chat_chance", 3);
//	set("chat_msg",({
//               (: check_book :),
//    }));

 
	setup();

    carry_object("/d/city/obj/guazi")->wear();

    remove_call_out("check_book");
    call_out("check_book", 3+random(5) );

}


int init()
{
  object ob;
  ob = this_player();
  ::init();

  add_action("do_list", "list");
  add_action("do_buy", "buy");
  add_action("do_publish","publish");

  if( interactive(ob = this_player()) && !is_fighting() ) {
       remove_call_out("greeting");
       call_out("greeting", 1, ob);
  }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        message_vision(	"$N朝$n微微笑了笑。\n",this_object(),ob );
        switch( random(2) ) {
                case 0:
                        say( "书贾笑眯眯地说道：这位" + RANK_D->query_respect(ob)
                                + "，想要刊行您的著作吗？这可找对人了。\n");
                        break;
                case 1:
                        say( "书贾笑眯眯地说道：这位" + RANK_D->query_respect(ob)
                                + "，我这有各种江湖文士写的笔录，看看您想要买哪一本。\n");
                        break;
        }
}


int do_publish(string arg)
{
	object me, this_book, save_book;
    mapping book_content;

    if(!arg) return notify_fail("您要刊行什么？\n");

	me = this_player();
    this_book = present(arg, me);

    if(!this_book)
            return notify_fail("你身上好像并没有这样东西？\n");
    if(!this_book->query("publishable"))
            return notify_fail("对不起！这样东西我无法刊印。\n");
    if(me->is_busy())
            return notify_fail("你现在正忙着呢。\n");



// get the book content 
    book_content=this_book->query("book_content");
// stamp on time, number of book sold, money made and the marker not to discard it
// also set the initial price to be 20 silver
	book_content["publish_time"] = ctime(time());
	book_content["book_sold"] = 0;
	book_content["money_made"] = 0;
	book_content["keep_marker"] = 0;
	book_content["current_price"] = 2000;
    save_book=new("/clone/misc/save_book");
    save_book->set_owner(book_content["arthur_id"]);
    save_book->save_this_book(book_content);
    message_vision(	"$N高高兴兴地把$n写的稿纸拿去刊印了。\n\n",this_object(),me );

    destruct(save_book);
	destruct(this_book);
    return 1;
}

int do_list()
{
        string *goods, long_name;
        object *inv;
        int i, j, k;

        inv = all_inventory(this_object());
		k = 0;
        if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
                return notify_fail("目前没有可以买的东西。\n");
        // list the cloneable goods
        if (arrayp(goods = query("vendor_goods"))){
                for (i = 0; i < sizeof(goods); i++)
                        printf("%65-s：%s\n", goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
        }
		// list the inventory for sell
        for (i = 0; i < sizeof(inv); i++) 
		{
                if (inv[i]->query("can_sell_book"))
				{
					k++;
					long_name = sprintf("%s(%s%d)",(inv[i]->query("new_book"))["title"],inv[i]->query("id"),k);
                    printf("%35-s 【作者】%20-s ：%s\n", long_name, 
                    (inv[i]->query("new_book"))["arthur"],MONEY_D->price_str(inv[i]->query("value")));
				}
		}
        return 1;
}       

int do_buy(string arg)
{
        int book_no, value, val_factor, i, k, book_found;
        string ob_file, file;
        object ob, obj, *inv;


        k = 0;
		book_found = 0;
        if (!arg)
                return notify_fail("你想买什么？\n");
        if (ob && ob->query("money_id"))
                return notify_fail("你想买「钱」？？\n");

		if (arg == "book")
		{
		    ob_file = is_vendor_good(arg);
			ob = new(ob_file);
			val_factor = 10;
		}
		else if( sscanf(arg, "book%d", book_no) == 1 ) 
		{
            inv = all_inventory(this_object());
			if(!sizeof(inv))
			    return notify_fail("你想买的东西我这里没有。\n");
            for (i = 0; i < sizeof(inv); i++) 
	     	{
                if (inv[i]->query("can_sell_book"))
				{
					k++;
    				if ( k == book_no ) {
					   ob = inv[i];
					   book_found = 1;
					}
		 		}
		    }
			if (!book_found)
				return notify_fail("你想买的东西我这里没有。\n");
		}
		else 
		{
			return notify_fail("你想买的东西我这里没有。\n");
        }

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

        
  switch (MONEY_D->player_pay(this_player(), ob->query("value") *  val_factor / 10)) {
        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        default:
                set_temp("busy", 1);
                message_vision("$N从$n那里买下了一" + ob->query("unit") + 
                ob->query("name") + "。\n", this_player(), this_object());
				// save the number of book sold and money made to file
				if(book_found) {
                   obj=new("/clone/misc/save_book");
                   obj->set_owner((ob->query("new_book"))["arthur_id"]);
                   obj->save_book_sold(ob->query("book_number"),ob->query("value")/2);
				   destruct(obj);
				}
                ob->move(this_player());
        }
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

        return 1;
}

string is_vendor_good(string arg)
{
        string *goods;
        object ob;
        int i;

        if (arrayp(goods = query("vendor_goods"))) 
                for (i = 0; i < sizeof(goods); i++) 
                        if (goods[i]->id(arg))
                                return goods[i];
        return "";
}

void enough_rest()
{
        delete_temp("busy");
}

string query_book_file( string arg)
{
         return sprintf( DATA_DIR "book/%c/%s", arg[0], arg );
}

void check_book()
{

   string *dir_list, *time_list;
   string file, arthur_id, time_lable; 
   object new_book, real_book, *inv, temp_book;
   mixed *file_list;
   int i, j, k, l, call_time;
   mapping book_info;
   mixed *local;
   object me = this_object();

   // get our local time first
   local = localtime(time()*60);

   if (!(me->query("last_clear_book_time"))) {
	  // this is the first time we clearing the book
	  // record the current year
	  me->set("last_clear_book_time",local[LT_YEAR]);
   }
   else {
	  // we have recorded a time before, so let's check if we need
	  // to clear the books
	  if ((local[LT_YEAR] - me->query("last_clear_book_time")) == 1) {
		  // ok one year has passed, time to clear the books
		  // first set our new clear book time
          set_temp("busy", 1);
	      me->set("last_clear_book_time",local[LT_YEAR]);
		  clear_book();
          delete_temp("busy");
	  }
	  else {
		  // if the time is messed up, refresh our count
    	  me->set("last_clear_book_time",local[LT_YEAR]);
	  }
   }

   time_list = ({});
   k = 0;
   inv = all_inventory(this_object());
   if (!sizeof(inv))
       k = 0;
   else {
	  // build my book time list
	  for (i = 0; i<sizeof(inv); i++) {
		 if ( inv[i]->query("can_sell_book") ) {
		   time_list += ({ inv[i]->query("time_stamp") });
		   k++;
		 }
	  }
      // if the there are 40 books, get ride one of them, randomly
      if (k>39) {
	      l = random(sizeof(inv));
		  if ( inv[l]->query("can_sell_book") ) {
			 temp_book = inv[l];
 			 time_list -= ({ inv[l]->query("time_stamp") });
			 destruct(temp_book);
		  }
      }
   }

   // if publisher have 20 book in his invertory, slow down checking for new books
   if (k<20) 
	  call_time = 2;
   else
      call_time = 30;

   //  get my random arthur
   dir_list = explode("a b c d e f g h i j k l m n o p q r s t u v w x y z", " ");
   //   dir_list = explode ("a s"," ");
   i = random(26);
   file_list = get_dir(DATA_DIR + "book/" + dir_list[i] + "/");
   // if no file, then exit
   if (!sizeof(file_list)) {
	  // do nothing here
   }
   else {
      j = random(sizeof(file_list));

      sscanf(file_list[j], "%s.o", arthur_id);
        
      file = query_book_file( arthur_id+".o" );
      assure_file( file );

      if(file_size(file)!=-1)  {

          new_book=new("/clone/misc/save_book");
          new_book->set_owner(arthur_id);
 		  real_book = new_book->get_new_book();

          time_lable = real_book->query("time_stamp");
		  // if this time_stamp is not the same as something in invertory then get it
		  // if there are already 30 books in his inventory, don't create anymore
		  if ( member_array(time_lable, time_list) == -1 && k<40) {
			  real_book->set("can_sell_book",1);
			  real_book->move(this_object());
		  }
		  else {
			  destruct(real_book);
		  }
      }
      destruct(new_book);
   }
   remove_call_out("check_book");
   call_out("check_book", call_time+random(3) );

}

int ask_book()
{
   object me, new_book;
   string file, arthur_id;
   me=this_player();

   arthur_id = me->query("id");
   file = query_book_file( arthur_id+".o" );
   assure_file( file );

   if(file_size(file)!=-1)  {
          new_book=new("/clone/misc/save_book");
          new_book->set_owner(arthur_id);
		  new_book->pay_player_profit();
   }
   else {
        return notify_fail("你还未刊行出一本书，就想要钱？\n");
   }

   destruct(new_book);
   return 1;

}

void clear_book() 
{

   string *dir_list;
   string file, arthur_id; 
   object new_book, *inv, temp_book;
   mixed *file_list;
   int i, j, k, l;

   dir_list = explode("a b c d e f g h i j k l m n o p q r s t u v w x y z", " ");
   for (i=0; i<26; i++) {
      file_list = get_dir(DATA_DIR + "book/" + dir_list[i] + "/");
      if (!sizeof(file_list)) {
    	 // do nothing here
      }
      else {
         k = sizeof(file_list);
		 for (j=0; j<k; j++) {
            sscanf(file_list[j], "%s.o", arthur_id);
            file = query_book_file( arthur_id+".o" );
            assure_file( file );

            if(file_size(file)!=-1)  {
               new_book=new("/clone/misc/save_book");
               new_book->set_owner(arthur_id);
			   new_book->clear_book();
			}
		 }
      }
   }
   destruct(new_book);
   return;
}
