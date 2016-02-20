//Cracked by Roath
// room: /d/xingxiu/btbarn
// Jay 10/18/97

inherit ROOM;

void create()
{
        set("short", "密窖");
        set("long", @LONG
这里伸手不见五指，只能听到唏唏嗦唢爬虫蠕动的声音。
LONG
        );
        set("exits", ([ 
	    "up" : __DIR__"btroom",
	    "north" : __DIR__"btbase1",
        ]));
        set("objects", ([ 
	    __DIR__"npc/snake" : 3,
		"/d/foshan/npc/zsnake" : 2,
         ]) );
        replace_program(ROOM);
	set("cost", 0);
        setup();
}

