//Cracked by Roath
// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

int respirating(object me);
int halt_respirate(object me);

int main(object me, string arg)
{
	int respirate_cost;
	object where;

	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (where->query("sleep_room"))
					 return notify_fail("在睡房里不能吐纳，这会影响他人。\n");

	if (where->query("no_fight"))
					 return notify_fail("这里不是吐呐的地方。\n");

	if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能吐纳，会走火入魔。\n");

	if (me->query_temp("cursed", 1))
                return notify_fail("什么？\n");

	if( me->query("rided"))
                return notify_fail("骑在马上吐纳，会走火入魔。\n");

	if( !arg || !sscanf(arg, "%d", respirate_cost))
		return notify_fail("你要花多少精修行？\n");
	if (respirate_cost < 10)
		return notify_fail("你的修为还没有达到那个境界！\n");

	if( (int)me->query("jing") < respirate_cost )
		return notify_fail("你现在精不足，无法修行精力！\n");

	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");

	write("你闭上眼睛开始打坐，全身暖洋洋地甚是舒服。\n");

	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
	message_vision("$N盘膝坐下，开始吐纳炼精。\n", me);
	me->start_busy((: respirating :), (:halt_respirate:));
	return 1;
}

int respirating(object me)
{
	int respirate_cost = (int)me->query_temp("respirate_cost");
	int jingli_gain = 1 + (int)me->query_skill("force",1) / 10;
	if (respirate_cost < 1)
		return 0;
	me->add("jingli", jingli_gain);
	me->set_temp("respirate_cost", respirate_cost -= jingli_gain);

	//me->add("jing", -jingli_gain);
	me->receive_damage("jing", jingli_gain, "吐纳走火入魔死了");

	if (respirate_cost > 0)
		return 1;

	me->set_temp("pending/respirate", 0);
	message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
	if ((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else {
		if ((int)me->query("max_jingli") > (int)me->query_skill("force") * me->query("con") / 2
		 || (int)me->query("eff_jingli") > (int)me->query_skill("force") * me->query("con") / 2) {
			write("你的精力修为似乎已经达到了瓶颈。\n");
			me->set("jingli", (int)me->query("max_jingli"));
			return 0;
		}
		else {
			me->add("eff_jingli", 1);
			me->add("max_jingli", 1);
			me->set("jingli", (int)me->query("max_jingli"));
			write("你的精力增加了！！\n");
			return 0;
		}
	}
}

int halt_respirate(object me)
{
	if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		me->set("jingli", (int)me->query("max_jingli") * 2);
	me->set_temp("pending/respirate", 0);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : respirate|tuna [<耗费「精」的量>]
 
打坐修行，利用「炼精化气，炼气化神，炼神还虚」的方法将你的精
转变成精力。

See also: exercise
HELP
        );
        return 1;
}
