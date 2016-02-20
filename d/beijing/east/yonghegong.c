//Cracked by Roath
// Room: /d/beijing/east/yonghegong.c

inherit ROOM;

void create()
{
	set("short", "雍和宫");
	set("long", @LONG
雍和宫是北京城里最大的喇嘛庙，是清廷管理全国喇嘛教
事务的中心。雍和宫集汉、满、蒙、藏各族建筑艺术于一体，
藏有不少艺术价值极高的工艺品；并于每年五月初八，雍和宫
都要排演“打鬼”来驱崇迎祥。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  	"west" : __DIR__"guozijianjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
