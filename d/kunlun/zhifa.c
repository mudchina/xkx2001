//Cracked by Roath
// Room: /d/mingjiao/zhifa.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "执法处");
	set("long", @LONG
此处乃明教执法之处。入口处摆有龙、狮、虎、豹、狗五尊青铜雕像。
明教教规极严，凡有违教规者必受重罚。大厅左侧旗架上插着光明圣火旗，
已示明教威严。正堂处有一红木方桌，上摆黄金铸造虎形符。右侧摆着一
大刑架，上置各种刑具。
LONG
	);
set("objects",([
		__DIR__"npc/lengqian" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"shijie77",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
