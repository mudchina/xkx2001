//Cracked by Roath
// Room: /d/mingjiao/shanlu19.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
几只蜜蜂在匆匆得忙碌着，给这小小的山路增添了几分生机。清晨的
阳光撒来，草上的水珠散射出绚丽的生命。偶有一只野兔蹿过，在草上留
下淡淡的记痕。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"shanya21",
  "east" : __DIR__"shanlu20",
  "southdown" : __DIR__"yongdao2",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
