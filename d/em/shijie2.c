//Cracked by Roath
// shijie2.c 青石阶
// Shan: 96/06/23

inherit ROOM;

void create()
{
        set("short", "青石阶");
        set("long", @LONG
快到峨嵋山了。这是一条通往峨嵋山的青石阶，两旁绿树荫蔽，空气十分
清新。时常能见到些游人香客。
LONG
        );
        set("exits", ([
		"southwest" : __DIR__"shijie1",
                "north" : __DIR__"emroad1",
        ]));

        set("objects", ([
                __DIR__"npc/woman": 1,
		__DIR__"npc/puren": 1,
	]) );

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

