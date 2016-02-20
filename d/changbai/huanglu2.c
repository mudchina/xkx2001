//Cracked by Roath
// Room: huanglu2.c

inherit ROOM;

void create()
{
	set("short", "荒路");
	set("long", @LONG
这是城东的一条荒路，路旁杂乱的长着齐膝的荒草，远近荒无一人。两
旁干枯的老树上落满了成群的乌鸦，凄凉的鸣叫声在荒野上远远传去，一派
凄凉的景象。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"huanglu1",
                "northeast" : __DIR__"ssmiao",
	]));

        set("objects",([
          //      __DIR__"npc/teng" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

