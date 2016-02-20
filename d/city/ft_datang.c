//Cracked by Roath
// chu@xkx 7/27/98

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大堂");
        set("long", @LONG
这里是斧头帮的议事厅，几只灯笼高高的挂着，厅上排了五张檀木椅子，似
乎是给帮中职位较高的人物准备的。大堂侧面有一块红松木所制的方板，上面写
了不少东西。
LONG
        );
        set("exits", ([
                "out" : __DIR__"ft_room1",
        ]));
	set("objects", ([
	    __DIR__"npc/ftb_zhu":1,
	]));
        set("cost", 1);
        set("invalid_startroom", 1);
        setup();
        "/clone/board/futou_b"->foo();
        replace_program(ROOM);
}
