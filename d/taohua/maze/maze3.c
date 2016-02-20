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
		"east" : __DIR__"maze48",
		"south" : __DIR__"maze27",
		"west" : __DIR__"maze60",
		"north" : __DIR__"maze42",
	]));

	set("item_desc", ([
	"shibei" : "
　　屯：元，亨，利，贞，勿用，有攸往，利建侯。
　　初九：磐桓；利居贞，利建侯。
　　六二：屯如□如，乘马班如。 匪寇婚媾，女子贞不字，十年乃字。
　　六三：既鹿无虞，惟入于林中，君子几不如舍，往吝。
　　六四：乘马班如，求婚媾，无不利。
  　九五：屯其膏，小贞吉，大贞凶。
　　上六：乘马班如，泣血涟如。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 3);
	check_count(me, 3);
	return;
}
