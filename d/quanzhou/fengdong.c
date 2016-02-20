//Cracked by Roath
// fengdong.c 风动岩
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "风动岩");
	set("long", @LONG
这是灵山的北麓，林木茂盛，奇石磷磷。中有一块似方而圆的天然岩石，
只要一人用手摇撼，它就能兀然而动。它甚至弱不禁风，阵风吹来，似乎也会
摆动，人称「风动岩」，又名「碧玉球」，上刻「天然机妙」。有诗云：「动
时锦水将轮转，圆处巴山作镜看」。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
