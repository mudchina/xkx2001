//Cracked by Roath
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "石窟");
  set ("long", @LONG
这是敦煌石窟中的一个洞窟，墙上是一幅幅作於五代时期的壁画，
所画受西域画匠影响，都是淡彩托底，再以金、红、银等色勾画主体。
画中内容多是佛经故事，如割肉喂鹰，白象入肋。
LONG);

  set("exits", ([ 
  "west" : __DIR__"dtongdao3",
]));
  set("objects", ([
                "/d/emei/obj/yugajing2" : 1,
                "/d/qilian/obj/fojing3" : 1,
                "/d/shaolin/obj/fojing20" : 1,
        ]));
	set("cost", 2);
  setup();
  replace_program(ROOM);
}

