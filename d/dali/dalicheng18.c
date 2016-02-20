//Cracked by Roath
// Room: /d/dali/dalicheng18.c

inherit ROOM;

void create()
{
	set("short", "摆夷民居");
	set("long", @LONG
摆夷是大理第一大族，大多散布在苍山洱海附近。摆夷民居是以石块垒成，
别局风格。朝花节那天，家家户户都把盆栽花木摆在门口，摆搭成一座座的“花
山”，招引四野乡村的人来观花街。
LONG);
	set("objects", ([
		__DIR__"npc/oldman" : 1,
		__DIR__"npc/miaonu2" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"dalicheng16",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
