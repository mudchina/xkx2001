//Cracked by Roath
// road: /zhongnan/milin8.c

inherit ROOM;

void create()
{
        set("short","树林");

        set("long",@LONG
走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，自密
林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。只见一块石碑(shibei)
立在当眼ㄦ处。往东是一座古墓。其它方向尽是茂密的树林。往西是黄沙岭。
LONG);

        set("item_desc",(["shibei" : "

			终南古墓，
			外人止步。

\n",]));


        set("exits",([ "west" : __DIR__"huangshaling",
                        "east" : __DIR__"gumu",
				"south" : __DIR__"milin9",
				"north" : __DIR__"milin7",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();
        replace_program(ROOM);
}
