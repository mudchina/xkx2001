//Cracked by Roath
// road: /zhongnan/xiaojing2.c

inherit ROOM;

void create()
{
        set("short", "山间小径");

        set("long",@LONG
这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林苍翠
，遍地山花，枝头啼鸟唱和不绝。往西和东南可通往山林深处。
LONG);

        set("exits",([ "west" : __DIR__"xiaojing3",
                        "southeast" : __DIR__"xiaojing1",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}

