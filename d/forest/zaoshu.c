//Cracked by Roath
// Jay 7/11/96
inherit ROOM;


void create()
{
    int i;
        set("short", "枣树上");
        set("long", @LONG
枣树上到处都是成熟的枣子，散发出诱人的香味。
LONG
        );

        set("exits", ([
                "down" : __DIR__"mty1",
        ]));
        set("objects", ([
                __DIR__"npc/obj/zao" : 4,
        ]));

	set("cost", 3);
	set("outdoors", "city");
        setup();
        replace_program(ROOM);
}


