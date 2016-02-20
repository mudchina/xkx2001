//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "丹山");
        set("long", @LONG
此地又名装山，自古以产铜著称，在嘉峪关西一百八十里，峰峦高耸，
下有小红石，可以炼铜，相传是女蜗补天时撒下。山下一条商路贯通东西。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jiayuguan",
                "north" : __DIR__"yumenguan",
		"west" : "/d/xingxiu/silk1",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
