//Cracked by Roath
// Room: // Date: 

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "石阵入口");
	set("long",@LONG
这是一片空阔的砂石滩，南边有一个小小的港湾，北边似乎是
一座乱石阵，但是一股薄雾常年笼罩着石阵，使人看不真切阵中究
竟。通入阵中的唯一小路又被一块大石碑(shibei)挡住。
LONG
	);

	set("exits", ([
		"south" : __DIR__"harbor",
	]));

	set("item_desc", ([
	"shibei" : "
石碑表面十分光滑，似乎经常有人用手摩挲，上面有几行字：
天道左旋，地道右旋，数往者顺，知来者逆。
\n",
	]));

	set("cost", 2);
	setup();
}

void init()
{
	 add_action("do_push", "push");
}


int do_push(string arg)
{
  object me = this_player();

  if (!arg || arg != "shibei")
    return notify_fail("什麽？\n");
  
  if ( me->query_str() < 25 && me->query("combat_exp") > 100000) {
    return notify_fail("你没那么大力气搬动石碑。\n");
  }

/*
  if ( (me->query("age") - me->query("taohua_maze")) < me->query("taohua_maze2"))
    return notify_fail("你今年已通过桃花混沌大阵，明年再来吧\n");
*/

  message_vision(HIW"石碑缓缓沉入地面，石阵中涌出一股怪风挟着浓雾向$N卷来！\n$N身影顿时消失在浓雾之中......\n\n\n\n\n"NOR,me);
  if( me->query("taohua_maze") )
	me->move("/d/taohua/maze/zhongshu");
  else
	me->move("/d/taohua/maze/maze"+(random(63)+1));
	
  return 1;
}
