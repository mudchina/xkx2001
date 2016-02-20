//Cracked by Roath
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "通道");
  set ("long", @LONG
通道是在山腹中开凿出来，贯穿各个石窟。通道的两壁上有合种
题材的壁画和浮雕。这里通向第二层。
LONG);

  set("exits", ([ 
  "out" : __DIR__"dtongdao",
  "west" : __DIR__"shiku4",
  "up" : __DIR__"dtongdao3",
  "east" : __DIR__"shiku5",
]));

	set("cost", 1);
  setup();
  replace_program(ROOM);
}

