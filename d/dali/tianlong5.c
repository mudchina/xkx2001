//Cracked by Kafei
//zyz /12/13/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
一间黑漆漆的屋子，北面墙前坐了一个老僧，正在面壁。 等你
稍稍适应了混暗的光线，你似乎看到墙上画了些图像。
LONG
        );

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

