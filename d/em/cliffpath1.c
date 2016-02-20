//Cracked by Roath
// d/emei/cliffpath1.c 崖壁
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "崖壁");
	set("long", @LONG
崖壁这边不那么光秃秃的，有许多立足之处，石缝间长着小花小草。
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
	    "down"	:
"下面是万丈深渊。\n",
		"cliff"	:
"崖壁东边有个大石缝，向下伸去。\n",
        ]));

	set("cost", 10);
	setup();

}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( arg == "down" ) {
                message_vision("$N纵身向下跳去。\n", me);
		call_out("to_pool", 1, me);
                return 1;
	}
	return 0;
}

int do_climb(string arg)
{
	object me = this_player();
	int k;

	if ( arg && arg != "down" && arg != "right")
		return notify_fail("从这里不能朝那个方向爬。\n");

	if ( arg == "down" ){
		k = (int)me->query_dex() + (int)me->query_kar();
		if ( random(k) < 20 ) {
                	message_vision("$N向崖下爬去，忽然一个失手，直摔了下去。。\n", me);
			call_out("to_pool", 1, me);
	        	return 1;
		}
		else {
			message_vision("$N扒着崖壁向下边爬去。\n", me);
			me->move(__DIR__"cliffpath2");
	                message_vision("$N扒着悬崖从爬下来。\n", me);
			me->add("jingli",-random(20));
			return 1;
		}
	return 0;
	}

	if (arg == "right" ) {
		message_vision("$N扒着崖壁向右边爬去。\n", me);
		me->move(__DIR__"clifftree3");
		message_vision("$N扒着崖壁从左边爬过来。\n", me);
		me->add("jingli", -random(10));
		return 1;
	}

	return 0;
}

#include "/d/emei/cliff.h"

