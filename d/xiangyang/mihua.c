//Cracked by Roath
// Room: /d/xiangyang/mihua.c

inherit ROOM;

void create()
{
	set("short", "米花街");
	set("long", @LONG
这是平民杂居的米花街，几个小孩无虑的趴在地上戏耍，路旁的宅院半
掩半闭着。北边远远有香火味传来，东处即是襄阳贮粮所在，旁人不允许在那
出路。南面可到西大街。
LONG
	);
        set("coordinates", ([ "x" : -5, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"jicang",
  "south" : __DIR__"xijie2",
  "northeast" : __DIR__"miao",
]));
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
