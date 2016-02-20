//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "小山洞");
        set("long", @LONG
一个小山洞里光线昏暗。洞内有些杂物放置得整整齐齐，但都
积满了尘土。
LONG
        );
        set("exits", ([
		"out" : __DIR__"hill",
	]));

	set("objects", ([
		__DIR__"obj/tangshi" : 1,
	]));
	set("cost",1);
	setup();
        replace_program(ROOM);
}
