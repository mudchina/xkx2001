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
		"east" : __DIR__"maze17",
		"south" : __DIR__"maze38",
		"west" : __DIR__"maze31",
		"north" : __DIR__"maze10",
	]));

	set("item_desc", ([
	"shibei" : "
　　兑：亨，利贞。
　　初九：和兑，吉。
　　九二：孚兑，吉，悔亡。
　　六三：来兑，凶。
　　九四：商兑，未宁，介疾有喜。
　　九五：孚于剥，有厉。
　　上六：引兑。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 58);
	check_count(me, 58);
	return;
}
