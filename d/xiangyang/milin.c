//Cracked by Roath
// Room: /d/xiangyang/milin.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
一入林中，驻步回观林中景物，称羡不已。果然山不高而秀雅，水不深而
澄清；地不广而平坦，树不大而茂盛；松篁交翠，猿鹤相亲。自此山之南，一
带高岗，乃卧龙岗。岗前疏林内茅芦中，即夕日诸葛亮高卧之地。在此遥望卧
龙岗，果然清景异常。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -16, "y" : -3 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guangde",
]));

	setup();
	replace_program(ROOM);
}
