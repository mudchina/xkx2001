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
//		"east" : __DIR__"",
		"south" : __DIR__"maze22",
		"west" : __DIR__"maze29",
		"north" : __DIR__"maze37",
	]));

	set("item_desc", ([
	"shibei" : "
　　既济：亨，小利贞，初吉终乱。
　　初九：曳其轮，濡其尾，无咎。
　　六二：妇丧其□①，勿逐，七日得。
　　九三：高宗伐鬼方，三年克之，小人勿用。
　　六四：□②有衣□③，终日戒。
　　九五：东邻杀牛，不如西邻之□④祭，实受其福。
　　上六：濡其首，厉。
□① ＝ 上髟 下弗
□② ＝ 纟 ＋ 需
□③ ＝ 衤 ＋ 如
□④ ＝ 礻 ＋ 龠
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 63);
	check_count(me, 63);
	return;
}
