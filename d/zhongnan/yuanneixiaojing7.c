//Cracked by Roath
// road: /zhongnan/yuanneixiaojing7.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","院内小径");

        set("long",@LONG
这全真教的後院面积颇为广大，殿宇散於山间，山上遍植松杉翠林，
泉水淙淙，环境清幽肃静，小径曲回通幽。走到宁静处，只闻枝头鸟啼，
给人一种闲适的感觉。不远处一个伙工正在劈柴，看他那一劈一砍，颇
具武功架势，有可能是个会家子呢。往西是厨房。往北是一条小径。
往南是重阳宫后殿.
LONG);

		  set("exits",([ "west" : __DIR__"kitchen1",
								"north" : __DIR__"yuanneixiaojing6",
						"south" : __DIR__"haodian",
							 ])
			  );
	  set("cost",1);
	  set("outdoors", "zhongnan");

		create_door("south", "木门", "north", DOOR_CLOSED);

		setup();

		replace_program(ROOM);
}

