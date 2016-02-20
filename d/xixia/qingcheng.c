//Cracked by Roath
// Room: /d/xixia/qingcheng.c

inherit ROOM;

void create()
{
	set("short", "青城");
	set("long", @LONG
青城位于靖远以南三百二十里，西南八十里就是兰州，名为青城，其
实只是个小镇，因为地处北去西夏的要冲，许多往来西夏和大宋的商旅都
必须经过这儿，人来人往很是热闹。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"desert4",
  "east" : "/d/huanghe/hetao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
