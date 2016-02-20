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
		"east" : __DIR__"maze30",
		"south" : __DIR__"maze40",
		"west" : __DIR__"maze50",
		"north" : __DIR__"maze47",
	]));

	set("item_desc", ([
	"shibei" : "
　　未济：亨，小狐汔济，濡其尾，无攸利。
　　初六：濡其尾，吝。
　　九二：曳其轮，贞吉。
　　六三：未济，征凶，利涉大川。
　　九四：贞吉，悔亡，震用伐鬼方，三年有赏于大国。
　　六五：贞吉，无悔，君子之光，有孚，吉。
　　上九：有孚于饮酒，无咎，濡其首，有孚失是。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 64);
	check_count(me, 64);
	return;
}
