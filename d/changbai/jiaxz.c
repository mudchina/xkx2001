//Cracked by Roath
// Room: jiaxz.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "夹心子");
	set("long", @LONG
这里是两山之间的一个山坳，平常大风吹不到此处，因此这里相对暖和
一点。在向阳坡高大的树木中间，生长着一片片紫红色的金达莱花，在皑皑
白雪和淡淡的雾气中，显得更加绚丽多姿。
LONG	);
	set("exits", ([ 
              "westup" : __DIR__"heifk",
              "southup" : __DIR__"erld",
        ]));

        set("objects",([
		__DIR__"npc/cb_xiong" : 1,
	]));
	
        set("outdoors", "changbai");
        set("cost", 4);

        set("count", random(3)+1);

	setup();
}
