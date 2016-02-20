//Cracked by Roath
// road: /zhongnan/huangshaling.c

inherit ROOM;

void create()
{
        set("short","黄沙岭");

        set("long",@LONG
此处位於终南山西部。只见远处王曲原上，孤立着一座由荒沙堆积而成的
山岭，波纹为奇特。据当地人说，这是在商朝，一位名叫陆亚仙的人，用法力
遣来一股黄沙而成。往东是一片密林。
LONG);

        set("exits",([ "east" : __DIR__"milin8",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");
        setup();

        replace_program(ROOM);
}

