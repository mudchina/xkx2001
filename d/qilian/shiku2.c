//Cracked by Roath
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "石窟");
  set ("long", @LONG
这窟中满壁的壁画，由于所绘皆是杀身故事，如舍身喂虎，皆
是阴森凄惨之悲剧，故设色用笔，均极沉着艰毅。往往于石青石绿
之气氛中，加以黑白及土红之对照，显得朴实古拙。 
LONG);

  set("exits", ([ 
  "east" : __DIR__"dtongdao",
]));

	set("cost", 2);
  setup();
   replace_program(ROOM);
}

