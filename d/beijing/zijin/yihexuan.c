//Cracked by Roath
// Room: /d/beijing/zijincheng/yihexuan.c

inherit ROOM;

void create()
{
	set("short", "颐和轩");
	set("long", @LONG
这里原为乾隆皇帝归政后的憩息之所。“颐和”的名称是乾隆皇
帝预祝他自己老年幸福。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"leshoutang",
  "north" : __DIR__"hougongmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
