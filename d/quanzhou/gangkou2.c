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
物南来北往。不少马队都有镖师保护，看来都是价值不菲的货物。南边是安海
港，东边是船坞，东南边则是永宁港。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"gangkou1",
		"southeast" : __DIR__"yongning",
		"south" : __DIR__"anhai",
		"east" : __DIR__"chuanwu",
	]));

        set("objects", ([ 
		__DIR__"npc/biaotou" : 2,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
