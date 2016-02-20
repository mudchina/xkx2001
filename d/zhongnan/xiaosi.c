//Cracked by Roath
// road: /zhongnan/xiaosi.c

inherit ROOM;

void create()
{
        set("short","草堂寺");

        set("long",@LONG
这是一座位於终南山北麓的小寺。寺院中的一口古井，名为烟雾井。
因为每天清晨都会有一股巨大的烟雾，自井里袅袅升起，不少游客来此，
就是为了一观此奇景。往南上是一条崎岖的山道。往北是一条阴森森的
小径。
LONG);

        set("exits",([ "north" : __DIR__"haoshanxiaojing6",
                        "southup" : __DIR__"shanlu6",
                      ])
           );
	  set("cost",1);

        setup();

        replace_program(ROOM);
}

