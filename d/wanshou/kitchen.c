//Cracked by Roath
// /d/wanshou/kitchen.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "膳堂");
        set("long", @LONG
万兽山庄弟子用餐之所，大堂正中的长桌上用大海碗装着各种
山镇野味，一角的一个小桌上用牛皮袋子装着珍稀的豹乳供山庄弟
子饮用。
LONG
        );
        set("exits", ([
				"east" : __DIR__"qianting",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
