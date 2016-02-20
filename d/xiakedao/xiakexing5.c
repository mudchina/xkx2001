//Cracked by Roath
// xiakedao/xiakexing5.c
// modified  by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "石洞");
        set("long", @LONG
进洞便觉脚下有些不同，原来特意垫了半尺厚的黄土，不知有什
麽妙用。正面也是刻着这四句的总纲：「落花残阳」，却是笔致圆润，
似出女子之手。周围帘幕低垂，一色淡黄。
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing4",
		"north"   : __DIR__"xkx17",
		"south"   : __DIR__"xkx18",
		"east"   : __DIR__"xkx19",
		"west"   : __DIR__"xkx20",
		"enter" : __DIR__"xiakexing6",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
