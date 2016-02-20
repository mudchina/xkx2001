//Cracked by Roath

// kane: 98/3/025

inherit ROOM;

void create()
{
        set("short", "冰火岛");
        set("long", @LONG
这是岛屿东部的一个大平原，远处高山玄冰白雪，平野上却极目青绿，苍
松翠柏，高大异常，更有诸般奇花异树，皆为中土所无。平野上一群梅花鹿正
幽闲的吃草，毫不惧人。
LONG
        );
        set("exits", ([
                "west" : __DIR__"icefire1",
        ]));

        set("objects", ([
                "/d/changbai/npc/deer": 3,
	]) );

	set("outdoors", "island");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

