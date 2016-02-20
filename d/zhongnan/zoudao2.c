//Cracked by Roath
// road: /zhongnan/zoudao2.c

inherit ROOM;

void create()
{
        set("short","走道");

        set("long",@LONG
这阴森森的走道，也不知道是通到哪ㄦ的。墙上的一枝小蜡烛，正哔
哔啵啵的燃烧着。那黄晕的微光，正好照亮了这一段走道，再远一点ㄦ就
看不到了。走道尽头似乎有些人声传来。除了南方有一丝光明传来外，其
余方向都是幽暗的走道。
LONG);

        set("exits",([ "west" : __DIR__"zoudao2",
                        "south" : __DIR__"dating",
                        "east" : __DIR__"zoudao2",
                        "north" : __DIR__"zoudao1",
                      ])
           );
	  set("cost",1);

	 setup();
}

