//Cracked by Roath
// road: /zhongnan/shanlu1.c

inherit ROOM;

void create()
{
        set("short", "山路");

        set("long",@LONG
这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱郁的
古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭峻，山川
毓秀，往南下是一条道路。往北上走是一条蜿蜒的山路。往南下是一条道
路。
LONG);

        set("exits",([ "southdown" : __DIR__"daolu",
                        "northup" : __DIR__"shanlu2",
                      ])
           );
	  set("cost",3);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
