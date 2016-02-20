//Cracked by Roath
// Room: jianbu.c 棒杖部
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "棒杖部");
    set("long", @LONG
这是武馆的棒杖部，由陈浒负责。到处摆着木人沙包，可供练习。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zoulang1",
    ]));

    set("objects", ([
	__DIR__"npc/chenhu" : 1,
    ]));		    	

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
