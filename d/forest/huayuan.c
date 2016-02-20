//Cracked by Roath
// yanting.c
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "花园");
        set("long", @LONG
这里是晋阳大侠萧半和家的後花园。园内奇花异葩遍布。东面就是
萧家小姐的闺房。南边是大厅。
LONG
        );

        set("objects", ([
	    __DIR__"npc/ren" : 1,
	    __DIR__"npc/lin" : 1,
	    "/d/wudang/npc/bee" : 1,
	]));

        set("exits", ([
                "south" : __DIR__"dating",
		"east": __DIR__"guifang",
        ]));
	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

