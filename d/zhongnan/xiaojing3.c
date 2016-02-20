//Cracked by Roath
// road: /zhongnan/xiaojing3.c

inherit ROOM;

void create()
{
        set("short", "山间小径");

        set("long",@LONG
这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林苍翠
，遍地山花，枝头啼鸟唱和不绝。往南可看到一条小河。往东可通往山林
深处。
LONG);

        set("exits",([ "south" : __DIR__"river",
                        "east" : __DIR__"xiaojing2",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
