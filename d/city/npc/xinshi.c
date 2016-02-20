//Cracked by Roath
// Write by Wzfeng 12-29 //main fuction
// modified by sdong, 12/29/98
// Change by Wzfeng, 3/1/98  // add ask jin nang

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;
int ask_me();
int ask_jinnang();
void create()
{
                  set_name("驿丞", ({ "yi cheng", "cheng" ,"cheng" }));
                  set("shen_type", 1);

                  set("gender", "男性");
                  set("age", 45);
                  set("long",
"他是专门负责这里书函传递的官员。\n"
);
                  set("attitude", "friendly");
                  set("inquiry", ([
                                "送信" : (: ask_me :),
                                "send" : (: ask_me :),
								"锦囊" : (:ask_jinnang :),
                  ]));

                  set("vendor_goods", ({
					  
                                __DIR__"obj/maobi",
                                __DIR__"obj/xinzhi",
                                __DIR__"obj/xinfeng",
                                __DIR__"obj/xinfeng1",
                                __DIR__"obj/xinfeng2",
                  }));
  

/*				   set("vendor_goods", ([
                __DIR__"obj/maobi":99,
                __DIR__"obj/xinzhi":99,
				__DIR__"obj/xinfeng":99,
				__DIR__"obj/xinfeng1":99,
				__DIR__"obj/xinfeng2":99,
              

                
        ]));
  */     
  
                  setup();

                 remove_call_out("do_check_letter");
                 call_out("do_check_letter", 3+random(10) );

}

void init()
{
         object ob;
         ob=this_object();
         add_action("do_list", "list");
         add_action("do_buy", "buy");
         add_action("do_send", "send");
         add_action("do_check_letter", "check");
}

int do_emote(string str)
{
        message_vision(CYN "$N招了招手，一个驿使走了过来。\n"NOR, this_object());
        message_vision(CYN "$N对驿使说道：“这是送给"+str+"的书函，赶快送去，勿要失落。\n"NOR, this_object());
        message_vision(CYN "驿使将书函接过来贴身放好，向$N拱手道：“小的这就出发”。\n"NOR, this_object());
        message_vision(CYN "驿使牵过一匹快马，翻身跃上马背，扬长而去......\n"NOR, this_object());
        return 1;
}

string query_letter_file( string arg)
{
         return sprintf( DATA_DIR "letter/%c/%s", arg[0], arg );
}

int do_check_letter()
{
                object *ob,ob_letter;
                 string file ;
                  int i;
                  ob=objects();
                  i = sizeof(ob);
                  while (i--)
                {
                        if (userp(ob[i]))
                        {

                                file = query_letter_file( ob[i]->query("id")+".o" );
                                assure_file( file );

                                if(file_size(file)!=-1)
                                {

                                        if(interactive(ob[i]))
                                        if(living(ob[i]))
                                        if(!ob[i]-> is_busy())
                                        if(!ob[i]-> is_fighting() )
                                        {
                                                ob_letter=new("/clone/misc/xin");
                                                ob_letter->set_owner(ob[i]->query("id"));
                                                ob_letter->check(ob[i],this_object());
                                        }
                                }
                        }
                }

          remove_call_out("do_check_letter");
          call_out("do_check_letter", 3+random(10) );

          return 1;
}





int ask_me()
{
        write("驿丞对你说到：“要想托这里送信，请先将书函封好，然后交给我。”\n"
                "命令 send letter \n");
                return 1;
}
int do_send(string arg)
{
        object ob_letter,me,send_letter;

        int i;
        mapping letter;


        me=this_player();
        if(!arg) return notify_fail("你要托送什么？\n");

        ob_letter = present(arg, me);
        if(!ob_letter)
                return notify_fail("你身上好像并没有这种物品？\n");
        if(!ob_letter->query("can_send"))
                return notify_fail("对不起！我们这里不负责送这个。\n");
		if(me->is_busy())
			    return notify_fail("你现在正忙着呢。\n");

		letter=ob_letter->query("letter");
		
		send_letter=new("/clone/misc/xin");
		send_letter->set_owner(letter["to"]);
		
		//防止flood,如果发现以前未发的信中有和这封一样的，就拒绝发这封信。
		//////////////////////////////////////////////////////////////


			if((letter["from"]==send_letter->query("last_from"))&&
				(letter["text"]==send_letter->query("last_text")))
		  {
			  command("hmm ");
			  return notify_fail("您好像托我传交过一封和这一样的信函，我现在忙得很，您待会再来吧。\n");
		  }
		//////////////////////////////////////////////////////////////		
		


        switch( ob_letter->query("letter/send_level"))
        {
                                case 1:
                                message_vision("$N接过$n递过来的封套，看了一眼，随手放在桌底抽屉里。\n", this_object(),me);
                                                  break;
                                case 2:
                                message_vision(HIY"$N接过$n递过来的缄封，看了一眼，对$n说道：“快件，好，我会尽快送出的。”\n"NOR, this_object(),me);
                                                  break;
                                case 3:
                                message_vision(HIR"$N接过$n递过来的帛套，一看之下，连忙站起身来对$n说到：“啊！十万火急，我马上叫人去送这封文书！”\n"NOR, this_object(),me);
									                break;
                    
        }
		
		send_letter->add_send_level(ob_letter->query("letter/send_level"));
	
		//由于在以前的版本中存在着两个参数，如果将所有保存letter的文件
		//删除，这两句可删掉，否则，还是留下吧。
		//////////////////////////////////////////////////////////////
		send_letter->set("can_send",0);
		send_letter->set("can_feng",0);
        //////////////////////////////////////////////////////////////
		
		
		send_letter->send_letter(letter);
		send_letter->set("last_from",letter["from"]);
        send_letter->set("last_text",letter["text"]);
		send_letter->save();

        destruct(send_letter);
		destruct(ob_letter);
		do_check_letter();
		me->start_busy(1);
		

        return 1;
}

int ask_jinnang()
{
	object ob,me;
	ob=this_object();
	me=this_player();

    
    if(me->query("have_jinnang"))
	if(present("jin nang", me))
	{
		tell_object(me,CYN"驿丞对你说到：“你不是已经有一个了吗？”\n"NOR);
		return 1;
	}
	else
	{
		tell_object(me,CYN"驿丞对你说到：“你不是已经有一个了吗？”\n"NOR);
		tell_object(me,CYN"驿丞对你说到：“哦！弄丢了？”\n"NOR);
		command("consider ");
		tell_object(me,CYN"驿丞在你耳边悄悄说到：“拿十两金子来，我就再给你一个！”\n"NOR);
		me->set_temp("can_give_jinnang",1);
		return 1;
	}

	
	if(me->query_temp("can_give_jinnang"))
	{
		tell_object(me,CYN"驿丞对你说到：“我不是已经告诉你了吗？”\n"NOR);
		return 1;
	}
  
	
	message("vision", CYN "只见"+me->query("name")+"在驿丞耳边悄悄的说了几句话。\n" NOR, environment(me), me);
  	tell_object(me,CYN"你在驿丞耳边悄悄说到：“能帮我搞个装信的锦囊么？”\n"NOR);
	command("ah");
	tell_object(me,CYN"驿丞在你耳边悄悄说到：“你想要一个装信的锦囊？”\n"NOR);
    tell_object(me,CYN"驿丞在你耳边悄悄说到：“锦囊珍贵无比，十两金子一个，不二价！”\n"NOR);
	message("vision", CYN "只见驿丞在"+me->query("name")+"耳边悄悄的说了几句话。\n" NOR, environment(me), me);
    me->set_temp("can_give_jinnang",1);
	
	return 1;
  
}

int accept_object(object who, object ob)
{
	int value;
	object ob1,money,Ob_JinNang;
	ob1=this_object();
	if(!who->query_temp("can_give_jinnang"))
	{
		command("? "+who->query("id"));
		return 0;
	}
	if(!ob->query("base_value"))
	{
		command("? "+who->query("id"));
		write("!ob->query(value)\n");
		return 0;
	}
       switch( ob->query("id"))
        {
		   case "gold":
                value=1000;
				  break;
		  case "silver":
    			value=100;
				  break;
		   case "coin":
    			value=10;
				  break;
		   default:
			   {
			   	   command("shake "+who->query("id"));
				   write("驿丞对你说到：“对不起，我这里不收银票，请拿到当铺换好了再来吧！”\n");
						return 0;			   
			   }
        }


	value*= ob->query_amount();


	if(value<10000)
	{
		command("shake "+who->query("id"));
		tell_object(who,CYN"驿丞对你说到：“我说过，十两黄金，这些哪里够？”\n"NOR);
		return 0;
	}


	command("nod "+who->query("id"));
	tell_object(who,CYN"驿丞对你说到：“这一个锦囊，您小心收好。”\n"NOR);
	write("驿丞给你一个锦囊。\n");
	who->set("have_jinnang",1);

	Ob_JinNang=new("/clone/misc/jinnang");
	Ob_JinNang->move(who);


	return 1;
	
}



