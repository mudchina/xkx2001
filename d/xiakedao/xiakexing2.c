//Cracked by Roath
// xiakedao/xiakexing2.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "石洞");
        set("long", @LONG
此洞通向第二组石室。洞中水声淙淙，右面恰巧一道山泉流过。
中间四个草书大字深入石壁「飘渺烟云」，两侧均是蓝色帷幔环绕。几
名蓝衣弟子侍立。
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing1",
		"north"   : __DIR__"xkx5",
		"south"   : __DIR__"xkx6",
		"east"   : __DIR__"xkx7",
		"west"   : __DIR__"xkx8",
		"enter"   : __DIR__"xiakexing3",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
