//Cracked by Roath
// jiedao1.c 街道
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "街道");
	set("long", @LONG
这是泉州南面东西向的一条干道，规模不大。南去可达海外交通使节府，
东面是一所绸缎庄。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"silkshop",
		"south" : __DIR__"jiedao2",
		"north" : __DIR__"tumen",
	]));

	set("objects", ([ 
                __DIR__"npc/liumangtou" : 1,
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
