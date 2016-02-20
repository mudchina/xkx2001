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
		"east" : __DIR__"maze63",
		"south" : __DIR__"maze4",
		"west" : __DIR__"maze48",
		"north" : __DIR__"maze59",
	]));

	set("item_desc", ([
	"shibei" : "
　　坎：习坎，有孚，维心亨，行有尚。
　　初六：习坎，入于坎□②，凶。
　　九二：坎有险，求小得。
　　六三：来之坎坎，险且枕，入于坎□②，勿用。
　　六四：樽酒簋贰，用缶，纳约自牖，终无咎。
　　九五：坎不盈，只既平，无咎。
 　 上六：用徽□③，置于丛棘，三岁不得，凶。
□② ＝ 上穴 ＋ 下陷 － 阝
□③ ＝ 纟 ＋ 墨
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 29);
	check_count(me, 29);
	return;
}
