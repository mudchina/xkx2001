//Cracked by Roath
// Room: daobu.c 刀刃部
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "刀刃部");
    set("long", @LONG
这是武馆的刀刃部，由龙铨负责。四周都是木片木人，可供练习。
LONG
    );

    set("exits", ([
	"south" : __DIR__"zoulang1",
    ]));

    set("objects", ([
	__DIR__"npc/longquan" : 1,
    ]));		    	

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
