//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "蒙古包");
        set("long", @LONG
这是一个金璧辉煌的蒙古包，蒙古国师金轮法王的行帐。地上铺了
厚厚的羊毛地毯。帐中央有一张短案，上面摆满了咒经。
LONG
        );
        set("exits", ([
		"out" :__DIR__"caoyuan4",
        ]));

	set("objects", ([
	"/kungfu/class/xueshan/jinlun" : 1,
        ]));
	set("cost", 0);
        setup();
        replace_program(ROOM);
}
