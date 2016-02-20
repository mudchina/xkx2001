//Cracked by Roath
// 山坡2 /d/shenlong/shanpo2
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山坡");
        set("long", @LONG
这是一个山坡，通向北方的一座山峰，你已经爬的气喘嘘嘘了，真想停
下来休息休息，突然间，你看见树上、草上、路上，东一条，西一条全是毒
蛇，可怕极了！... 是非之地，不可久留，还是赶快离开吧。北面是一个狭
窄的山道，往南是一个山坡。
LONG
        );
	set("cost", 6);
        set("outdoors", "shenlong");

        set("exits", ([
		"northup" : __DIR__"shandao",
		"southdown" : __DIR__"shanpo1",
        ]));

        set("snaketype", ({"jinhuan", "yinhuan"}));

        setup();
}

#include "/d/shenlong/snakeroom.h"
