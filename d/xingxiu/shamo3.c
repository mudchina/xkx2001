//Cracked by Roath
// Room: /d/xingxiu/shamo3.c

#include <room.h>
inherit ROOM;

void create()
{
       set("short","大沙漠");
       set("long", @LONG
这是一片一望无际的大沙漠。你一进来就迷失了方向。
看来要走出这块沙漠并非易事。
LONG
     );
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"shamo4",
		"south" : __DIR__"shamo1",
		"north" : __DIR__"shamo2",
	]));
	set("cost", 5);
	set("outdoors", "xingxiu-hai");
	setup();
}

#include "/d/xingxiu/shamo.h"
