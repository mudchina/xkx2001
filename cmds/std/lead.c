//Cracked by Roath
//lead.c 带领
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object victim;
	string comm;

		  if (!arg) return notify_fail("你要让谁跟着你走？\n");

		  if ( arg == me->query("id") ) return notify_fail("你要自己跟着自己，疯啦？\n");

	victim = present(arg, environment(me));
		  if (!victim) return notify_fail("这里并无此人！\n");
		  if (!living(victim)) return notify_fail("这不是活物！\n");

	 if (victim->query("no_get", 1))
					 return notify_fail("这个人领不走！\n");

	if ( !me->query("env/invisibility") ){

	if ( !userp(victim) && victim->query("sjsz/team_name") && victim->query("sjsz/team_name") == me->query("sjsz/team_name") ){
		message_vision("\n$N对著$n说道：跟着我走吧，我带你去个地方。\n",me, victim);
		message_vision("$N看了看$n，痛快地说道：好吧！\n\n",victim, me, );
		victim->set_leader(me);
		return 1;
	}

    if( victim->query_condition("xs_necromancy") < 0 || !victim->query_temp("block_msg/all", 1) 
                || (me->query("id") != victim->query("xueshan/necromancy_singer")) ) {
//	if ( !victim->query_temp("cursed", 1) || !victim->query_temp("block_msg/all", 1)){
	message_vision("\n$N对著$n说道：跟着我走吧，我带你去个地方。\n\n",me, victim);
	tell_object(victim, YEL "如果你愿意跟着" + me->query("name") +"走，请你键入 follow " + me->query("id") +"的指令。\n" NOR);
					 write(YEL "你必须等对方同意才能领着对方走。\n" NOR);
					 return 1;
	}
	if (me->query_skill("necromancy", 1) < 45)
		return notify_fail("你的降伏法火候不够！\n");

	message_vision(HIR "$N诡笑中伸手向$n一招。\n" NOR, me, victim);
	tell_object(victim,"你迷迷糊糊中觉得"+me->name()+"是你的主人，须得跟随他！\n");

	victim->set_leader(me);
	return 1;
	}
}
