//Cracked by Roath
// xiakedao/xiakexing3.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "石洞");
        set("long", @LONG
迎面可见四个行书大字「水银泻地」，极具神韵。洞中陈设奢华，
洁白的大理石砖，汉白玉栏杆。几个香炉烟雾缭绕，白衣婢女垂手侍
立，依稀是豪门内宅一般。
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing2",
		"north"   : __DIR__"xkx9",
		"south"   : __DIR__"xkx10",
		"east"   : __DIR__"xkx11",
		"west"   : __DIR__"xkx12",
		"enter"   : __DIR__"xiakexing4",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
