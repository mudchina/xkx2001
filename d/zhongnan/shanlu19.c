//Cracked by Roath
// road: /zhongnan/shanlu19.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","山路");

		  set("long",@LONG
此段山路是沿着峭壁而开凿出来的，特别崎岖难行。往南向下通往湖滨，
北上通往峰顶。
LONG);

		  set("exits",([ "southdown" : __DIR__"shanlu18",
								"northup" : __DIR__"shanlu20",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

