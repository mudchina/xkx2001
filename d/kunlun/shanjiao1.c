//Cracked by Roath
// Room: /d/mingjiao/shanjiao1.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "小山脚");
	set("long", @LONG
遍地红花绿草，不远处是一松林。静心细听，似有哗哗水声，但又不
真切。两只山雀飞过，给这幽静之处留下了一段清音。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"shanquan",
  "northup" : __DIR__"qingshilu1",
  "southeast" : __DIR__"songlin1",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
