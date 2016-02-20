//Cracked by Roath
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "石窟");
  set ("long", @LONG
本窟都是供养像。画像内容有王公贵族、地方官吏、乃致贩夫走足、
歌舞妓女，等等不一。画像有八寸至尺许长者、也有大过真身者。
LONG);

  set("exits", ([ 
  "east" : __DIR__"dtongdao2",
]));
	set("cost", 2);
  setup();
  replace_program(ROOM);
}

