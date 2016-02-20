//Cracked by Roath
// d/emei/obj/flower.c
// xbc 1997/02/03

#include "ansi.h"
inherit ITEM;

string* titles = ({
        "木槿花",
        "竹叶花",
        "紫荆花",
        "芙蓉花",
        "木莲花",
        "蕙兰花",
	"白合花",
	"莎椤花",
});

void create()
{
	int i;
	i = random(sizeof(titles));
	if (i<2)
        set_name(HIC+titles[i]+NOR, ({ "flower", "hua" }));
	else if (i<4)
	set_name(MAG+titles[i]+NOR, ({ "flower", "hua" }));
        else if (i<6)
        set_name(HIR+titles[i]+NOR, ({ "flower", "hua" }));
	else
        set_name(HIM+titles[i]+NOR, ({ "flower", "hua" }));

        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵美丽的小野花，香气清新。\n");
                set("value", 0);
        }
}


void init()
{
        add_action("do_smell","smell");
        add_action("do_dai","dai");
}

int do_smell(string arg)
{
        object me = this_player();
        object flower = present("flower", me);

        if ( !arg|| arg != "flower" ) 
           return notify_fail("你要闻什么？\n");

        message_vision("$N拿起" + (string)flower->query("name") +"，放在鼻端深深地一闻。\n", me);
        return 1;
}

int do_dai(string arg)
{
        object weapon, flower, target, me = this_player();
	string arg1, arg2;
	int argc;

	if ( !arg ) return notify_fail("你要戴什么？\n");

	if ( (argc = sscanf(arg, "%s %s", arg1, arg2)) != 2) {
		argc = 1;
		arg1 = arg;
	}

	if ((argc == 1 && arg1 != "flower"))
	        return notify_fail("你要戴什么？\n");

	if (argc == 1) {
		if ( arg1 != "flower" )
			return notify_fail("你要戴什么？\n");

		if ( !(weapon = present( "flower", me)) ) 
                        return notify_fail("你没有花可以戴。\n");

	        if ( me->query("gender") == "女性" ) {
        	    	message_vision("$N将" + (string)weapon->query("name") +"插在发际，好个美貌娇娘。\n", me);
        	}
        	else {
           		message_vision("$N将" + (string)weapon->query("name") +"别在胸前，好个风流儿郎。\n", me);
        	}
		target = me;
	}
	else if (argc == 2) {
		if ( !(target = present(arg1, environment(me)))
		     || !target->is_character() )
			return notify_fail("这里没有这个人。\n");

		if ( !userp(target) || target==me) 
			return notify_fail("找个玩家献殷勤吧。\n");

		if ( arg2 != "flower" ) 
			return notify_fail("你想给" + target->name() + "戴什么？\n");

		if ( !(weapon = present( "flower", me)) ) 
			return notify_fail("你没有" + (string)weapon->query("name") +"可以戴。\n");

		if ( target->query("gender") == "女性" ) {
			printf("你将" + (string)weapon->query("name") +"插在%s的发际，好个美貌娇娘。\n", 
				target->name());
           		message("vision", 
			     sprintf("%s将" + (string)weapon->query("name") +"插在你的发际，好个美貌娇娘。\n",
				  me->name()), target);
			message("vision", 
			     sprintf("%s将" + (string)weapon->query("name") +"插在%s的发际，好个美貌娇娘。\n",  
				  me->name(), target->name()), environment(me), ({me, target}) );
        	}
        	else {
			printf("你将" + (string)weapon->query("name") +"别在%s的胸前，嘻嘻嘻。\n", 
				target->name());
           		message("vision",
			     sprintf("%s将" + (string)weapon->query("name") +"别在你的胸前，好个风流儿郎。\n",
			        me->name()), target);
			message("vision", sprintf("%s将" + (string)weapon->query("name") +"花别在%s胸前，好个风流儿郎。\n", 
				me->name(), target->name()), environment(me), ({me, target}) );
        	}
	}

        weapon->move(target);
	
	return 1;
}        

