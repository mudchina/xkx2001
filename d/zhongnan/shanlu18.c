//Cracked by Roath
// road: /zhongnan/shanlu18.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","风洞口");

		  set("long",@LONG
你眼前出现一个大洞，由两大花岗岩夹峙而成。洞内清风习习，凉气飕飕，
故称风洞。此段山路是沿着峭壁而开凿出来的，特别崎岖难行。往东向下通往
湖滨，北上通往峰顶。
LONG);

		  set("exits",([ "eastdown" : __DIR__"shanlu17",
								"northup" : __DIR__"shanlu19",
								"enter": __DIR__"fengdong",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}
