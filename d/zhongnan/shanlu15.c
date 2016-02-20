//Cracked by Roath
// road: /zhongnan/shanlu15.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","山道");

		  set("long",@LONG
此段山路是通往后山脚。往南上是一大片树林。往北下可以望见一个较大的湖。
LONG);

		  set("exits",([ "northdown" : __DIR__"taiyici",
								"southup" : __DIR__"shulin6",
							 ])
			  );
	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

