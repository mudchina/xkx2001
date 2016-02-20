//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW"白玉峰山脚"NOR);
	set("long", @LONG
这是古城中心，也是白玉山峰(mountain)的山脚下。玉峰近
看尤其美丽，通体雪白，莹光纯净，你抬头仰望，只觉心旷神怡
，万虑俱消，暗暗赞叹造物之奇。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gucheng3",
	]));
	set("item_desc", ([
	"mountain" : "你仰望山峰，忽见山峰上有些斧凿痕迹，似乎是凿出来的踏脚，也许可以从这儿上去。\n",
	]));

	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
}


void init()
{
        add_action("do_jump", "jump");
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	if( !arg || arg=="" ) return notify_fail("你想往哪儿爬？\n");

	if( arg == "up") return notify_fail("山壁上自踏脚处以下，全是一片光滑，祗怕爬不上去，乾脆直接用跳的试试吧。\n");
	else return notify_fail("你不能往这儿爬。\n");
}

int do_jump(string arg)
{
	object me, weapon;
	string msg, type;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="up" )
	{
		if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你正忙着呢。\n");

		if(me->query("rided"))
		return notify_fail("你骑着马，不能这麽干！\n");

		if( me->query_skill("dodge") < 200 ) {
		message_vision("$N纵身而起，想一举攀上白玉峰。\n", me);
		message_vision("不料玉壁太滑，$N一脚踏上了山壁，无法再使得上力，“砰”地一声摔下地来。\n", me);
		me->start_busy(1);
		me->receive_damage("qi", 50+random(20), "攀白玉峰失足摔死了");
		return 1;
		}

		if( !objectp(weapon = me->query_temp("weapon")) ) 
		msg = "$N凝神提气，往峭壁上奔去，上得丈余，掌按玉峰，一借力，再奔上丈余，已到踏脚的所在。\n";
		else {
			type = weapon->query("skill_type");
			if(type == "sword" || type == "sword" || type == "pike" ) 
			msg = "$N凝神提气，往峭壁上奔去，上得丈余，举"+weapon->name()+"戳入玉峰，一借力，再奔上丈余，已到踏脚的所在。\n";
			else msg = "$N凝神提气，往峭壁上奔去，上得丈余，"+weapon->name()+"在玉峰上一击，一借力，再奔上丈余，已到踏脚的所在。\n";
		}
			message_vision(msg, me);

			me->move("/d/xingxiu/baiyufeng");
			message("vision", me->name() + "从山脚纵了上来。\n", 
			environment(me), ({me}) );
			me->start_busy(1);
			return 1;

	}
}	
