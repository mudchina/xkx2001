//Cracked by Roath
// Room: /d/mingjiao/qingshilu1.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
小径以青石铺成，虽无人清扫，然山间多风，亦显干净。两边碧柏成
阴，翠松为林，树下长满各色野花，蝴蝶纷飞，林鸟时临。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shanlu7",
  "northwest" : __DIR__"qingyun",
  "southdown" : __DIR__"shanjiao1",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
