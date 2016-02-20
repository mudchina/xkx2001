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
		"east" : __DIR__"maze25",
		"south" : __DIR__"maze58",
		"west" : __DIR__"maze33",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
　　履：履虎尾，不□①人，亨。
　　初九：素履，往无咎。
　　九二：履道坦坦，幽人贞吉。
　　六三：眇能视，跛能履，履虎尾，□①人，凶。 武人为于大君。
　　九四：履虎尾，□②□②终吉。
　　九五：□③履，贞厉。
　　上九：视履考祥，其旋元吉。
□①  ＝ 口 ＋ 至
□② ＝ 上朔 ＋ 下心
□③  ＝ 炔 － 火 
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 10);
	check_count(me, 10);
	return;
}
