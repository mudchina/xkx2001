//Cracked by Roath
// Room: /city/ximen.c
// YZC 1995/12/04 

#include <ansi.h>;
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西门");
	set("long",
"这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城门正上方
勉勉强强可以认出“"+YEL"西门"NOR+"”两个大字，城墙上贴着几张"+HIW"通缉告示"NOR+"(gaoshi)。这里
是罪犯逃往西域的必经之地，官兵们戒备森严，动不动就截住行人盘问。一条笔
直的青石板大道向东西两边延伸。西边是郊外，骑马的、座轿的、走路的，行人
匆匆。你加快了脚步，生怕官兵找碴。东边是城里。\n"
	);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : __DIR__"xidajie3",
  		"west" : "/d/xingxiu/xxroad1",
		"north" : __DIR__"xijiao1",
		"south" : __DIR__"xijiao3",
	]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
               "/clone/npc/murong" : 1,
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
        if (dir =="east" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("官兵手中的刀挡住了你的去路。\n");
        return ::valid_leave(me, dir);
}
