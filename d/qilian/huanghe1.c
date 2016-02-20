//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "黄河");
        set("long", @LONG
黄河出了青海，经甘肃之后，向东受到黄土高原的阻挡，转而向东北
流去。在流经黄土高原的过程中泥沙含量猛增，水色澄黄，就被称为黄河。
LONG
        );
        set("exits", ([
		"northeast" : "/d/forest/huanghe1",
                "west" : __DIR__"huanghe2",
        ]));
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
