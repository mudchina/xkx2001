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
		"east" : __DIR__"maze49",
		"south" : __DIR__"maze64",
		"west" : __DIR__"maze28",
		"north" : __DIR__"maze6",
	]));

	set("item_desc", ([
	"shibei" : "
　　困：亨，贞，大人吉，无咎，有言不信。
　　初六：臀困于株木，入于幽谷，三岁不见。
　　九二：困于酒食，朱绂方来，利用亨祀，征凶，无咎。
　　六三：困于石，据于蒺藜，入于其宫，不见其妻，凶。
　　九四：来徐徐，困于金车，吝，有终。
　　九五：劓刖，困于赤绂，乃徐有说，利用祭祀。
　　上六：困于葛□①，于□②□③，曰动悔。 有悔，征吉。
□① ＝ 上 艹 ＋ 三个品字形的 田
□② ＝ 臬 ＋ 危 
□③ ＝ 兀 ＋ 危
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 47);
	check_count(me, 47);
	return;
}
