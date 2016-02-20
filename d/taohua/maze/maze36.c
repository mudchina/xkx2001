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
//		"south" : __DIR__"",
		"west" : __DIR__"maze7",
		"north" : __DIR__"maze22",
	]));

	set("item_desc", ([
	"shibei" : "
　　明夷：利艰贞。
　　初九：明夷于飞，垂其翼。 君子于行，三日不食， 有攸往，主人有
          言。
　　六二：明夷，夷于左股，用拯马壮，吉。
　　九三：明夷于南狩，得其大首，不可疾贞。
　　六四：入于左腹，获明夷之心，出于门庭。
　　六五：箕子之明夷，利贞。
　　上六：不明晦，初登于天，后入于地。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 36);
	check_count(me, 36);
	return;
}
