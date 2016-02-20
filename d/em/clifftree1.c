//Cracked by Roath
// d/emei/clifftree1.c 舍身崖下罗汉松
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "罗汉松");
	set("long", @LONG
这是一只大树枝，由一棵罗汉松伸出来。这棵罗汉松样子象杉树，叶子圆
而细。你抬头望去，上面离舍身崖顶不远，下面却是万丈深渊。
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
            "up"        :
"上面好象离崖顶不远，不知有没有人能从上面把你拉上去呢？\n",
	    "down"	:
"下面是万丈深渊，你大难不死，还想再跳吗？\n"
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
		message_vision("$N纵身跳了下去。\n", me);
                if (me->query("kar") > 15+random(15) 
		&& me->query_str() > 28 && me->query("dex") < 17
		&& me->query("con") > 18 && me->query("int") < 25) {
//require a low int here. 傻人有傻福。
			call_out("to_branch2", 1, me);
	                return 1;
                }
                else {
			call_out("to_pool", 1, me);
       		        return 1;
		}
		return 0;
	}
	return 0;
}

int do_climb(string arg)
{
	object me = this_player();
	int k;

	if ( arg && arg != "down" && arg != "up")
		return notify_fail("什么？\n");

	if ( arg == "down" ){
		message_vision("$N向下爬，忽然一个失手，直摔了下去。\n", me);
		call_out("to_pool", 1, me);
	        return 1;
	}

	k = (int)me->query_str()+(int)me->query_dex();

	if ( arg == "up" ) {
		if (( random(k) > 40) && (me->query("jingli") > 60)) {
			message_vision("$N小心地向上爬去。\n", me);
			me->move(__DIR__"duguang2");
			message_vision("$N小心翼翼地从崖下爬上来。\n", me);
			me->add("jingli",-random(60));
			return 1;
		}
		else {
			message_vision("$N想向上爬，可是没爬上去，又掉下来了。\n", me);
			me->add("jingli",-random(10));
			return 1;
		}
	}
	return 0;
}

#include "/d/emei/cliff.h"
