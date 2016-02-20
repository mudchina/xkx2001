//Cracked by Roath
// shisun.c 石笋
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石笋");
	set("long", @LONG
这是泉州西面的一处地貌奇观，经千年风蚀形成的石笋千奇百怪，似剑、
似刀、似锥，形态各异。洞壑纵横，不知所终。南面的山谷中有一所草庵。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"luanshi",
		"south" : __DIR__"caoan1",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
