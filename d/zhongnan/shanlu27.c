//Cracked by Roath
// road: /zhongnan/shanlu27.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","山路");

		  set("long",@LONG
此段山路两边都是杂草，看来走的人不多，往南通往终南山，往北通往大西北。
LONG);

		  set("exits",([ "north" : __DIR__"shanlu28",
								"south" : __DIR__"shanlu26",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

