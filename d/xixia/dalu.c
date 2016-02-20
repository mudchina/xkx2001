//Cracked by Roath
// Room: /d/xixia/dalu.c

inherit ROOM;

void create()
{
	set("short", "林中大路");
	set("long", @LONG
这是山间的土路，勉强可以通行一辆大车，路面上有两条深深的车辙印，路
边山坡上全是参天巨木，看上去密不透风，这里很幽静，除了偶尔几声鸟叫才能
打破寂静。土路向北蜿蜒延伸转了个弯。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"luorilin2",
  "north" : __DIR__"xiaolu",
  "south" : __DIR__"luorilin",
]));
	set("cost", 2);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
