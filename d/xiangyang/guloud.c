//Cracked by Roath
// Room: /d/xiangyang/guloud.c

inherit ROOM;

void create()
{
	set("short", "鼓楼底层");
	set("long", @LONG
你处在鼓楼的底层，一缕缕阳光从墙上的花砖缝隙里透射进来。右侧有条挤
仄的长木梯架在墙边。墙角、梯级都堆满了灰尘。楼层上铺设了结实的木楼板，
墙砖也是颇为厚实。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"gulou",
  "westdown" : __DIR__"xiaoshi",
]));

	setup();
	replace_program(ROOM);
}
