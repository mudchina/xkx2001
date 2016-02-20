//Cracked by Roath
// road: /zhongnan/milin2.c

inherit ROOM;

void create()
{
        set("short","树林");

        set("long",@LONG
走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，自密
林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。只见一块石碑(shibei)
立在当眼ㄦ处。往东是一块空地。其它方向尽是茂密的树林。
LONG);

        set("item_desc",(["shibei" : "

			终南古墓，
			外人止步。

\n",]));


        set("exits",([ "north" : __DIR__"kongdi",
                        "southwest" : __DIR__"milin4",
				"west" : __DIR__"milin3",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
