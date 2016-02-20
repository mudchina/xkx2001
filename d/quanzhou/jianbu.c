//Cracked by Roath
// Room: jianbu.c 剑部
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "剑部");
    set("long", @LONG
这是武馆的剑部，由刘虹瑛负责。到处摆着竹筒木人，可供练习。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zoulang2",
    ]));

    set("objects", ([
	__DIR__"npc/liuhongying" : 1,
    ]));		    	

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
