//Cracked by Roath
// tianshan: /d/xingxiu/shanjiao.c
// Jay 3/17/96
// Modified by qfy August 24, 1996.
// Ryu 5/10/1997

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "天山脚下");
	set("long", @LONG
北面就是边陲重镇伊犁了。但见城郭之外，巍峨的天山，直插云天，
气势雄伟；茫茫沃野，阡陌相连，一片葱翠，奔腾的伊犁河，宛如一条
银色的缎带，曲折萦回。河畔，城郊，水蕖纵横，林带成网。一道天山
将西域分为两半。北疆是西域各族的聚居区，南疆是无边的塔克拉马干
大沙漠。
LONG
	);
	set("exits", ([
	    "west" : __DIR__"tianroad1",
	    "north" : __DIR__"nanmen",
	    "southwest" : __DIR__"nanjiang",
	    "southeast" : __DIR__"silk4",
]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiuhai" );
	set("objects", ([
	__DIR__"npc/hasake" : 1,
	    __DIR__"npc/trader" : 1]));

	set("cost", 2);
	setup();
//      replace_program(ROOM);
}

void init()
{
	object ob, robber, *inv, me=this_player();
	int i, j=0;

	inv = all_inventory(me);

	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("value") >= 10000 
		&& !inv[i]->query("money_id")) j++;
	}
	
	if (me->query("family/family_name")!="星宿派" && j>0)
	me->set_temp("rob_victim", 1);

	if ( interactive(ob=this_player()) && ob->query_temp("biao/bayi")
	&& present("hong biao", ob) && random(3)==1 
	|| me->query_temp("rob_victim") && random(5)==1) {
		message_vision(HIR"「慢着！」，一个星宿派弟子走了出来，拦住了$N。\n"NOR, ob);
		robber = new(__DIR__"npc/xxdizi");
		robber->move(environment(ob));
	}
}

int valid_leave(object me, string dir)
{
    int current_water;

    if ( me->query_temp("biao/bayi") && present("xingxiu dizi", environment(me)) 
	|| me->query_temp("rob_victim") && present("xingxiu dizi", environment(me)))
	return notify_fail("星宿派弟子恶狠狠地威胁道：快将宝贝交出来，否则取你狗命！\n");
	
    if (dir == "southwest") {

	if (!userp(me)) return 0;
	current_water = me->query("water");
	if (current_water==0) {
	}

	if (current_water>0 && current_water<20) {
	    me->set("water",0);
	}

	if (current_water>20) {
	    me->set("water",current_water-20);
	}
	return ::valid_leave(me, dir);
    }
	else { me->delete_temp("rob_victim"); }
	return ::valid_leave(me, dir);

}
