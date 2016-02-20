//Cracked by Roath
// hz_xilang1.c 华藏庵西廊
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "华藏庵西廊");
	set("long", @LONG
这里是峨嵋华藏庵西廊。走廊往南通往禅房，东边通往广场。
LONG
	);
	set("exits", ([
		"south" : __DIR__"hz_xilang2",
		"east" : __DIR__"hz_guangchang",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

