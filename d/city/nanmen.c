//Cracked by Roath
// Room: /city/nanmen.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "南门");
	set("long",
"这是南门。城墙被当成了广告牌，贴满了花花绿绿各行各业的广告，官府的
"+HIW"告示"NOR+"(gaoshi)因此不太显眼。官兵们被近处的欢声笑语所吸引，似乎不是很认真
在执勤。一条笔直的青石板大道向南北两边延伸。\n"
	);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south" : __DIR__"wdroad1",
		"north" : __DIR__"nandajie3",
		"east" : __DIR__"nanjiao1",
		"west" : __DIR__"nanjiao3",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));

	set("cost", 1);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n浙江提督\n李克秀\n";
}

int valid_leave(object me, string dir)
{
        if (dir =="north" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("官兵手中的刀挡住了你的去路。\n");
        return ::valid_leave(me, dir);
}
