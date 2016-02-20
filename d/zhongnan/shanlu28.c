//Cracked by Roath
// road: /zhongnan/shanlu28.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","小路");

		  set("long",@LONG
此段小路两边都是杂草，看来走的人不多，四周的景色都越来越萧条，看来已经
快到沙漠了。往南通往终南山，往西北通往大西北。
LONG);

		  set("exits",([ "northwest" : __DIR__"shanlu29",
								"south" : __DIR__"shanlu27",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

