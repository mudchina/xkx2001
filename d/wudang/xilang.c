//Cracked by Roath
// xilang.c 西厢走廊
// by Xiang

inherit ROOM;

void create()
{
	set("short", "西厢走廊");
	set("long", @LONG
	你走在一条走廊上，东边是大殿，北边是一座楼阁。
LONG
	);

	set("exits", ([
		"northup" : __DIR__"cangjingge",
		"east" : __DIR__"sanqingdian",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

