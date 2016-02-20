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
		"east" : __DIR__"maze42",
		"south" : __DIR__"maze60",
		"west" : __DIR__"maze53",
		"north" : __DIR__"maze54",
	]));

	set("item_desc", ([
	"shibei" : "
　　中孚：豚鱼吉，利涉大川，利贞。
　　初九：虞吉，有他不燕。
　　九二：鸣鹤在阴，其子和之，我有好爵，吾与尔靡之。
　　六三：得敌，或鼓或罢，或泣或歌。
　　六四：月几望，马匹亡，无咎。
　　九五：有孚挛如，无咎。
　　上九：翰音登于天，贞凶。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 61);
	check_count(me, 61);
	return;
}
