//Cracked by Roath
// Room: jianbu.c 暗器部
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "暗器部");
    set("long", @LONG
这是武馆的暗器部，由萧飞负责。到处摆着草人靶子，可供练习。
LONG
    );

    set("exits", ([
	"south" : __DIR__"zoulang2",
    ]));

    set("objects", ([
	__DIR__"npc/xiaofei" : 1,
    ]));		    	

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
