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
		"east" : __DIR__"maze62",
		"south" : __DIR__"maze20",
		"west" : __DIR__"maze34",
		"north" : __DIR__"maze35",
	]));

	set("item_desc", ([
	"shibei" : "
　　豫：利建侯行师。
　　初六：鸣豫，凶。
　　六二：介于石，不终日，贞吉。
　　六三：盱豫，悔。 迟有悔。
　　九四：由豫，大有得。勿疑。 朋盍簪。
　　六五：贞疾，恒不死。
　　上六：冥豫，成有渝，无咎。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 16);
	check_count(me, 16);
	return;
}
