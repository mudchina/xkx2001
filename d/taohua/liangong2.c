//Cracked by Roath
//Kane
// modified by sdong to anti-robot, 7/12/1999
//增加(discuss <对象> <次数> )功能 by maco 9/2/1999

inherit ROOM;

#include "discuss.h"
#include <ansi.h>

//int in_ask, answer;
//int bCheckingRobot;
//object partner;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这是桃花岛弟子的练功房。屋子东半部散放着几个蒲团，供诸弟子打坐吐纳，调
气养息，修练内功之用。西半部地上则绘着伏羲六十四卦的方位卦象，大概是修习奇
门遁甲所用。书架上有一些经书。
LONG
	);
	 set("exits", ([
		"west" : __DIR__"changlang",
	]));

	 set("objects", ([
		__DIR__"obj/tiexiao" : 1,
		__DIR__"obj/zhuxiao" : 1,
		__DIR__"obj/yijing3" : 1,
		__DIR__"obj/bagua" : 1,
	]));

	set("no_fight", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_discuss", "discuss");
	add_action("do_answer", "answer");
	add_action("do_answer", "da");
}
