//Cracked by Roath
// Room: /d/beijing/tianqiao.c

#include "beijing_defs.h"
inherit ROOM;

void create()
{
	set("short", "天桥");
	set("long", @LONG
这里是北京城最繁华热闹的地方，龙蛇混杂，三教九流无所不包；在这里跑
江湖卖解的，说书唱曲的，百货小吃，无所不有，不过这里藏龙卧虎，其中也不
乏深藏不露的隐士高人。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
        	"south" : __DIR__"kedian",
		"north" : __DIR__"quanjude",
		"west" : __DIR__"caishikou",
		"east" : __DIR__"zhengyangdajie",
		"northwest": __DIR__"chouzhuang",
		"northeast": __DIR__"zhubaodian",
                "southwest": __DIR__"majiu",
                "southeast": __DIR__"chaguan",
	]));
	
 	set("objects", ([
	__DIR__"npc/funseller.c": 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 4);
	setup();
}

void init()
{
    if (random(8) == 1) 
	HELPER->clonehere_with_limit(this_object(), "/d/beijing/npc/randomnpc", 8);
}

