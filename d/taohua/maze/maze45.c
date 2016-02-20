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
		"east" : __DIR__"maze31",
		"south" : __DIR__"maze35",
		"west" : __DIR__"maze43",
		"north" : __DIR__"maze12",
	]));

	set("item_desc", ([
	"shibei" : "
　　萃：亨。 王假有庙，利见大人，亨，利贞。 用大牲吉，利有攸往。
　　初六：有孚不终，乃乱乃萃，若号一握为笑，勿恤，往无咎。
　　六二：引吉，无咎，孚乃利用□①。
　　六三：萃如，嗟如，无攸利，往无咎，小吝。
　　九四：大吉，无咎。
　　九五：萃有位，无咎。 匪孚，元永贞，悔亡。
　　上六：□②咨涕□③，无咎。
□① ＝ 礻 ＋ 龠
□② ＝ 繁体字 齐 下半部 丿和丨 间夹一贝字
□③ ＝ 氵 ＋ 夷
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 45);
	check_count(me, 45);
	return;
}
