//Cracked by Roath
// Room: /d/beijing/zijincheng/longfumen.c

inherit ROOM;

void create()
{
	set("short", "隆福门");
	set("long", @LONG
这是连接后三宫和西六宫的一个门,东边就是交泰殿,西边是通往
西六宫的通道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tongdao2",
  "east" : __DIR__"jiaotaidian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
