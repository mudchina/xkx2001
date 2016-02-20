//Cracked by Roath
// mituo.c 弥陀岩
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "弥陀岩");
	set("long", @LONG
这里古木参天，巨石峭立。多雨时节，有飞瀑如练，从岩上垂挂下来，溅
起千堆细沫，诗云：虹雨千层吹不断，琉璃万盅涌还多。瀑边两大巨石夹峙，
岩壁小松攀生，仰望天空细如一线，即为「一线天」之所在。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"qianshou",
		"southeast" : __DIR__"liandan",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
