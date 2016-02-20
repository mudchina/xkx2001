//Cracked by Roath
// Room: /d/xiangyang/migongci.c

inherit ROOM;

void create()
{
	set("short", "米公祠");
	set("long", @LONG
这是北宋名书画家米芾的祠宇。庵院临江而立，和夫人城隔江相望。这
有碧绿的草坪，清净的庭院，参天的银杏。奇花秀草，尊尊怪雕奇刻，无不
处处动人，给人以洁、净、幽、深之感。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : 9 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"migonglu",
  "enter" : __DIR__"jieting",
]));

	setup();
	replace_program(ROOM);
}
