//Cracked by Roath
//Kane

inherit FERRY;

void create()
{
	set("short", "码头");
	set("long", @LONG
这是太湖中一个水洲，青石砌的码头上停泊了一些小船。只见
前面楼阁纡连，偌大一座庄院，便是太湖归云庄。
LONG
	);
	 set("exits", ([
		"west" : __DIR__"matou",
	]));
	set("cost", 2);
	set("outdoors", "taihu");

	set("water_name", "湖");
	set("boat", __DIR__"duchuan2");
	set("opposite", __DIR__"taihu2");

	setup();
}

#include "ferry.h"
