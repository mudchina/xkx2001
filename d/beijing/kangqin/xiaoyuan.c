//Cracked by Roath
// Room: /d/beijing/kangqin/xiaoyuan.c

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这是一个僻静的小院子，中间种着一棵老槐树，树下有一口井。
周围都是平房，不时传来吆喝之声。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiangfang3",
  "west" : __DIR__"xiangfang2",
  "north" : __DIR__"xiangfang1",
  "east" : __DIR__"zhoulang8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
