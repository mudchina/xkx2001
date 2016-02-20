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
		"east" : __DIR__"maze61",
		"south" : __DIR__"maze39",
		"west" : __DIR__"maze20",
		"north" : __DIR__"maze62",
	]));

	set("item_desc", ([
	"shibei" : "
　　渐：女归吉，利贞。
　　初六：鸿渐于干，小子厉，有言，无咎。
　　六二：鸿渐于磐，饮食□□，吉。
　　九三：鸿渐于陆，夫征不复，妇孕不育，凶；利御寇。
　　六四：鸿渐于木，或得其桷，无咎。
　　九五：鸿渐于陵，妇三岁不孕，终莫之胜，吉。
　　上九：鸿渐于逵，其羽可用为仪，吉。
□  ＝ 彳 ＋ 干 ＋ 亍
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 53);
	check_count(me, 53);
	return;
}
