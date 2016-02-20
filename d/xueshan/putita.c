//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "菩提塔");
        set("long", @LONG
一个须弭座佛塔，塔上有狮子浮雕，八吉祥图案："轮、螺、伞、盖、
花、瓶、鱼、吉祥节"，分别刻於塔的四面。塔底部是莲花座，塔身从下
至上红陶质塔刹逐层嵌裹，上下共十三层，称为 "十三天"。塔瓶上有宝
盖，盖上有宝珠。
LONG
        );
        set("exits", ([
                "east" : __DIR__"frontyard",
        ]));
	set("objects", ([
                "/clone/weapon/falun" : 1,
        ]));
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
