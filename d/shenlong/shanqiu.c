//Cracked by Roath
// 山丘 /d/shenlong/shanqiu
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山丘");
	set("long", @LONG
这是一片山丘地，地上满是树叶和黄土，由于刚下过雨，地面十分泥泞，
突然，你发现地上有许多蛇虫爬行的痕迹，粗细不均，小的有如筷子，大的
确似车辙，你不由得浑身起了一层鸡皮疙瘩。北面是一片果园。
LONG
        );
        set("outdoors", "shenlong");
	set("exits", ([
		"southwest" : __DIR__"shanlu2",
                "north" : __DIR__"guoyuan",
        ]));
        set("snaketype", ({"yinhuan"}));
	set("cost", 5);

        setup();
}

#include "/d/shenlong/snakeroom.h";
