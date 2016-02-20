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
		"east" : __DIR__"maze18",
		"south" : __DIR__"maze24",
		"west" : __DIR__"maze41",
		"north" : __DIR__"maze3",
	]));

	set("item_desc", ([
	"shibei" : "
　　颐：贞吉。 观颐，自求口实。
　　初九：舍尔灵龟，观我朵颐，凶。
　　六二：颠颐，拂经，于丘颐，征凶。
　　六三：拂颐，贞凶，十年勿用，无攸利。
　　六四：颠颐吉，虎视眈眈，其欲逐逐，无咎。
　　六五：拂经，居贞吉，不可涉大川。
 　 上九：由颐，厉吉，利涉大川。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 27);
	check_count(me, 27);
	return;
}
