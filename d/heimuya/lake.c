//Cracked by Roath
// Room: /d/heimuya/lake.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", HIC"小湖"NOR);
        set("long", @LONG
这里是平定州郊外的一个小湖，湖旁都是垂柳，湖
面水波微动。湖边长满了野花，花香醉人。小湖对面有
个菜园，有数名庄稼农人在菜园里在忙着浇水。四周围
还有几家农舍。
LONG
        );

        set("exits", ([
                "east" : __DIR__"nongshe1",
                "north" : __DIR__"nongshe2",
                "southwest" : __DIR__"smallhill2",
        ]));

        set("objects", ([
                "/d/emei/obj/flower" : 1,
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

