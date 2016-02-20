//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "诵经堂");
        set("long", @LONG
这里是僧人们读诵经书的地方，满地的菩团。正前方是集密、怖畏、胜乐
三大金刚的雕像，地上则散放了一些经书。
LONG
        );
        set("exits", ([
                "west" : __DIR__"yanwu",
        ]));

	set("objects",([
	"d/qilian/obj/fojing1" : 1,
	]));
	set("cost", 1);
        setup();
        replace_program(ROOM);
}
