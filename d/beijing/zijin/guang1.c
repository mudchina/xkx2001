//Cracked by Roath
// Room: /d/beijing/zijincheng/guang1.c

inherit ROOM;

void create()
{
	set("short", "殿前广场");
	set("long", @LONG
这是太和殿前的大广场。中间一条白玉石路通向太和殿，两边各
有一排石狮护拥着着这条白玉路。每一各石狮边上都站立一名带刀侍
卫，目不斜视，纹丝不动。
LONG
	);
	set("exits", ([ /* sizeof() == 10 */
   "northeast" : __DIR__"zhongzuomen",
  "south" : __DIR__"taihemen",
  "east" : __DIR__"zuoyimen",
  "northwest" : __DIR__"zhongyoumen",
   "west" : __DIR__"youyimen",
  "north" : __DIR__"taihedian",
   
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
