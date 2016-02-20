//Cracked by Roath
// yongning.c 永宁港
// qfy Nov 3, 1996
// modified by aln

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "永宁港");
	set("long", @LONG
永宁港是泉州三大港口之一。这里港阔水深，风平浪静。极目远眺，海天
一色，蔚蓝无暇。岸边停靠着密密麻麻的各种船只。南边的姑嫂塔流传着一个
感人的故事。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"gushao",
		"northwest" : __DIR__"gangkou2",
	]));

        set("objects", ([ 
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/kuli" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

        set("navigate/locx", 0);
        set("navigate/locy", -280);

	set("cost", 1);
        setup();
}
