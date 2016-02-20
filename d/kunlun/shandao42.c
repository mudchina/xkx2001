//Cracked by Roath
// Room: /d/mingjiao/shandao42.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
山间土道并无石阶，山雨过后，因此地土硬，也非十分泥泞。两边树
木不多，野花草却是遍地。清风吹来，满山的蒲英一朵一朵地浮了起来，
淡淡得弥漫四野。是雾，是烟，是花，是雨。。。。。。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shanqiu",
  "southwest" : __DIR__"shenwei",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
