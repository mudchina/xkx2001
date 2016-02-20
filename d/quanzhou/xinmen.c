//Cracked by Roath
// xinmen.c 新门集
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "新门集");
	set("long", @LONG
这是泉州南面东西向的一条干道，规模不大。南边有家茶居，西边是新门
吊桥，东边则是市集。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"xmqiao",
		"east" : __DIR__"jishi",
		"south" : __DIR__"taoran",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
