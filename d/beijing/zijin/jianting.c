//Cracked by Roath
// Room: /d/beijing/zijincheng/jianting.c

inherit ROOM;

void create()
{
	set("short", "箭亭");
	set("long", @LONG
整个建筑没有一扇窗户,南北向共有三十二扇隔扇门,周围是空
旷的广场,便于练习可跑马射箭.清代武士殿试,皇帝在此阅技勇.亭
内东西各陈放着乾隆.嘉靖圣训石碑,训喻子孙居安思危,务忘骑射.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"guang4",
  "south" : __DIR__"gzxd3",
  "east" : __DIR__"yuchashanfang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
