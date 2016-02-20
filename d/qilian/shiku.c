//Cracked by Roath
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "石窟");
  set ("long", @LONG
莫高窟始建於符秦元二年，后历代均有扩建，有大约四百个石窟。
这里是莫高窟第一层的入口。
LONG);

  set("exits", ([ 
  "eastdown" : __DIR__"drukou",
  "enter" : __DIR__"dtongdao",
]));
	set("cost", 2);
  set("objects", ([
	"/d/xingxiu/npc/yinli" : 1
	]));
  set("no_clean_up", 1);
  setup();
  call_out("reset_flags", 60);
}

void reset_flags() {
    set("no_clean_up", 1);
}
