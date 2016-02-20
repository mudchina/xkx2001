//Cracked by Roath
// tumen.c 涂门集
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "涂门集");
	set("long", @LONG
这是泉州南面东西向的一条干道，规模不大。南边是泉州著名的鸿翔绸缎
庄。西边是个集市，东边便是去往港口的主要通道「涂门水关」。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"qingjing",
		"south" : __DIR__"jiedao1",
		"east" : __DIR__"shuiguan",
		"west" : __DIR__"jishi",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
