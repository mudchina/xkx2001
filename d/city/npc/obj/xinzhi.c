//Cracked by Roath
// Write by Wzfeng 12-29-1998
//change By Wzfeng 4/1/1999
#include <ansi.h>
inherit ITEM;
int  start_letter(object me);
void get_send_name(string username, object ob);
void get_letter_title(string str, mapping letter,object me);
void get_letter_text(mapping letter, string str);


void create()
{
	set_name("白纸", ({"paper"}));
	set_weight(10);
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一张刚买来的宣纸，可以用来写信(write letter)。\n");
		set("unit", "张");
		set("material", "paper");
		set("value", 10);
	}
}
int init()
{
    add_action("do_write", "write");
    
}


int do_write(string arg)
{
           object me,ob_bi,ob_paper;
           object ob_letter;
            me=this_player();
          	if (arg != "letter") 
				 return  notify_fail("你要写什么？\n");
          if(!ob_bi=present("mao bi",me))
                 return  notify_fail("你好像没有写信的工具吧？最好去买支毛笔！\n");
		  if (this_player()->is_busy())
				return notify_fail("你正忙着呢！等你有功夫时在写吧。\n");

          message_vision("只见$N拿出一支毛笔，展开白纸，奋笔疾书......\n"NOR,me);
          //destruct(ob_paper);
          start_letter(me);
          return 1;
        }

int start_letter(object me)
{
  tell_object(me,"【收信人】(英文姓名):\n");
  input_to( (: get_send_name :), me );

}

void get_send_name(string username, object ob)
{
        mapping letter;
        object me;
        me=ob;
        ob = FINGER_D->acquire_login_ob(username);
        if( !ob ) {
                write("没有这个人。\n");
          tell_object(this_player(),"【收信人】(英文姓名):\n");
      input_to( (: get_send_name :),  me);
          return;
        }
        letter = ([
                "from": me->name(1) + "(" + me->query("id") + ")",
                "title": "无标题",
                "to": username,
                "time": time(),
                "text": ""
        ]);
        write("【书信标题】:");
    input_to("get_letter_title", letter,me);
        
}


void get_letter_title(string str, mapping letter,object me)
{
        if( str!="" ) 
                letter["title"] = str;
        write("【书信内容】:\n");
        me->edit( (: get_letter_text, letter:) );
}

void get_letter_text(mapping letter, string str)
{
        object ob_letter;
                
        
        letter["text"] = str;
        message_vision("只见$N长舒一口气，将毛笔放到一旁，将写好的书函叠起来放在怀里。\n"NOR,this_player());
        
		/*ob_letter=new("/clone/misc/xin");
        ob_letter->set_owner(letter["to"]);
		ob_letter->set("long", "一封已经写好的信，你可用读(read letter)来看它的内容。\n");
		ob_letter->set_name(HIW"信"NOR, ({"letter", "xin"}));
        ob_letter->set("can_feng",1);
		ob_letter->set("can_send",0);
		ob_letter->send_letter(letter);
		*/
		ob_letter=new("/d/city/obj/letter1");
		ob_letter->set("letter",letter);
		ob_letter->set("can_feng",1);
		ob_letter->set("can_send",0);
        ob_letter->move(this_player());
        destruct(this_object());
          return;
        
}







