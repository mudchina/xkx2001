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
		"east" : __DIR__"maze24",
//		"south" : __DIR__"",
		"west" : __DIR__"maze15",
		"north" : __DIR__"maze41",
	]));

	set("item_desc", ([
	"shibei" : "
　　临：元，亨，利，贞。 至于八月有凶。
　　初九：咸临，贞吉。
　　九二：咸临，吉无不利。
　　六三：甘临，无攸利。 既忧之，无咎。
　　六四：至临，无咎。
　　六五：知临，大君之宜，吉。
　　上六：敦临，吉无咎。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 19);
	check_count(me, 19);
	return;
}
