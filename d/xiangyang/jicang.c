//Cracked by Roath
// Room: /d/xiangyang/jicang.c

inherit ROOM;

void create()
{
	set("short", "积仓街");
	set("long", @LONG
襄阳之所以能以一城之力独拒蒙古大军数十年而屹立不倒，除了全城上下
平民与将士齐心，还因襄阳广积粮草，死守时稍有积栗可赖。於是这守备更
是森严，常人不允许接近此处。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"mihua",
  "east" : __DIR__"beijie1",
  "south" : __DIR__"liangc2",
  "north" : __DIR__"liangc",
]));

	setup();
	replace_program(ROOM);
}
