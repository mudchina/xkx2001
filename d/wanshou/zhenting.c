//Cracked by Roath
// /d/wanshou/zhenting.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山庄正厅");
        set("long", @LONG
眼前便是万兽山庄正厅，大厅中央是一张厚重的八仙桌，周
遭摆着五把太师椅子，显然是山庄五位庄主的议事之所。大厅一
角卧着一只猛虎，半睡半醒，仿佛正在打盹。厅的左手是驯兽场，
右手一间秘室，再往前便是后厅。
LONG
        );
        set("exits", ([
		        "north" : __DIR__"houting",
				"south" : __DIR__"qianting",
                "east" : __DIR__"mishi",
                "west" : __DIR__"xunshouchang",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
