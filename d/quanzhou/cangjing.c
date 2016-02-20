//Cracked by Roath
// cangjing.c 藏经阁
// qfy Nov 3, 1996

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "藏经阁");
	set("long", @LONG
藏经阁是开元寺的最高处，建在一个小山坡上。阁分两层，阁下有一小门
紧闭。登阁凭栏，看双塔凌空，点坛俯地，饶富诗意。阁上藏经近万卷。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"southdown" : __DIR__"ganlu",
		"northdown" : __DIR__"houshan",
	]));

        set("objects", ([ 
		__DIR__"npc/monk" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
