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
		"east" : __DIR__"maze19",
//		"south" : __DIR__"",
		"west" : __DIR__"maze2",
		"north" : __DIR__"maze52",
	]));

	set("item_desc", ([
	"shibei" : "
　　谦：亨，君子有终。
　　初六：谦谦君子，用涉大川，吉。
　　六二：鸣谦，贞吉。
　　九三：劳谦君子，有终吉。
　　六四：无不利，□②谦。
　　六五：不富，以其邻，利用侵伐，无不利。
　　上六：鸣谦，利用行师，征邑国。
□②  ＝ 扌＋为
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 15);
	check_count(me, 15);
	return;
}
