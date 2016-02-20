//Cracked by Roath
// Room: /d/zhongnan/zhoulang.c
// Date: sdong 07/23/98

inherit ROOM;


void create()
{
		  set("short", "走廊");
		  set("long", @LONG
你走在一条走廊上，再往前就是养心殿。东面通往长春殿。
LONG
		  );

		  set("exits", ([
					 "west" : __DIR__"taijie3",
					 "east" : __DIR__"dadian",
		  ]));

		  set("outdoors", "zhongnan");
		  set("cost", 2);
		  setup();
}

