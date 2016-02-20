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
		"east" : __DIR__"maze46",
//		"south" : __DIR__"",
		"west" : __DIR__"maze19",
		"north" : __DIR__"maze27",
	]));

	set("item_desc", ([
	"shibei" : "
　　复：亨。 出入无疾，朋来无咎。 反复其道，七日来复，利有攸往。
　　初九：不复远，无只悔，元吉。
　　六二：休复，吉。
　　六三：频复，厉无咎。
　　六四：中行独复。
　　六五：敦复，无悔。
    上六：迷复，凶，有灾眚。用行师，终有大败，以其国君，凶；至于
          十年，不克征。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 24);
	check_count(me, 24);
	return;
}
