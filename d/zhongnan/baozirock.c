//Cracked by Roath
// road: /zhongnan/baozirock.c

inherit ROOM;

void create()
{
        set("short","抱子岩");

        set("long",@LONG
一路过来，山路是越来越险。只见光秃秃的山路，左旁尽是怪石，而
右则是万丈深渊，渺不见底。前方不远处的一块巨石，便是有名的抱子岩。
再看几眼，觉那岩生得甚是奇怪，就如一个妇人抱着个孩子般，细心呵护。
往南和西各是一片密林。
LONG);

        set("exits",([ "south" : __DIR__"shulin1",
                        "west" : __DIR__"shulin2",
                      ])
           );
	  set("cost",2);
	  set("objects", ([
				 __DIR__"npc/chen-zy" : 1,
		  ]));
	  set("outdoors", "zhongnan");

	  setup();
}
