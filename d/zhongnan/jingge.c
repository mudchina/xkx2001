//Cracked by Roath
// road: /zhongnan/jingge.c
// sdong 08/05/98

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short",HIM"藏经阁"NOR);

		  set("long",@LONG
这ㄦ是重阳宫外不远的藏经阁，不少教内的书典便是存放在此。只见
这三层高的建筑，檐角高卷，恍如临流画舫，甚是精巧美观。往南是一条
小径。
LONG);

		  set("exits",([ "south" : __DIR__"yuanneixiaojing3",
							  "up"	: __DIR__"jingge2.c",
							 ])
			  );
	  set("cost",1);

	  set("objects", ([
				 CLASS_D("quanzhen") + "/li" : 1,
					 ]));

	  setup();

}


