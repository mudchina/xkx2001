//Cracked by Roath
// Room: /d/beijing/east/dongchangan2.c

inherit ROOM;

void create()
{
	set("short", "东长安街");
	set("long", @LONG
这是繁华热闹的东长安街，大街街面宽阔，车水马龙，川
流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货小
吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chongwenmen",
  "west" : "/d/beijing/zijin/dongchangan",
  "east" : __DIR__"guanxiangtai",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
