//Cracked by Roath
// room: /d/city/nanjiao1.c
// Jay 7/4/96

inherit ROOM;

void create()
{

        set("short", "草地");
        set("long", @LONG
这里是一遍绿茵茵的草地，像是一方绿色的毯子铺在地上。草丛中开着一些
不知名的小花，有红的、黄的，还有紫的。花瓣上、草叶上的露珠闪着晶莹的光。
西面是扬州城的南门。
LONG
        );

        set("objects", ([
            "/d/city/obj/stone" : 3,
		"/d/emei/obj/flower" : 1,
            "/d/shaolin/obj/caoliao" : 2,
	]));


        set("exits", ([
                "east" : __DIR__"nanjiao2",
                "west" : __DIR__"nanmen",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

