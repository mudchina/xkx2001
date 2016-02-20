//Cracked by Roath
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "绸缎庄");
    set("long", @LONG
这里是京城里有名的几家绸缎庄之一，店里就是一位张姓的老板娘当家。店
面虽然不大，可是绫罗绸缎摆得到处都是，让你看的眼花缭乱。
LONG
	);

    set("exits", ([
	"out" : __DIR__"tianqiao",
    ]));

    set("objects", ([
	__DIR__"npc/zhangshi":1,
    ]));

    setup();
}
