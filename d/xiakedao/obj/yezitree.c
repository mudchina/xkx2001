//Cracked by Roath
// yezitree.c
// By ssy

#include <ansi.h>

inherit ITEM;
void reset_count();
int t0;

void create()
{
	set_name("椰子树",({"yezi tree", "tree"}));
	set_weight(900000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一棵高高的椰子树，树顶好象还有几只椰子。\n");
		set("unit", "棵");
		set("value", 8);
		set("no_get", 1);
    	}
	t0 = uptime();
        set("yezicount",1);
}


void init()
{
        int t;
        t = uptime();
	if ((t-t0)>900)  // every 15 mins re-grow a yezi
	  {
	    t0=t;
	    set("yezicount",1);
	  }
	add_action("do_pa", "pa");
	add_action("do_pa", "climb");
}

int do_pa(string arg)
{
	object ye, me = this_player();
	int check;

	if( !arg || arg!="tree" && arg != "树" )
		return notify_fail("你要爬甚么？\n");
	
	if ((int)me->query("jingli") < 50)
                return notify_fail("你累得连站都站不起来了，怎麽爬树？\n");
        me->receive_damage("jingli", 20);
	message_vision(HIW"$N双手抱住树干，哼哧哼哧的爬了起来。\n"NOR,
		       me);
        if ((int)me->query_skill("dodge", 1) >= 10)
	  {
	    if (!(present("yezi", me)))
	      {
		if (query("yezicount")>0)
		  {
		    message_vision("$N爬上了树顶，摘了一只椰子。\n", me);
		    ye = new(__DIR__+ "yezi");
		    ye->move(me);
		    add("yezicount", -1);
		  }
		else
		  {
                    message_vision("$N爬上了树顶，发现椰子已经被人摘光了。\n", me);
		  }
	      }
	    else
	      {
                message_vision("$N爬上了树顶，想摘一只椰子，没想到手中已经拿了另一只，一个不留神，从树顶栽了下来！\n", me);
		if ((int)me->query("qi") > 30)
		  me->receive_damage("qi", 20);
		else me->receive_damage("jingli",40);
	      }
	    return 1;
	  }
        check = (int)me->query_skill("dodge",1)*
	  (int)me->query_skill("dodge",1)*
	  (int)me->query_skill("dodge",1);
        if (check > (int)me->query("combat_exp") * 10)
	  {       
	    write ("你实战经验不足，爬了半天全无长进。\n");
	    return 1;
	  }

	me->improve_skill("dodge", me->query("int"));
        return 1;
}

