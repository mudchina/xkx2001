//Cracked by Roath
// jiulao2.c 九老洞
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "九老洞");
        set("long", @LONG
这就是峨嵋第一大洞，洞内深窈无比，神秘难测。你一走进来，便发觉洞
中叉洞多如迷宫，怪异莫测，似乎黝黑无底。还是快快离开吧。
LONG
        );

        set("exits", ([
        "north" : __DIR__"jiulao3",
        "south" : __DIR__"jiulao3",
        "west" : __DIR__"jiulao3",
        "east" : __DIR__"jiulao3",
	"out" : __DIR__"jiulao1"
        ]));

        set("objects", ([
                __DIR__"npc/bat": 4]));

        set("no_clean_up", 0);

	set("cost", 4);
        setup();
	replace_program(ROOM);
}

