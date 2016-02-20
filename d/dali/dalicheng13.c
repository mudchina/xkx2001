//Cracked by Roath
// Room: /d/dali/dalicheng13.c

inherit ROOM;

void create()
{
	set("short", "大和街");
	set("long", @LONG
这是一条青石板路，两边种了不少柏树，显得庄严肃穆。南面是大理城的守
军驻地，隐隐可以听到兵士们操练的号子声，向北是土司府，是当今皇太妃刀氏
一族的世袭衙门。
LONG);
	set("exits", ([
		"north" : __DIR__"tusi1",
		"south" : __DIR__"dalicheng14",
		"east" : __DIR__"dalicheng12",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
