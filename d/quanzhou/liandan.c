//Cracked by Roath
// liandan.c 练胆石
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;
inherit F_SSERVER;

void create()
{
        set("short", "练胆石");
	set("long", @LONG
这是立崖上的一方窄石(stone)， 正处风口。人立其上，但觉狂风撕扯，
面如刀割，头晕目眩，摇摇欲坠。相传这是明朝抗倭英雄俞大猷少年时的练胆
石，上有他题刻的「恩重如山」四个字。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"mituo",
		"eastdown" : __DIR__"shanlu2",
	]));

	set("item_desc",([
            "stone" : "只见窄石耸立在崖上，任狂风暴哮始终不倒，你不禁感叹造物之奇。\n"
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 3);
        setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me = this_player();

	if ( !arg || arg != "stone" ) return 0;

	if ( me->query_temp("marks/climb") ) return notify_fail("你还未从石上下来，着急什么？\n");

	message_vision("$N颤颤惊惊地爬上练胆石，马上被风吹得东摇西摆，随时可能失足！\n", me);

	if ( random((int)me->query_kar()) < 2 ) {
		message_vision("突然间狂风大作，$N一个支持不住，发出一声惨呼失足跌下练胆石！\n", me);
		me->receive_wound( "qi", me->query("max_qi")+100, "被狂风吹落山石跌死了" );
	}
	else if ( random((int)me->query_kar()) < 8 && me->query_skill("dodge") < 30 ) {
		message_vision("突然间狂风大作，$N一个支持不住，发出一声惨呼失足跌下练胆石！\n", me);
		me->unconcious();
	}
	else if ( random((int)me->query_kar()) < 8 ) {
		message_vision("突然间狂风大作，$N被风吹得东摇西摆，随时可能失足跌下！\n", me);
		me->receive_damage( "qi", 50, "被狂风吹落山石跌死了" );
        	me->receive_damage( "jing", 50, "被狂风吹落山石跌死了" );
	}

	if ( living(me) ) {
		me->receive_damage( "qi", 50, "被狂风吹落山石跌死了" );
        	me->receive_damage( "jing", 20, "被狂风吹落山石跌死了" );
	}

	if ( me->query("potential") - me->query("learned_points") < 100 
	&& random(5) == 1 ) me->add("potential", 1);

	call_out("check", 1, me);
	me->set_temp("marks/climb", 1);

	return 1;
}

int check(object me)
{
	if ( !me->is_ghost() && living(me) ) 
		message_vision("$N一会儿便抵受不住，只好小心翼翼地爬了下来。\n", me);
	else message_vision("$N发出一声凄历的惨呼，失足跌下练胆石！\n", me);

	me->delete_temp("marks/climb");

	return 1;
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("marks/climb") ) 
		return notify_fail("你还未从石上下来呢！\n");

	return ::valid_leave(me, dir);
}
	
	
