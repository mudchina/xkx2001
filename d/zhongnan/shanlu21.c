//Cracked by Roath
// road: /zhongnan/shanlu21.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","冰洞口");

		  set("long",@LONG
你眼前出现一个大洞，洞内凉气飕飕，虽盛夏亦有坚冰，寒气逼人。
原来这就是冰洞。此段山路是沿着峭壁而开凿出来的，特别崎岖难行。往
南向下通往湖滨，西下也有一条小路。
LONG);

		  set("exits",([ "westdown" : __DIR__"shanlu22",
							  "southdown" : __DIR__"shanlu20",
								"enter": __DIR__"bingdong",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}
