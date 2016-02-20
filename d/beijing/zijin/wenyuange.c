//Cracked by Roath
// Room: /d/beijing/zijincheng/wenyuange.c

inherit ROOM;

void create()
{
	set("short", "文渊阁");
	set("long", @LONG
是专为收藏乾隆年间编纂的共79000多卷的《四库全书》而修建的,
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhujingdian",
  "north" : __DIR__"gzxd4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
