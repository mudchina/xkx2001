//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "哈拉湖");
        set("long", @LONG
郁水过玉门关向东，北去二百里，汇之为泽，名哈拉。传说有恶蛟藏在里面，
每年春秋两季，以肥牛羊十头祭典才能平安，不然会淫雨连绵达月余。这里是方
圆八百里唯一的水源。
LONG
        );
        set("exits", ([
                "west" : __DIR__"yumenguan",
                "south" : __DIR__"yumen",
        ]));

        set("resource/water", 1);

	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
