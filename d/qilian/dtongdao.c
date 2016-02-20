//Cracked by Roath
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "通道");
  set ("long", @LONG
通道是在山腹中开凿出来，贯穿各个石窟。通道的两壁上有各种
题材的壁画和浮雕。
LONG);

  set("exits", ([ 
  "out" : __DIR__"shiku",
  "west" : __DIR__"shiku2",
  "enter" : __DIR__"dtongdao2",
  "east" : __DIR__"shiku3",
]));

	set("cost", 1);
  setup();
  replace_program(ROOM);
}

