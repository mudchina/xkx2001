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
		"east" : __DIR__"maze27",
		"south" : __DIR__"maze19",
		"west" : __DIR__"maze52",
		"north" : __DIR__"maze60",
	]));

	set("item_desc", ([
	"shibei" : "
　　损：有孚，元吉，无咎，可贞，利有攸往？  曷之用，二簋可用享。
　　初九：已事遄往，无咎，酌损之。
　　九二：利贞，征凶，弗损益之。
　　六三：三人行，则损一人；一人行，则得其友。
　　六四：损其疾，使遄有喜，无咎。
　　六五：或益之，十朋之龟弗克违，元吉。
　　上九：弗损益之，无咎，贞吉，利有攸往，得臣无家。
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 41);
	check_count(me, 41);
	return;
}
