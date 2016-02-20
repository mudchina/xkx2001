//Cracked by Roath
// Room: /d/beijing/zijincheng/ciningmen.c

inherit ROOM;

void create()
{
	set("short", "慈宁门");
	set("long", @LONG
这是一扇朱漆大门，门口站着几个侍卫和太监。再往北走就是皇
太后的寝宫。任何人未得宣召，不得入内。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cininggong",
  "south" : __DIR__"cininghuayuan",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
