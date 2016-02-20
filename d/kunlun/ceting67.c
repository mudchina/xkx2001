//Cracked by Roath
// Room: /d/mingjiao/ceting67.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "侧厅");
	set("long", @LONG
一入此厅，心中即感逸然。环目于前，厅壁并非太素，亦非太华。名
人尺幅，自是不少，然浓淡得宜，错综有致。室间设大屏风，上多花鸟，
屏前设坐榻，旁几陈琴棋，置瓶花，格调清雅，极富情趣。南墙挂一山水
中堂，有联称装左右：案前看鹤浴，棂下见鱼游，横幅(hengfu)又题：会
心山水，故此厅又名会心厅。
LONG
);
	set("item_desc",([
		"hengfu" : "横幅上有一排小字 ：杨逍题 \n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shting",
  "north" : __DIR__"jiuqu",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
