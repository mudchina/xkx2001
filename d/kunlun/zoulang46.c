//Cracked by Roath
// Room: /d/mingjiao/zoulang46.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条昏暗寂静的走廊，彩梁画栋，连顶棚也用彩漆绘满了各种飞
天的图形。走廊西南两侧均与教众寝室相连。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nanxiu",
  "south" : __DIR__"nvxiu",
  "east" : __DIR__"qiankun",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
