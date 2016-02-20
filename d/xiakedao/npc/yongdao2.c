//Cracked by Roath
// xiakedao/yongdao2.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
甬道曲折延伸，依着山腹中天然洞穴穿凿而成。淙淙的流水之声
时隐时现。东面赫然是一道玉石砌成的洞门，门额上刻着「迎宾馆」
三个大字。西边有一个洞(hole)，好象可以钻(zuan)进去。
LONG );

      set("exits", ([
		"north" : __DIR__"yongdao1",
		"south" : __DIR__"yongdao5",
		"east" : __DIR__"yingbin",
      ]));
	set("objects", ([ 
		__DIR__ +"npc/baituo" : 1, 
    	]));
      set("no_clean_up", 1);
    	set("no_fight", "1");
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
void init()
{	add_action("do_kill", "kill");
	add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{	object me = this_player();
	if ( !arg )
		return notify_fail( "你想钻什麽?\n");
	if ( arg != "hole" )
		return notify_fail( "老老实实 zuan hole 吧。\n");
	message_vision("$N一弯腰，往那洞口钻了进去。\n", me);
	write("你在洞里爬了一会儿，突然眼前一亮。\n");
	me->move(__DIR__"shibi");
	message("vision", me->name() + "从洞里钻了出来。\n",environment(me), ({me}) );

	return 1;
}
#include "/d/xiakedao/kill.h"
