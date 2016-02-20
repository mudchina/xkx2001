//Cracked by Roath
// /d/wanshou/juebi.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "庄后绝壁");
        set("long", @LONG
这是万兽山庄后面的危崖，开地摩天，深不见底。崖边一棵千
年老松斜斜地自绝壁上探出头去，独立峰巅，正所谓“雾开虎豹文
姿出，松隐龙蛇怪状孤。”
LONG
        );
        set("exits", ([
				"south" : __DIR__"shulin",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
