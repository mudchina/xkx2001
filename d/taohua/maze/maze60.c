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
		"east" : __DIR__"maze3",
		"south" : __DIR__"maze41",
		"west" : __DIR__"maze39",
		"north" : __DIR__"maze61",
	]));

	set("item_desc", ([
	"shibei" : "
　　节：亨。 苦节不可贞。
　　初九：不出户庭，无咎。
　　九二：不出门庭，凶。
　　六三：不节若，则嗟若，无咎。
　　六四：安节，亨。
　　九五：甘节，吉；往有尚。
　　上六：苦节，贞凶，悔亡。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 60);
	check_count(me, 60);
	return;
}
