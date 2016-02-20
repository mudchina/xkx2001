//Cracked by Roath
// Room: /d/xiangyang/bingqiku.c

inherit ROOM;

void create()
{
	set("short", "兵器库");
	set("long", @LONG
这里是襄阳城储精藏锐的兵器库。你一入其内，觉到处银光闪闪，让人眼
花缭乱。钢刀、钢剑，钢棒、钢杖，长枪、长鞭，头盔、铁甲、铁背心，各色各
样的兵器防具应有尽有，对付蒙古铁骑是非精兵锐器不足以当之。
LONG
	);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : -3, "y" : -3 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"lianwuc",
]));

	setup();
	replace_program(ROOM);
}
