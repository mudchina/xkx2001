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
		"east" : __DIR__"maze47",
		"south" : __DIR__"maze50",
		"west" : __DIR__"maze17",
		"north" : __DIR__"maze44",
	]));

	set("item_desc", ([
	"shibei" : "
  　大过：栋桡，利有攸往，亨。
　　初六：藉用白茅，无咎。
　　九二：枯杨生□，老夫得其女妻，无不利。
　　九三：栋桡，凶。
　　九四：栋隆，吉；有它吝。
　　九五：枯杨生华，老妇得士夫，无咎无誉。
　　上六：过涉灭顶，凶，无咎。
□② ＝ 禾 ＋ 弟
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 28);
	check_count(me, 28);
	return;
}
