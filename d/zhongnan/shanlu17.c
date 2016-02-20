//Cracked by Roath
// road: /zhongnan/shanlu17.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","山道");

		  set("long",@LONG
此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边必须
面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然一失足，
就要掉进万丈深渊了。往东通往湖滨，，西上通往山峰。
LONG);

		  set("exits",([ "eastdown" : __DIR__"shanlu16",
								"westup" : __DIR__"shanlu18",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

