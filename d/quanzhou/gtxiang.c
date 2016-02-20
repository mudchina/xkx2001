//Cracked by Roath
// gtxiang.c 桂坛巷
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "桂坛巷");
	set("long", @LONG
桂坛巷顺着施府高墙蜿蜒而出，一面是潺潺流水的沟渠，幽暗宁静。桂坛
巷西南面便是承天寺。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"southwest" : __DIR__"chengtian",
		"north" : __DIR__"jiangfu",
		"west" : __DIR__"xuetang",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
