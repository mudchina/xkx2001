//Cracked by Roath
// room: /d/xingxiu/btroom
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "小山丘");
        set("long", @LONG
这是一座小山丘。一条小溪绕山而过。这一带本来没有什么毒虫，
但最近不知何故常常听到有人被毒蛇咬死的传言。
LONG
        );
        set("exits", ([ 
	    "eastdown" : __DIR__"btroad",
        ]));
        set("resource/water", 1);

        set("objects", ([ 
            CLASS_D("baituo")+"/ke" : 1,
	    __DIR__"npc/snake" : 2,
         ]) );
        replace_program(ROOM);
	set("cost", 2);
        setup();
}

