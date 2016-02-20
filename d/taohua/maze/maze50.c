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
		"east" : __DIR__"maze64",
		"south" : __DIR__"maze32",
		"west" : __DIR__"maze21",
		"north" : __DIR__"maze28",
	]));

	set("item_desc", ([
	"shibei" : "
　　鼎：元吉，亨。
　　初六：鼎颠趾，利出否，得妾以其子，无咎。
　　九二：鼎有实，我仇有疾，不我能即，吉。
　　九三：鼎耳革，其行塞，雉膏不食，方雨亏悔，终吉。
　　九四：鼎折足，覆公□，其形渥，凶。
　　六五：鼎黄耳金铉，利贞。
　　上九：鼎玉铉，大吉，无不利。
□  ＝ 饣 ＋ 束  
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 50);
	check_count(me, 50);
	return;
}
