//Cracked by Roath
// anhai.c 安海港
// qfy Nov 3, 1996
// modified by aln 4 / 98

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "安海港");
	set("long", @LONG
安海港是泉州三大港口之一。这里港阔水深，风平浪静。极目远眺，海天
一色，蔚蓝无暇。岸边停靠着密密麻麻的各种船只。东边有座姑嫂塔。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"gushao",
		"north" : __DIR__"gangkou2",
	]));

        set("objects", ([ 
		__DIR__"npc/kuli" : 1,
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/langren" : 2,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

        set("navigate/locx", 0);
        set("navigate/locy", -300);

	set("cost", 1);
        setup();
}
