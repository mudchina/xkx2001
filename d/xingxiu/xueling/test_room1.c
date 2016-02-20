//Cracked by Roath
inherit ROOM;
#include <ansi.h>
#include "battlefield.h"

void create()
{
  set("short", HIG"比武场"NOR);
  set("long", @LONG
这里就是比武场了，各路英雄们正大打出手，祝你好运！
当你杀死一个玩家后不要望了将其结果 (finish)，踢出比武场。
LONG
  );

  set("exits", ([
		 "north" : __DIR__"bf1",
		 "out" : __DIR__"exit1",
		 ]));
  // must have this line
  createRoom();
  setup();
}

void init()
{
  // must have this line
  initRoom();
  add_action("do_jump", "jump");
}

int do_jump(string arg)
{
  if (!arg || arg!="out")
	return notify_fail("你要往哪儿跳？\n");
  message_vision("$N纵身一跃，从比武场跳了出去．\n", this_player());
  this_player()->move("/d/xingxiu/xueling/exit1");

  message_vision("$N从比武场里跳了出来．\n", this_player());
  return 1;
}

int valid_leave(object who, string dir)
{
  if (!wizardp(who) && dir == "out") 
    return notify_fail("你要是真想出去就 jump out\n");
  return ::valid_leave(who, dir);
}

