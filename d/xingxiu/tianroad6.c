//Cracked by Roath
// room: /d/xingxiu/tianroad6.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "小峰");
        set("long", @LONG
这里是天山上一座小小的山峰。从这里向周围望去，帕米尔高原
的风光尽收眼底。东面一条小路可以下山。
LONG
        );
        set("exits", ([
            "eastdown" : __DIR__"tianroad5",
	    "southdown" : __DIR__"shangu",
        ]));
        set("objects", ([
               "/d/wudang/npc/snake" : 1, 
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 3);
	set("bing_can", 3);
        setup();
        replace_program(ROOM);
}

