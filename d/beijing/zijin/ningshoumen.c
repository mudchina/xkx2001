//Cracked by Roath
// Room: /d/beijing/zijincheng/ningshoumen.c

inherit ROOM;

void create()
{
	set("short", "宁寿门");
	set("long", @LONG
你面前是一道影壁(wall)，影壁后就是宁寿宫宫门了。宁寿
宫建于乾隆三十六年至四十一年，仿大内中轴线，前三殿，后三
宫的体制，是紫禁城中最气魄雄伟的宫殿。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"guang4",
  "north" : __DIR__"huangjidian",
  "northwest" : __DIR__"gzxd5",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "wall" : "“九龙壁”上面雕刻着九条盘旋飞舞的巨龙。\n",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
