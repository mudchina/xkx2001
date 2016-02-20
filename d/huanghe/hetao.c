//Cracked by Roath
// Room: /d/forest/hetao.c

inherit ROOM;

void create()
{
	set("short", "河套");
	set("long", @LONG
常言到“黄河九害，富了一套”。河套地区灌溉系统发达，土地
肥沃，是种庄稼的好地方。
LONG
	);
	set("cost", 3);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/xixia/qingcheng",
  "east" : __DIR__"huanghe2",
  "southwest" : __DIR__"huanghe1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
