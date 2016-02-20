//Cracked by Roath
// road: /zhongnan/shanlu29.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","小路");

		  set("long",@LONG
此段小路两边都是杂草，看来走的人不多，四周的景色都越来越萧条，看来已经
快到沙漠了，西北方向可以看到一座陡峭的山峰。
LONG);

		  set("exits",([ "northwest" : __DIR__"shanlu30",
								"southeast" : __DIR__"shanlu28",
						  ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

