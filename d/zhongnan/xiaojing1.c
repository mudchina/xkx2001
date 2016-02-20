//Cracked by Roath
// road: /zhongnan/xiaojing1.c

inherit ROOM;

void create()
{
        set("short", "山间小径");

        set("long",@LONG
这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林苍翠
，遍地山花，枝头啼鸟唱和不绝。往东可看到一条道路。往西北可通往山
林深处。
LONG);

        set("exits",([ "northwest" : __DIR__"xiaojing2",
                        "east" : __DIR__"daolu",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}



