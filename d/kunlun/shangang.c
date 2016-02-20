//Cracked by Roath
// Room: /d/mingjiao/shangang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山岗");
	set("long", @LONG
地上长满了嫩草，不远处有一群山羊正在吃草。北面有一凸峰，因山
石本为赤色，日暮时分，特别醒目。山樵们称其为神火峰。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"tianmoling",
  "southwest" : __DIR__"shanya21",
  "northup"	: __DIR__"shenhuo",	
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
