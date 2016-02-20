//Cracked by Roath
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "泥潭小屋");
	set("long", @LONG
墙里是个院子，分为两半，左一半是实土，右一半却是水塘。内堂前是个月
洞，仍无门扉。只见当前摆了一张长桌，上面放了七盏油灯，排成天罡北斗之形。
地下乱七八糟地摆了一根根的无数竹片，那些竹片都是长约四寸，阔约二分，似
乎是计数用的算子。
LONG);
	set("objects", ([
		__DIR__"npc/yinggu" : 1,
		]) );
	set("exits", ([
		"out" : __DIR__"maze2",
        ]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}
