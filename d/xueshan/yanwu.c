//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "演武场");
        set("long", @LONG
这里僧人们练武的地方。场中有几个喇嘛在练武。武场东西分
别是经堂和诵经堂，北面走上台阶是度母殿，边上一条走廊通向金
刚院。
LONG
        );
        set("exits", ([
                "west" : __DIR__"jingtang",
		"east" : __DIR__"songjing",
		"south" : __DIR__"frontyard",
		"north" : __DIR__"zoulang",
		"northup" : __DIR__"dumudian",
        ]));

	set("objects", ([
		__DIR__"npc/gelun" : 2,
	]));
	set("cost", 1);
        setup();
	set("outdoors","qilian-shan");
        replace_program(ROOM);
}
