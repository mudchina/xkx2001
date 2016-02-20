//Cracked by Roath
// road: /zhongnan/milin3.c

inherit ROOM;

void create()
{
        set("short","树林");

        set("long",@LONG
走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，自密
林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。往西是一座古墓。其
它方向尽是茂密的树林。
LONG);


        set("exits",([ "north" : __DIR__"milin1",
                        "east" : __DIR__"milin2",
				"south" : __DIR__"milin4",
				"west" : __DIR__"gumu",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
