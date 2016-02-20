//Cracked by Roath
// Room: /d/mingjiao/ldating.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "烈火旗大厅");
	set("long", @LONG
踏入此厅，便觉一阵眩晕。大厅四角各有一大火炉，青蓝色的火苗狂
欢般跳跃。左右站有两排斥肩光背的大汉，脸上没有一丝痛苦，仿佛以经
习惯了这种没有暖意的火浪。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"shanlu76",
  "east" : __DIR__"shanlu33",
]));
	set("objects",([
		__DIR__"npc/xinran" : 1,
	]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
