//Cracked by Roath
// Room: /d/xiangyang/xijie1.c

inherit ROOM;

void create()
{
	set("short", "西街");
	set("long", @LONG
这是一条宽阔的青石板道，官兵频频在周围巡逻。两旁气象森严，过往路人
尽皆快步行过，不敢停留。南边隐隐传来阵阵呐喊之声，原来是座兵营。南边可
望见一座高耸的鼓楼，用以示警召集兵士。
LONG
	);
        set("coordinates", ([ "x" : -1, "y" : 0 ]) );
	set("no_clean_up", 0);
	set("no_sleep_room", 1);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"guangc",
  "west" : __DIR__"xijie2",
  "south" : __DIR__"bydamen",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
