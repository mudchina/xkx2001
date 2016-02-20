//Cracked by Roath
// xiakedao/xiakexing4.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "石洞");
        set("long", @LONG
此洞气氛却又大不相同，却似来到火焰山一般。只见一色红布帷
幔，八支粗大的红烛分列四角。一旁站立的是虬髯大汉，各佩弯刀，
刀柄上红樱低垂。正中大字是雄健的魏碑体：「烈焰豪情」。
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing3",
		"north"   : __DIR__"xkx13",
		"south"   : __DIR__"xkx14",
		"east"   : __DIR__"xkx15",
		"west"   : __DIR__"xkx16",
		"enter"   : __DIR__"xiakexing5",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
