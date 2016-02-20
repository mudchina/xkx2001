//Cracked by Roath
#include <ansi.h>
inherit ITEM;


int start_book_title(object me);
void get_book_title(string book_title, object ob);
int start_book_text(object me, int p_no);
void get_book_text(string str, int p_no);
int help(object me);

mapping new_book = ([]);
mapping text = ([]);
// text = allocate( string 20 );

void create()
{
        set_name("纸稿", ({"book"}));
        set_weight(10);
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一本空白的书，你可以在上面写字。(write)\n");
                set("unit", "本");
                set("material", "paper");
                set("value", 100000);
        }
}
int init()
{
    add_action("do_title","title");
    add_action("do_write", "write");
    add_action("do_read", "read");   
}

int do_title(string arg)
{
          object me;
          object this_book;

          me = this_player();
		  this_book = this_object();

          if (arg != "book") 
              return  notify_fail("你要写什么？\n");

          if(!this_book->query("titled"))
 		  {
              start_book_title(me);
		  }
		  else {
              message_vision("$N左想右想，又决定要把书名改一改。\n"NOR,me);
			  start_book_title(me);
		  }

		  return 1;

}

int start_book_title(object me)
{
    tell_object(me,"【书名】:");
    input_to( (: get_book_title :), me );
	return 1;
}

void get_book_title(string book_title, object ob)
{
        object me, this_book;

        me=ob;
		this_book = this_object();

        if( !book_title || (strlen(book_title)<2) ) {
              write("请先写书名。\n");
              tell_object(this_player(),"【书名】:");
              input_to( (: get_book_title :),  me);
              return;
        }

        message_vision("$N想了半天，终于在封皮上题了一个书名。\n"NOR,me);

		new_book["title"] = book_title;
        new_book["arthur"] = me->name(1) + "(" + me->query("id") + ")";
        new_book["arthur_id"] = me->query("id");
 
        this_book->set("titled",1);
        this_book->set_name(book_title, ({"book"}));
		this_book->set("long", "一本未写完的书，你可以在上面接着写。(write book)\n");
        this_book->set("book_content",new_book);

        return;        
}

int do_write(string arg)
{
          string msg;
          object me;
          object this_book;
		  int page_no;

          me = this_player();
		  this_book = this_object();

	      if( !arg || sscanf(arg, "%s %d", msg, page_no)!=2 ) return help(me);

          if (msg != "page") 
              return  notify_fail("写书用 (write page #) 。\n");
		  if (page_no > 20 || page_no < 1) 
              return  notify_fail("写书在 1 到 20 页之间。\n");
          if(!this_book->query("titled"))
		      return  notify_fail("你还没有给书题名呢，先想个书名再说把 (title book)。\n");
		  else 
		  {
              message_vision("$N拿出一支笔，铺开书本，开始写作.....\n"NOR,me);
			  start_book_text(me, page_no);
		  }
          return 1;

}


int start_book_text(object me, int p_no)
{
        write("【书本内容】:\n");
        me->edit( (: get_book_text, p_no :) );
        return 1;
}

void get_book_text(int p_no, string str)
{

        message_vision("$N写完一段，放下手中的笔。\n"NOR,this_player());
   		text[p_no] = str;
        new_book["text"] = text;


        this_object()->set("book_content",new_book);
        this_object()->set("text_written",1);
        this_object()->set("publishable",1);
        return;
        
}

int do_read(string arg)
{
        string msg, this_page;
		int page_no;
		object me, this_book;

        me = this_player();
		this_book = this_object();

        if( !arg || sscanf(arg, "%s %d", msg, page_no)!=2 ) return help(me);

        if (msg != "page") 
             return  notify_fail("读书用 (read page #) 。\n");
    	if (page_no > 20) 
              return  notify_fail("书不超过 20 页。\n");

        if(!this_book->query("text_written"))
             return  notify_fail("这本书还没写，怎么读？\n");

        if(!(this_page = new_book["text"][page_no]))
             return  notify_fail("这一页还没写，怎么读？\n");;

        printf("【%s】：\n【作者】：%s\n\n",
		new_book["title"],new_book["arthur"]);
		this_player()->start_more(this_page);

        
        return 1;
}

int help(object me)
{
	write("指令格式：\n
	写书用 (write page #) 。\n
	读书用 (read page #) 。\n");
	return 1;
}
