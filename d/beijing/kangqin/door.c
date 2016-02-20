//Cracked by Roath
// Room: /d/beijing/kangqin/door.c

inherit ROOM;

void create()
{
	set("short", "王府大门");
	set("long", @LONG
你正站在一座豪华的府门前，门前有两只极大的石狮子，门
上高悬一块横匾，上书「康亲王府」四个金字。门口站着两排侍卫，
身着锦衣，手执钢刀，气宇轩昂。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tingyuan",
  "north" : "/d/beijing/west/lingjing",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
