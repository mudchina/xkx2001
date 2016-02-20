//Cracked by Roath
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "淑女牌坊");
        set("long", @LONG
在你的面前是一座高大的石坊，上面写着“淑女牌坊”四个镏金
大字，由于年代久远，久经日晒雨淋，已经显得有些黯淡了。
LONG
        );
        set("exits", ([
        ]));


        setup();
        set("outdoors","xixia");
        replace_program(ROOM);
}
