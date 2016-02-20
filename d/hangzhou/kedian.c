//Cracked by Roath
#include <ansi.h>
inherit ROOM;

string* Banned_id = ({
	"ufk",
	"none",
});	


void create()
{
	set("short", HIC"天外天客店"NOR);
	set("long", @LONG
这是杭州最有名的客店，里面雕梁画壁，装饰有如宫殿，你可以在这里
打听到各地的风土人情。店小二里里外外忙得团团转，接待着南腔北调的客
人。墙上挂着一个牌子(paizi)。
LONG
	);

//	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));

	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
		"/clone/obj/car" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"road24",
		"up" : __DIR__"kedian2",
	]));

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	string id;
	int i;
	
	if(me == present("xiao er"))
		return ::valid_leave(me, dir);
	
	if(objectp(present("xiao er", environment(me)))) {
		if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

		if ( me->query_temp("rent_paid") && dir == "east" )
		return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");
	}
	
	id = (string)me->query("id");
	for (i = 0; i < sizeof(Banned_id); i++)
	{
	if (id == Banned_id[i])
	{
		me->set("startroom", "/d/death/block");
		me->move("/d/death/block");
		return notify_fail("嘿嘿，看你能跑到哪里去！！\n");
	}
	}

	return ::valid_leave(me, dir);
}
