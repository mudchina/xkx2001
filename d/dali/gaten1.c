//Cracked by Roath
// Room: /d/dali/gaten1.c

inherit ROOM;

void create()
{
	set("short", "大理城北");
	set("long", @LONG
这里是个岔路口。南边就是大理城的北门了，道路从这里分岔，北去可到太
和城，西北通向下关城，也通苍山，是去游苍山和崇圣寺的必经之路。
LONG);
	set("exits", ([
		"northwest" : __DIR__"esqiao",
		"north" : __DIR__"taihec",
		"south" : __DIR__"northgate",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
