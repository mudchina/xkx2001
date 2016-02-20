//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "哀牢山");
        set("long", @LONG
此山毫无生气，寸草不生，一但踏入山中, 顿感一股莫可名状的怪捩之
息，传说中的神仙刑天想刺杀天帝，没有成功，天帝砍了他的头。刑天以脐
为嘴，双乳为目，继续和天帝作战，失败後被困於此山。
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"tieshi",
                "southwest" : __DIR__"zibai",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
