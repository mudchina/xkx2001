//Cracked by Roath
// Room: /d/beijing/zijincheng/leshoutang.c

inherit ROOM;

void create()
{
	set("short", "乐寿堂");
	set("long", @LONG
原为乾隆皇帝归政后园庭憩息之所。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"huayuan",
  "south" : __DIR__"yangxingdian",
  "north" : __DIR__"yihexuan",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
