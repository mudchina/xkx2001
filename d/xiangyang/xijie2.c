//Cracked by Roath
// Room: /d/xiangyang/xijie2.c

inherit ROOM;

void create()
{
	set("short", "西街");
	set("long", @LONG
这是一条宽广的大道，路上甚是乾净，从这沿着青石板道向西直去便可到镇
西门。北面是一条寂静的小路，通往米花街。南边传来阵阵的呐喊，军士操练之
声及耳可闻。
LONG
	);
        set("coordinates", ([ "x" : -5, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaoshi",
  "north" : __DIR__"mihua",
  "east" : __DIR__"xijie1",
  "west" : __DIR__"zhenxi",
]));
	set("outdoors", "xiangyang");
	set("no_sleep_room", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
