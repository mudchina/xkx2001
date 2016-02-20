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
		"east" : __DIR__"maze2",
//		"south" : __DIR__"",
//		"west" : __DIR__"",
		"north" : __DIR__"maze26",
	]));

	set("item_desc", ([
	"shibei" : "
　　泰：小往大来，吉亨。
　　初九：拔茅茹，以其夤，征吉。
　　九二：包荒，用冯河，不遐遗，朋亡，得尚于中行。
　　九三：无平不陂，无往不复，艰贞无咎。 勿恤其孚，于食有福。
　　六四：翩翩不富，以其邻，不戒以孚。
　　六五：帝乙归妹，以祉元吉。
　　上六：城复于隍，勿用师。 自邑告命，贞吝。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 11);
	check_count(me, 11);
	return;
}
