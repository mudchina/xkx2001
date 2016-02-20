//Cracked by Roath
// Room: /d/shaolin/nanyang.c

inherit ROOM;

void create()
{
	set("short", "南阳城");
	set("long", @LONG
这里便是当年诸葛先生的故居。南阳城不大，因为地出要冲，
南来北往的客人特别多，所以也五脏俱全，酒楼，客栈，马店，
满城子都是。本地人口甚少，到处都是行色匆匆的江湖客人。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiao-fan" : 1,
]));
	set("cost", 1);
	set("outdoors", "shaolin");
	set("exits", ([ /* sizeof() == 6 */
  "southeast" : __DIR__"majiu",
  "west" : __DIR__"jiulou1",
  "north" : __DIR__"yidao3",
  "south" : __DIR__"hanshui2",
  "east" : __DIR__"kedian1",
  "southwest" : __DIR__"sishu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
