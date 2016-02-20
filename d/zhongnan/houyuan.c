//Cracked by Roath

// road: /zhongnan/houyuan.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","小院子");

        set("long",@LONG
这是厨房後的一个小院子。不远的围墙那ㄦ，一扇小门正关着。出了
小门後就是後山了。往南是厨房。往西是後山。
LONG);

		  set("exits",([ "south" : __DIR__"kitchen1",
								"west" : __DIR__"haoshanxiaojing1",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");
	  create_door("south", "木门", "north", DOOR_CLOSED);

	  setup();
}
