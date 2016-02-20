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
		"east" : __DIR__"maze55",
		"south" : __DIR__"maze59",
		"west" : __DIR__"maze32",
		"north" : __DIR__"maze64",
	]));

	set("item_desc", ([
	"shibei" : "
　　解：利西南，无所往，其来复吉。 有攸往，夙吉。
　　初六：无咎。
　　九二：田获三狐，得黄矢，贞吉。
　　六三：负且乘，致寇至，贞吝。
　　九四：解而拇，朋至斯孚。
　　六五：君子维有解，吉；有孚于小人。
　　上六：公用射隼，于高墉之上，获之，无不利。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 40);
	check_count(me, 40);
	return;
}
