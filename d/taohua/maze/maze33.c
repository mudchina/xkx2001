//Cracked by Roath
// Room: 
// Date: 

inherit ROOM;

#include "/d/taohua/maze/maze.h"


void create()
{
	set("short", "石阵");
	set("long", @LONG
这是一座由约莫两人多高的大石块构成的乱石阵，规模似乎不大，
但抬眼望去，四周尽是重重叠叠的嶙峋怪石，完全看不出有路通向石阵
之外，加之阵中常年雾气弥漫，更让人摸不清头绪。石块下有一块斜倒
的石碑(shibei)，半埋在浮土中。
LONG
	);

	set("exits", ([
		"east" : __DIR__"maze10",
		"south" : __DIR__"maze31",
		"west" : __DIR__"maze12",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
　　□：亨，小利贞。
　　初六：□尾，厉，勿用有攸往。
　　六二：执之用黄牛之革，莫之胜说。
　　九三：系□，有疾厉，畜臣妾吉。
　　九四：好□君子吉，小人否。
　　九五：嘉□，贞吉。
　　上九：肥□，无不利。
□ ＝  辶 ＋ 丶 ＋ 豚 
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 33);
	check_count(me, 33);
	return;
}
