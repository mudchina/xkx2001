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
		"east" : __DIR__"maze8",
		"south" : __DIR__"maze26",
//		"west" : __DIR__"",
		"north" : __DIR__"maze9",
	]));

	set("item_desc", ([
	"shibei" : "
　　需：有孚，光亨，贞吉。 利涉大川。
　　初九：需于郊。 利用恒，无咎。
　　九二：需于沙。 小有言，终吉。
　　九三：需于泥，致寇至。
　　六四：需于血，出自穴。
　　九五：需于酒食，贞吉。
　　上六：入于穴，有不速之客三人来，敬之终吉。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 5);
	check_count(me, 5);
	return;
}
