//Cracked by Roath
// road: /zhongnan/shenheyuan.c

inherit ROOM;

void create()
{
        set("short","神禾原");

        set("long",@LONG
此处位於终南山中部的翠华山附近。放眼望去，只见一片坦荡无垠的
大平原，夹在群山之间。传说商朝末年，姜子牙率兵伐纣攻打长安时，粮
草短缺，在此获神禾老汉之助，得米万斛，因此命名为神禾原。往东南和
北上各是一片树林。往南是一处遗迹。
LONG);

        set("exits",([ "southeast" : __DIR__"shulin2",
                        "north" : __DIR__"shulin3",
				"west" : __DIR__"foyezhen",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");
        set("objects", ([
				 "/d/village/npc/seller": 1,
				 "/clone/obj/car" : 1,
		  ]));

        setup();

}

