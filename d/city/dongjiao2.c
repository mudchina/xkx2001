//Cracked by Roath
// room: /d/city/xijiao1.c
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
		"/d/emei/obj/flower" : 1,
	]));


        set("exits", ([
                "north" : __DIR__"neforest",
                "south" : __DIR__"dongjiao1",
		"northwest" : __DIR__"beijiao2",
        ]));
	set("outdoors","city");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

