//Cracked by Roath
// Room: /shguan1.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

// string look_bian();

void create()
{
	set("short", "山海关");
	set("long", @LONG
这里就是万里长城最东面的重要关口--山海关。这里地势险要，自古就
是关外通往中原的必经之地。站在关楼上北望，角山，古堡，烽火台历历在
目，南沿长城远眺，直深入海的老龙头依稀可见。城楼二楼上悬挂着一块巨
幅横匾(bian)。
LONG
	);

	set("item_desc", ([
		"bian" : 
	"\n"
	"    ※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　　　　※※※※\n"
	"    ※※※※　天  下  第  一  关  ※※※※\n"
	"    ※※※※　　　　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※\n"
	]));

	set("exits", ([
		"southeast" : __DIR__"shguan2",
                "northeast" : __DIR__"guandao1",
	]));

	set("outdoors", "changbai");
        set("cost", 5);

	setup();
        replace_program(ROOM);
}

/*
string look_bian()
{
	return
	"\n"
	"    ※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　　　　※※※※\n"
	"    ※※※※　天  下  第  一  关  ※※※※\n"
	"    ※※※※　　　　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※\n";
}
*/

