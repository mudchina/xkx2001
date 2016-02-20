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
		"east" : __DIR__"maze50",
		"south" : __DIR__"maze51",
		"west" : __DIR__"maze38",
		"north" : __DIR__"maze17",
	]));

	set("item_desc", ([
	"shibei" : "
  　噬嗑：亨。 利用狱。
　　初九：履校灭趾，无咎。
　　六二：噬肤灭鼻，无咎。
　　六三：噬腊肉，遇毒；小吝，无咎。
　　九四：噬乾□，得金矢，利艰贞，吉。
　　六五：噬乾肉，得黄金，贞厉，无咎。
　　上九：何校灭耳，凶。
□  ＝ 月 ＋ 姊 － 女
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 21);
	check_count(me, 21);
	return;
}
