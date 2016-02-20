//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
#include "room.h"

inherit ROOM;
string long_desc();
int look_mist();

void create()
{
	set("short", "蛇谷");
	set("long", (: long_desc :));

	set("exits", ([ 
	    "south" : __DIR__"road5",
	    "northdown" : __DIR__"shegu2",
	]));

	set("item_desc", ([
	"mist" : (: look_mist :),
	"雾" : (: look_mist :),
	"红雾" : (: look_mist :),
	]));

	set("defense", 1);
	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

string long_desc()
{
	string desc;

	if( query("defense") )
	desc  = "蛇谷是白驼山中最险恶的密境，栖息了无数毒蛇，因而得名。此\n"
		"处便是进入白驼山蛇谷的要冲，巨大而狭长的山口，便像是张大了的\n"
		"蛇口。谷前十数丈内的土地寸草不生，土里冒出阵阵红雾(mist)，弥\n"
		"漫整个谷口，气氛相当诡异。山谷的外围却是碧草如茵，偶尔有些胆\n"
		"大的牧民在此放牧。谷底是一条人马踩出来的小道。\n";
	else 
	desc  = "蛇谷是白驼山中最险恶的密境，栖息了无数毒蛇，因而得名。此\n"
		"处便是进入白驼山蛇谷的要冲，巨大而狭长的山口，便像是张大了的\n"
		"蛇口。谷前十数丈内的土地寸草不生，山谷的外围却是碧草如茵，偶\n"
		"尔有些胆大的牧民在此放牧。谷底是一条人马踩出来的小道。\n";

	return desc;
}

string look_mist()
{
	string desc;
	if( query("defense") ) {
		desc =  RED"一片血红色的雾气，不断从土里腾腾冒出，瑰丽之中，又显得十分诡谲。\n"NOR;
		if( this_player()->query("family/family_name") == "白驼山" ) 
		desc += "白驼山庄在地下建有密窖，欧阳锋将蛇场中的剧毒蛇种养在窖中，\n"
			"利用群蛇呼出的毒气做为屏障，以防外敌闯入蛇谷，毁了他捕蛇修炼的重地。\n";
		return desc;
	}
	else return "本来弥漫谷口的红雾，现在完全消失了。\n";
}

int valid_leave(object me, string dir)
{
	int i, w;

	if (dir == "northdown") {
		if ( !me->query("baituo/shegu_permit") && query("defense") )
			return notify_fail("你看着弥漫谷前的红雾，稍微走近，忽觉腥臭扑鼻，感觉竟有些晕眩。\n看来这是极为厉害的毒雾，难以强行通过。\n");

		if ( me->query("family/family_name") == "白驼山" 
		&& !me->query("baituo/shegu_permit") )
			return notify_fail("你想了一想，觉得未经庄主欧阳锋许可，还是别擅闯蛇谷得好。\n");
		if ( me->query("baituo/shegu_permit") && query("defense") )
		message_vision("$N无视於毒雾，大步走进了蛇谷。\n", me);
	}
	return ::valid_leave(me,dir);
}

void reset()
{
	::reset();
	set("no_clean_up", 1);
}
