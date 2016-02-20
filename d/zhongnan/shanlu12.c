//Cracked by Roath
// road: /zhongnan/shanlu12.c

inherit ROOM;

void create()
{
        set("short","山路");

        set("long",@LONG
这条山路盘终南山主峰而上，山路贴着石璧凿出，只容一人可过，形
势极为险峻。往远处望去。群山环绕，列於脚下，百里美景尽收眼底，顿
时令人豪气陡声，想要长啸一声。往南下是一片空地。往北上就是终南山
主峰。
LONG);

        set("exits",([ "northup" : __DIR__"shanfeng",
                        "southdown" : __DIR__"kongdi",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
