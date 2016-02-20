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
		"east" : __DIR__"maze7",
//		"south" : __DIR__"",
		"west" : __DIR__"maze24",
		"north" : __DIR__"maze18",
	]));

	set("item_desc", ([
	"shibei" : "
　　升：元亨，用见大人，勿恤，南征吉。
　　初六：允升，大吉。
　　九二：孚乃利用□，无咎。
　　九三：升虚邑。
　　六四：王用亨于岐山，吉无咎。
　　六五：贞吉，升阶。
　　上六：冥升，利于不息之贞。
□  ＝ 礻 ＋ 龠
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 46);
	check_count(me, 46);
	return;
}
