//Cracked by Roath
// xiakedao/xiakexing6.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room"; 

#include <room.h>;

void create()
{
        set("short", "石洞");
        set("long", @LONG
眼前烛光黯淡，四周未见任何装饰，光秃粗糙的石壁上四字小篆，
正是最后一句总纲：「天人归真」，下面又有一行小字(xiaozi)。几
张石桌石凳随意地摆放着，似是杂乱无章，又似内藏玄机。
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing5",
		"north"   : __DIR__"xkx21",
		"south"   : __DIR__"xkx22",
		"east"   : __DIR__"xkx23",
		"west"   : __DIR__"xkx24",
]));
	set("item_desc",([
	    "xiaozi" : "
小字写的是：「昔年余等沉溺无术，惟石公妙悟神功，盖因...」，
后面的字迹已模糊难辨。\n",
	]));

//	create_door("out", "石门", "enter", DOOR_CLOSED);
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}

