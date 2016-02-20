//Cracked by Roath
// Qfy July 26, 1999.
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "正堂");
        set("long", @LONG
这是一个装修华丽的厅堂，乃是日月神教头领聚会的地方。墙
上大扁龙飞凤舞地写着“唯我独尊”，笔意纵横，震撼人心。
LONG
        );
        set("exits", ([
                "east" : __DIR__"neiyuan",
        ]));

	set("objects", ([
            __DIR__"npc/yanglt" : 1,
        ]));

	set("cost", 1);
	setup();

	replace_program(ROOM);
}
