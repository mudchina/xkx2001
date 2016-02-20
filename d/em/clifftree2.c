//Cracked by Roath
// d/emei/clifftree2.c 舍身崖下万年松
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "万年松");
	set("long", @LONG
这是一只大树枝，从一棵万年松上伸出。这棵树生得高大苍劲，年代古远，
树根由石缝中长出，紧紧攀着崖壁。上边就是舍身崖了。
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
            "up"        :
"上面离崖顶太远了，叫救命大概不会有人听见了，爬也不知能否爬得上去。\n",
	    "down"	:
"下面是万丈深渊，你大难不死，还想再跳吗？\n",
	    "tree"	:
"大树树根由石缝中长出，紧紧攀着崖壁。\n",
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

	if ( arg && arg != "down" && arg != "up" && arg != "tree")
		return notify_fail("从这里不能朝那个方向爬。\n");

	if ( arg == "down" ){
                message_vision("$N向崖下爬去，忽然一个失手，直摔了下去。。\n", me);
		call_out("to_pool", 1, me);
	        return 1;
	}

	if ( arg == "up" ) {
		message_vision("$N想向上爬，可是没爬上去，又掉下来了。\n", me);
		me->add("jingli",-random(20));
		return 1;
	}

	if (arg == "tree" ) {
		message_vision("$N顺着树干慢慢爬下去。\n", me);
		me->move(__DIR__"clifftree3");
		message_vision("$N顺着树干爬了下来。\n", me);
		me->add("jingli", -random(10));
		return 1;
	}

	return 0;
}

#include "/d/emei/cliff.h"
