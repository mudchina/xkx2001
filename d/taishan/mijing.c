//Cracked by Roath
// mijing2.c 密径
// qfy July 10, 1996

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "密径");
        set("long", @LONG
一条窄长的密径穿插过巨石中央。头顶上光线从岩石的缝隙中投入，
是以四周不至于太暗。不知密径通往何处。
LONG
        );

	set("exits", ([
                "out" : __DIR__"shixin",
		"north" : __DIR__"dongqian",
        ]));

	set("cost", 2);
        setup();
}
