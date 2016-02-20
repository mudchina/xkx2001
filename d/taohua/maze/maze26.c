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
		"east" : __DIR__"maze23",
		"south" : __DIR__"maze11",
//		"west" : __DIR__"",
		"north" : __DIR__"maze5",
	]));

	set("item_desc", ([
	"shibei" : "
    大畜：利贞，不家食吉，利涉大川。
　　初九：有厉利已。
　　九二：舆说辐。
　　九三：良马逐，利艰贞。 曰闲舆卫，利有攸往。
　　六四：童豕之牿，元吉。
　　六五：□豕之牙，吉。
　　上九：何天之衢，亨。
□  ＝ 豕 ＋ 贲

\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 26);
	check_count(me, 26);
	return;
}
