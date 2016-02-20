//Cracked by Roath
// room: /d/baituo/base2
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
        set("short", "密窖");
        set("long", @LONG
这里伸手不见五指，只能听到唏唏嗦唢爬虫蠕动的声音。
LONG
        );
        set("exits", ([ 
	    "south" : __DIR__"base1",
        ]));
        set("objects", ([ 
	    __DIR__"npc/snake" : 2,
		"/d/foshan/npc/zsnake" : 1,
         ]) );
        replace_program(ROOM);
	set("cost", 0);
        setup();
}

