//Cracked by Roath
// room: /d/city/nanjiao.c
// Jay 7/4/96

inherit ROOM;

void create()
{

        set("short", "草地");
        set("long", @LONG
这里是一遍绿茵茵的草地，像是一方绿色的毯子铺在地上。草丛中开着一些
不知名的小花，有红的、黄的，还有紫的。花瓣上、草叶上的露珠闪着晶莹的光。
LONG
        );

        set("objects", ([
            "/d/city/obj/stone" : 1,
            "/d/shaolin/obj/caoliao" : 3,
	]));


        set("exits", ([
                "west" : __DIR__"nanjiao1",
                "east" : __DIR__"seforest",
		"northeast" : __DIR__"dongjiao4",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

