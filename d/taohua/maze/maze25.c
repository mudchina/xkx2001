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
		"east" : __DIR__"maze44",
		"south" : __DIR__"maze17",
		"west" : __DIR__"maze10",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
  　无妄：元，亨，利，贞。 其匪正有眚，不利有攸往。
　　初九：无妄，往吉。
　　六二：不耕获，不□畲，则利有攸往。
　　六三：无妄之灾，或系之牛，行人之得，邑人之灾。
　　九四：可贞，无咎。
　　九五：无妄之疾，勿药有喜。
　　上九：无妄，行有眚，无攸利。
□  ＝  上 艹 下甾

\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 25);
	check_count(me, 25);
	return;
}
