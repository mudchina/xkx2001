//Cracked by Roath
// /d/xingxiu/silk4.c
// Jay 3/17/96
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
		"west" : __DIR__"shamo2",
		"south" : __DIR__"shamo3",
		"north" : __DIR__"shamo4",
	]));             
	set("cost", 4);
	set("outdoors", "xingxiu-hai");
        setup();

}

#include "/d/xingxiu/shamo.h"
