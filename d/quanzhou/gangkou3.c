//Cracked by Roath
// gangkou1.c 港口路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "港口路");
	set("long", @LONG
这是用大块花岗石铺成的宽敞大道，平坦结实。路上马车都拉着沉重的货
物南来北往。不少马队都有镖师保护，看来都是价值不菲的货物。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"lingmu",
		"south" : __DIR__"gangkou4",
	]));

        set("objects", ([ 
		__DIR__"npc/biaotou" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
