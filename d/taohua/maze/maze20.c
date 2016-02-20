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
		"east" : __DIR__"maze53",
		"south" : __DIR__"maze8",
		"west" : __DIR__"maze9",
		"north" : __DIR__"maze16",
	]));

	set("item_desc", ([
	"shibei" : "
　　观：盥而不荐，有孚□若。
　　初六：童观，小人无咎，君子吝。
　　六二：窥观，利女贞。
　　六三：观我生，进退。
　　六四：观国之光，利用宾于王。
　　九五：观我生，君子无咎。
　　上九：观其生，君子无咎。
□  ＝ 禺 ＋ 页
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 20);
	check_count(me, 20);
	return;
}
