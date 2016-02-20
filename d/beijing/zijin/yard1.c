//Cracked by Roath
// Room: /d/beijing/zijincheng/yard1.c

inherit ROOM;

void create()
{
	set("short", "玉石通道");
	set("long", @LONG
这是一条汉白玉石建造的通道,连接着乾清宫和乾清门,通道两
侧栏杆上雕刻着一条条盘旋飞舞的龙.通道下面两侧是两个的小
广场.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianqingmen",
  "north" : __DIR__"qianqinggong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
