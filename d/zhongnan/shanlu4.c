//Cracked by Roath
// road: /zhongnan/shanlu4.c

inherit ROOM;

void create()
{
		  set("short","山路");
		  set("long",@LONG
这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱郁的
古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭峻，山川
毓秀，不少鸟ㄦ在枝头高声啼唱不绝。往南下是两块耸天而立的巨石。往
北是一片蓊郁的山林。
LONG);

        set("exits",([ "southdown" : __DIR__"sunmoonrock",
                        "northup" : __DIR__"shulin1",
                      ])
           );
	  set("cost",3);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
