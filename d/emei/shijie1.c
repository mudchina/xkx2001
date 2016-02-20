//Cracked by Roath
// shijie1.c 青石阶
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "青石阶");
        set("long", @LONG
已经是峨嵋山脚下了。南面一条通往峨嵋的青石阶，两旁绿树荫蔽，空气
十分清新。西南方通向南诏的大理国。西边好象有人搭了个小草棚。
LONG
        );
        set("exits", ([
		"southup" : __DIR__"baoguomen",
                "northeast" : __DIR__"shijie2",
		"west" : __DIR__"shack",
		"southwest" : "/d/dali/guandao6",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 2);
        setup();
//	replace_program(ROOM);
}

