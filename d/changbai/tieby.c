//Cracked by Roath
// Room: tieby.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "铁壁崖");
	set("long", @LONG
这里是瀑布西侧的一条小路，溯乘槎河而上。这段路极为险峻。一侧是
绝壁，一侧是万丈深壑。行人至此，只能面朝绝壁，单行贴壁侧身而过，极
是危险。
LONG	);

	set("exits", ([ 
              "southdown" : __DIR__"pubu",
              "eastup" : __DIR__"jiglz",
        ]));

        set("objects",([
                __DIR__"npc/sai" : 1,
        ]));
	
        set("outdoors", "changbai");
        set("cost", 4);

        set("count", random(3)+1);

	setup();
}
