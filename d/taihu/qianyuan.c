//Cracked by Roath
//Kane

#include "/d/taihu/guiyun.h"
inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这里是归云庄的前院，相当宽敞。左右靠墙各建有几间低矮的平房，
像是家人的住处。正前方几棵树木，湖中清风吹来，落叶萧萧而下。树木
再往后是一间大厅。
LONG
	);
	set("valid_startroom", 1);
	 set("exits", ([
		"north" : __DIR__"dating",
		"out" : __DIR__"damen",
	]));
	set("cost", 1);
	set("outdoors", "taihu");
	set("objects", ([
		"/d/taihu/npc/jiading" : 2,
	]));

	setup();
	"/clone/board/guiyun_b"->foo();
}
