//Cracked by Roath
// yanting.c
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "大厅");
        set("long", @LONG
这里是晋阳大侠萧半和家的大厅。今天是萧半和的五十寿诞。
萧府中贺客盈门，群英济济。萧半和在大厅上接待来贺的各路
英雄。
LONG
        );

        set("objects", ([
	    __DIR__"npc/banhe" : 1,
	]));

        set("exits", ([
                "west" : __DIR__"yanting",
		"out" : __DIR__"gate",
		"north" : __DIR__"huayuan",
        ]));

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{     
    if ( (dir=="out") && present("xiao banhe",environment(me)) &&
                (present("yuan dao", me) || present("yang dao", me))) {
       message_vision("萧半和一把揪住$N：你杀我儿女休得溜掉！\n",
                me);
       return notify_fail("\n");
    }
    else
        return :: valid_leave(me,dir);
}

