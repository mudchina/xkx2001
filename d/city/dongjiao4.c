//Cracked by Roath
// room: /d/city/dongjiao4.c
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
            "/d/quanzhou/npc/wuya" : 1,
		"/d/emei/obj/flower" : 1,
	]));


        set("exits", ([
                "north" : __DIR__"dongjiao3",
                "south" : __DIR__"seforest",
		"southwest" : __DIR__"nanjiao2",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

