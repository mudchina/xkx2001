//Cracked by Roath
// Room: /d/beijing/east/liulichang.c

inherit ROOM;

void create()
{
	set("short", "琉璃厂");
	set("long", @LONG
琉璃厂路面不宽，铺子也不甚起眼，但却是京城最大的书市，
一块块金字招牌全是名士手笔；京城文人闲时常集于厂肆，挑选
合意古本典籍。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfudajie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
