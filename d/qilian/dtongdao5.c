//Cracked by Roath
inherit ROOM;

void create()
{
  set ("short", "甬道");
  set ("long", @LONG
这是一条长长的甬道，两壁上满是彩塑：千佛、飞天、乐妓、
建筑物、花饰。
LONG);
set("exits", ([
  "east" : __DIR__"shiku0",
  "west" : "/d/xingxiu/mogaoku",
  "down" : __DIR__"dtongdao4",
]));
	set("cost", 1);
  setup();
  replace_program(ROOM);
}

