//Cracked by Roath
// Room: /d/xiangyang/beimen.c

inherit ROOM;

void create()
{
	set("short", "北门");
	set("long", @LONG
这是襄阳城的北门。有一队官兵正在仔细的盘察出入的百姓，也许是怕金国
奸细混入城内的关系吧。从这里再往西北走就到汉水南岸了。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : 6 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"tulu5",
  "south" : __DIR__"jzjie3",
]));

	setup();
	replace_program(ROOM);
}
