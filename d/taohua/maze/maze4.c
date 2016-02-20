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
		"east" : __DIR__"maze22",
		"south" : __DIR__"maze7",
		"west" : __DIR__"maze18",
		"north" : __DIR__"maze29",
	]));

	set("item_desc", ([
	"shibei" : "
　　蒙：亨。 匪我求童蒙，童蒙求我。 初噬告，再三渎，渎则不告。利
　　    贞。
　　初六：发蒙，利用刑人，用说桎梏，以往吝。
　　九二：包蒙吉；纳妇吉；子克家。
　　六三：勿用娶女；见金夫，不有躬，无攸利。
　　六四：困蒙，吝。
　　六五：童蒙，吉。
　　上九：击蒙；不利为寇，利御寇。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 4);
	check_count(me, 4);
	return;
}
