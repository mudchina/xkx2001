//Cracked by Roath
// road: /zhongnan/dajiaochang.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"大校场"NOR);

        set("long",@LONG
这是一个位於终南山山腰的圆坪，四周群山环抱。山脚下有一座大池。
每年腊月，全真派便於此地举行大校，以考察门下弟子在这一年间的进境。
往南是一条崎岖的山道。往西是一条通往峰顶的山路。往北行便是重阳宫。
只见远处十馀幢道观屋宇疏疏落落的散处山间。
LONG);

		  set("exits",([ "westup" : __DIR__"shanlu6",
								"northup" : __DIR__"gate",
								"southdown" : __DIR__"shanlu5",
							 ])
			  );

	  set("objects", ([
					 CLASS_D("quanzhen") + "/zhao" : 1,
					 ]));

	  set("cost",1);
	  set("outdoors", "zhongnan");
     setup();

}

#include "beidou.h" 

