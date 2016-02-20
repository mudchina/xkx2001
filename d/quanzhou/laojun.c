//Cracked by Roath
// laojun.c 老君岩
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "老君岩");
	set("long", @LONG
这里山不高而云雾缭绕，周围开旷辽阔，碧草如茵，风景宜人。因有道教
教主老君石像，故称老君岩。它是一天然巨石雕琢而成。石像左手依膝，右手
凭几，两眼平视，双耳垂肩，脸含笑容，苍髯飞动，一幅老人慈祥，安乐的神
态。民俗云：「摸到老君鼻，吃到一百二」。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"eastup" : __DIR__"nantai",
		"southdown" : __DIR__"qianshou",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 5);
        setup();
}

void init()
{
	add_action("do_touch", "touch");
	add_action("do_touch", "mo");
}

int do_touch(string arg)
{
	object me = this_player();
	int karma;

	if ( !arg || arg == "" ) return 0;

	if ( arg == "nose" || arg == "bi" ) {
		if ( me->query_temp("marks/laojun") ) {
			write("你还没摸够吗？\n");
			return 1;
		}

		message_vision("$N蹬高脚尖，笑嘻嘻地伸出手去摸了摸老君像的鼻子。\n", me);

		karma = random(40 - me->query("kar"));
		if ( karma < 0 ) karma = 0;
		me->set_temp("apply/karma", karma);
		me->set_temp("marks/laojun", 1);
		return 1;
	}

	return 0;
}
