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
		"east" : __DIR__"maze15",
//		"south" : __DIR__"",
		"west" : __DIR__"maze11",
		"north" : __DIR__"maze23",
	]));

	set("item_desc", ([
	"shibei" : "
　　坤：元，亨，利牝马之贞。 君子有攸往，先迷后得主，利西南得朋，
      东北丧朋。 安贞，吉。
　　初六：履霜，坚冰至。
　　六二：直，方，大，不习无不利。
　　六三：含章可贞。 或从王事，无成有终。
　　六四：括囊；无咎，无誉。
　　六五：黄裳，元吉。
　　上六：战龙於野，其血玄黄。
　　用六：利永贞。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 2);
	check_count(me, 2);
	return;
}
