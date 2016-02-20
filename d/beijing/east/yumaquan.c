//Cracked by Roath
// Room: /d/beijing/east/yumaquan.c

inherit ROOM;

void create()
{
	set("short", "御马圈");
	set("long", @LONG
这是当今天子钦点的御马圈，圈中所养之马均是千中挑、万
中选的良驹，匹匹都是龙背鸟颈、骨挺筋健、嘶吼若雷、奔驰如
风，非一般凡马可望其项背。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfudajie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
