//Cracked by Roath
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "石窟");
  set ("long", @LONG
这一窟修得灿烂夺目，壁画色彩丰富，人物众多。描绘的主要是平
民百姓。也有飞天、力士、金刚。
LONG);

  set("exits", ([
  "west" : __DIR__"dtongdao",
]));
	set("cost", 2);
  setup();
   replace_program(ROOM);
}

