//Cracked by Roath
// Room: /d/dali/wuhua10.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"小亭"NOR);
	set("long", @LONG
这是一个七角小亭，亭子前面就是临方池。临方池方圆十二里，白石砌成，
水深五丈四尺，鱼鳖悉有，是给五华楼里的贵宾们垂钓享乐所修。
LONG);
	set("exits", ([
		"south" : __DIR__"wuhua1.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
