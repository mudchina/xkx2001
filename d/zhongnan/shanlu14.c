//Cracked by Roath
// road: /zhongnan/shanlu14.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","山道");

		  set("long",@LONG
此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边必须
面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然一失足，
就要掉进万丈深渊了。往北下通往后山脚，远远可以望见一个较大的湖。
LONG);

		  set("exits",([ "northdown" : __DIR__"shulin4",
								"southup" : __DIR__"shanlu13",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

