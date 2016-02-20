//Cracked by Roath
// Room: /d/xixia/tulu.c

inherit ROOM;

void create()
{
	set("short", "林中土路");
	set("long", @LONG
这是山间的土路，勉强可以通行一辆大车，路面上有两条深深的车辙印，路
边山坡上全是参天巨木，看上去密不透风，这里很幽静，除了偶尔几声鸟叫才能
打破寂静。土路向东北蜿蜒延伸转了个弯，西南面隐约可以看见林中一面大屋顶
上的旗帜。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"kongdi",
  "south" : __DIR__"luorilin2",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
