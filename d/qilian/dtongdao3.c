//Cracked by Roath
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "甬道");
  set ("long", @LONG
这是用来贯穿众石窟的通道，两面石壁上刻有各式浮雕和凹凸笔法
的彩图。
LONG);

  set("exits", ([ 
  "east" : __DIR__"shiku7",
  "west" : __DIR__"shiku6",
  "up" : __DIR__"dtongdao4",
  "down" : __DIR__"dtongdao2",
]));

	set("cost", 1);
  setup();
  replace_program(ROOM);
}

