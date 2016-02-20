//Cracked by Roath
// road: /zhongnan/zoudao4.c

inherit ROOM;

void create()
{
        set("short","走道");

        set("long",@LONG
这阴森森的走道，也不知道是通到哪ㄦ的。墙上的一枝小蜡烛，正哔
哔啵啵的燃烧着。那黄晕的微光，正好照亮了这一段走道，再远一点ㄦ就
看不到了。走道尽头似乎有些人声传来。这走道东接大厅。南通弟子休息
室。西边是一个紧闭的石门。
LONG);

		  set("exits",([ "west" : __DIR__"shishi",
								"south" : __DIR__"nyudiziqinshi",
								"east" : __DIR__"dating",
								])
			  );
	  set("cost",1);

        setup();
        replace_program(ROOM);
}

