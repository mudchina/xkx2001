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
		"east" : __DIR__"maze20",
		"south" : __DIR__"maze5",
//		"west" : __DIR__"",
		"north" : __DIR__"maze34",
	]));

	set("item_desc", ([
	"shibei" : "
　　小畜：亨。 密云不雨，自我西郊。
　　初九：复自道，何其咎，吉。
　　九二：牵复，吉。
　　九三：舆说辐，夫妻反目。
　　六四：有孚，血去惕出，无咎。
　　九五：有孚挛如，富以其邻。
　　上九：既雨既处，尚德载，妇贞厉。 月几望，君子征凶。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 9);
	check_count(me, 9);
	return;
}
