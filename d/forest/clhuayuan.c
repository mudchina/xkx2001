//Cracked by Roath
// changle/clhuayuan.c

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这个花园是典型的江南风格，精巧细致。园中花卉虽没有什么名贵
品种，也是争奇斗妍。正中一条石子铺就的小路，上面遍布青苔，甚是
湿滑。向东是一条甬道。
LONG );

        set("exits", ([
		"south" : __DIR__"clbajiaoting",
		"west" : __DIR__"clzoulang2",
		"east" :  __DIR__"clyongdao",
        ]));

        set("cost", 0);

        setup();

        replace_program(ROOM);
}

