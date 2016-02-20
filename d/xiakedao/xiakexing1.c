//Cracked by Roath
// xiakedao/xiakexing1.c
// modifiey by  aln  5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "石洞");
        set("long", @LONG
这里依次是六个石洞，各自通向四个石室。后人研习「侠客行」
武功，悟出六句总纲，也分别刻在这里。此洞一色青布帷幔，侍立的
弟子均是青衣长剑。正面壁上，粗隶刻着前四句诗的总纲「一剑飞鸿」。
LONG );

      set("exits", ([
		"out" : __DIR__"gate",
		"north"   : __DIR__"xkx1",
		"south"   : __DIR__"xkx2",
		"east"   : __DIR__"xkx3",
		"west"   : __DIR__"xkx4",
		"enter" : __DIR__"xiakexing2",
      ]));

	create_door("out", "石门", "enter", DOOR_CLOSED);
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}

