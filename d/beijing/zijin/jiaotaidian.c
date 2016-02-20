//Cracked by Roath
// Room: /d/beijing/zijincheng/jiaotaidian.c

inherit ROOM;

void create()
{
	set("short", "交泰殿");
	set("long", @LONG
这是皇后在元旦，千秋（皇后生日)等节日里受朝贺的地方。殿
里还陈设有古代计时用的铜壶滴漏和大自鸣钟，都有五米多高。这里
还是存放二十五宝的地方.二十五宝是皇帝行使各方面权力的宝玺.这
些宝玺由内阁掌握,宫殿监的监正管理.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"longfumen",
  "north" : __DIR__"kunninggong",
  "south" : __DIR__"qianqinggong",
  "east" : __DIR__"jinghemen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
