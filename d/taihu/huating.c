//Cracked by Roath
//Kane

#include "/d/taihu/guiyun.h"
inherit ROOM;

void create()
{
	set("short", "花厅");
	set("long", @LONG
这是一间四方型的厅亭，没有牌匾，正面两方木柱，柱上挂了
幅缺了半阙的『诗词』(poem)。厅内摆设了几张桌椅。一个丫环正
在抹拭桌面。
LONG
	);

	set("item_desc", ([
	"poem" : "\n
      ┌─┐             ┌─┐
      │兵│             │  │
      │火│             │  │
      │有│             │  │
      │馀│             │  │
      │烬│             │  │
      │贫│             │  │
      │村│             │  │
      │才│             │  │
      │数│             │  │
      │家│             │  │
      └─┘             └─┘

\n",
	]));

	set("exits", ([
		"east" : __DIR__"nanfang",
		"south" : __DIR__"dating",
		"west" : __DIR__"nvfang",
		"north" : __DIR__"huayuan",
	]));
	set("cost", 1);
	set("objects", ([
		"/d/taihu/npc/xiaolan" : 1,
	]));

	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "桃花岛") && dir != "south" ) {
	if ( (!myfam || myfam["family_name"] != "桃花岛") && dir != "north" )
	   return notify_fail("归云庄不留外客，你不能住在这里！\n");
    }

    if ( me->query("gender") == "男性" && dir == "west" && present("xiao lan", environment(me)))
	return notify_fail("小兰大声叫道：大色狼！看清楚点，男弟子休息室在东边！\n");

    if ( me->query("gender") == "女性" && dir == "east" && present("xiao lan", environment(me)))
	message_vision("小兰似笑非笑的说道：这位"+RANK_D->query_respect(me)+"赶快进去吧，这儿有我帮你看着。\n", me);

    if ( me->query("gender") == "无性" && (dir=="east" || dir=="west") && present("xiao lan", environment(me)))
	return notify_fail("小兰轻蔑地一撇嘴，说道：公公不能住在这里！\n");

    return ::valid_leave(me, dir);
}
