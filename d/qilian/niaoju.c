//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "鸟居台");
        set("long", @LONG
沿着大通岭往上走，道路愈显艰难。沿途荆棘丛生，怪石嶙嶙，眼
见已是兽迹罕至了，却有百鸟群飞，两耳只闻啾啾之声。仰头望天，一
片碧蓝之下，耳畔鸟鸣，苍苍大地，尽在脚下，不禁豪情顿生。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"datong-ling",
                "northup" : __DIR__"mazong",
                "northwest" : __DIR__"qilian",
        ]));

	set("objects" , ([
		"/d/jiaxing/npc/wuya" : 1,
		"/d/city/npc/maque" : 2,
	]));

	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
