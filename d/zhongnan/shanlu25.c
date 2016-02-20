//Cracked by Roath
// road: /zhongnan/shanlu25.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","山路");

		  set("long",@LONG
此段山路两边都是杂草，看来走的人不多，南上通往终南山山峰，往北通往大西北。
LONG);

		  set("exits",([ "north" : __DIR__"shanlu26",
								"southup" : __DIR__"shanlu24",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

