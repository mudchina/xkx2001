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
		"east" : __DIR__"maze12",
		"south" : __DIR__"maze43",
//		"west" : __DIR__"",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
　　乾：元，亨，利，贞。

　　初九：潜龙，勿用。
　　九二：见龙再田，利见大人。
　　九三：君子终日乾乾，夕惕若，厉无咎。
　　九四：或跃在渊，无咎。
　　九五：飞龙在天，利见大人。
　　上九：亢龙有悔。
　　用九：见群龙无首，吉。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();

	me->add_temp("taohua/count",1);
	check_count(me,1);
	return;
}
