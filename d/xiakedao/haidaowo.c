//Cracked by Roath
// 海盗窝边
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "海盗窝边");
    	set("long", @LONG
这里树木茂盛，不见天日。林中有一个小小的草棚，看上去很是
破烂，偶尔从中传出一两声呻吟，似乎有人在里边。
LONG
    	);

    	set("exits", ([
		       "north" : __DIR__"yelin",
		       "enter" : __DIR__"haidaowo1",
		       ]));
    	set("outdoors", "xiakedao");
    	setup();
}


