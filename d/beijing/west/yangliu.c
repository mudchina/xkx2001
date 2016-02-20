//Cracked by Roath
// Room: /d/beijing/west/yangliu.c

inherit ROOM;

void create()
{
	set("short", "杨柳胡同");
	set("long", @LONG
这是北京城里一条平常的小胡同，因为胡同口种有两棵杨柳树，
因而得名为杨柳胡同。胡同里面有座大宅子，最近似乎有不少操外地
口音的人出出进进。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baidamen",
  "south" : __DIR__"xidan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
