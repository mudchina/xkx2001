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
		"east" : __DIR__"maze4",
		"south" : __DIR__"maze46",
		"west" : __DIR__"maze27",
		"north" : __DIR__"maze48",
	]));

	set("item_desc", ([
	"shibei" : "
　　蛊：元亨，利涉大川。 先甲三日，后甲三日。
　　初六：干父之蛊，有子，考无咎，厉终吉。
　　九二：干母之蛊，不可贞。
　　九三：干父小有晦，无大咎。
　　六四：裕父之蛊，往见吝。
　　六五：干父之蛊，用誉。
　　上九：不事王侯，高尚其事。 
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 18);
	check_count(me, 18);
	return;
}
