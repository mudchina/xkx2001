//Cracked by Roath
// xilang2.c 西厢走廊
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "西厢走廊");
	set("long", @LONG
你走在一条幽静的走廊上，北面是一座阁楼，往南是武当弟子的练功房
所在，不时传出弟子们练功的声音。
LONG
	);

	set("exits", ([
		"northup" : __DIR__"cangjingge",
		"east" : __DIR__"xilang1",
		"south" : __DIR__"liangongfang2",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

