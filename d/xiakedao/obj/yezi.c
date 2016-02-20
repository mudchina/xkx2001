//Cracked by Roath
// yezi.c 椰子
// ssy
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("椰子", ({ "yezi", "ye" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", "一只大椰子，很是诱人。\n");
                set("value", 70);
        }
        setup();
}
void init()
{
     add_action("do_eat", "eat");
     add_action("do_za", "za");
}

int do_za(string arg)
{
        object me = this_player();
        object stone,ke;
        int check;
	int level;

        if ( !arg )
                return notify_fail( "你想砸什么？\n");
        if (( arg == "yezi" )||(arg == "ye"))
          {
	    if (!stone=present("shikuai",me))
	      return notify_fail( "你没有工具，怎么砸？\n");
	    else
	      {
		message_vision("$n把$N高高举起，狠狠地砸在椰子上，", stone,me);
		level=(int)me->query_skill("hammer",1);
		check = level*level*level;
		if (level > 20)
		  {
		    write ("只一下便砸开了！\n");
		  }
		else if (check > (int)me->query("combat_exp") * 10)
		  {       
		    write ("砸了半天终于砸开了！\n");
		  }
		else
		  {
		    write ("砸了半天终于砸开了，你从中学到了基本锤法的初级知识！\n");
		    me->improve_skill("hammer", me->query("int"));
		  }
		ke = new("/d/xiakedao/obj/yezike");
		ke->move(me);
		destruct(this_object());
		return 1;
	      }
          }
        else return 0;
}

int do_eat(string arg)
{ 
        object me = this_player();
        if ( !arg )
                return notify_fail( "你想吃什么？\n");
        if (( arg == "yezi" )||(arg == "ye"))
	  {
	    message_vision("$N一口咬在椰子壳上，差点把牙崩掉了，疼得叫了一声。\n", me);
	    return 1;
	  }
	else return 0;
}



