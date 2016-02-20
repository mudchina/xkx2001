//Cracked by Roath
// Room: /d/mingjiao/jneiting.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "内厅");
	set("long", @LONG
但见四壁挂着十几柄兵器，除两三把古色刀剑外，其他皆是些古怪的
奇门武器，闪着寒光，经灯光一照，更显明亮。室中有一方桌，围聚四条
长凳。左侧为床，右边是长案，案上有几件古玩，亦都是青铜，金铁之类。
LONG
	);
			set("objects",([
		__DIR__"npc/zhuangzheng" : 1,
]));

	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"shanlu28",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
