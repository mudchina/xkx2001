//Cracked by Roath
// d/emei/clifftree3.c 万年松树下
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "万年松下");
	set("long", @LONG
你已经到了万年松树下。这棵松树年代古远，树根由石缝中长出，紧紧攀
着崖壁。
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
            "up"        :
"上面离崖顶太远了，大概是爬不上去了。\n",
	    "down"	:
"下面是万丈深渊。\n",
	    "cliff"	:
"崖壁似乎被人用刀削过一样平。崖壁左面突起一块，不知后面是否有什么支撑
可以爬出去。\n",
	    "left"	:
"崖壁似乎被人用刀削过一样平。崖壁左面突起一块，不知后面是否有什么支撑
可以爬出去。\n"
        ]));

	set("cost", 0);
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

	if ( arg && arg != "down" && arg != "up" && arg != "left")
		return notify_fail("什么？\n");

	if ( arg == "down" ){
		call_out("to_pool", 1, me);
                message_vision("$N向崖下爬去，忽然一个失手，直摔了下去。。\n", me);
	        return 1;
	}

	if ( arg == "up" ) {
		message_vision("$N顺着树干慢慢爬上去。\n", me);
		me->move(__DIR__"clifftree2");
		message_vision("$N顺着树干爬了上来。\n", me);
		me->add("jingli",-random(20));
		return 1;
	}

	if (arg == "left" ) {
		message_vision("$N扒着崖壁向左边爬去。\n", me);
		me->move(__DIR__"cliffpath1");
		message_vision("$N扒着崖壁从右边爬了过来。\n", me);
		me->add("jingli", -random(10));
		return 1;
	}

	return 0;
}

#include "/d/emei/cliff.h"
