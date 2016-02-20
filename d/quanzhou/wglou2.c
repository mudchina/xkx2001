//Cracked by Roath
// wglou2.c 万国烟雨楼
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "万国烟雨楼");
	set("long", @LONG
楼上酒桌满布，宾客不绝。推窗远眺，湖光荡漾，水雾空朦，美不胜收，
也因此吸引了来自全国各地的客商，游客来此休憩及品尝妙手厨师的手艺。号
称天下第一菜的「佛跳墙」便是烟雨楼的绝活。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"down" : __DIR__"wglou1.c",
	]));

        set("objects", ([ 
		__DIR__"npc/wu" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
