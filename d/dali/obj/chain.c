//Cracked by Roath
// /d/dali/obj/chain.c 铁链 锁捕工具
// mantian may/16/2001

#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_SSERVER;

void create()
{
	set_name("铁链", ({ "tie lian","chain" }) );
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("unit", "条");
		set("value", 1000);
		set("long", "这是一条明晃晃，沉甸甸的铁链。\n");
		set("material", "steel");
	}
	init_whip(10);
	setup();
}

void init()
{
	add_action("do_arrest","arrest");
}

int do_arrest(string arg)
{
	object me=this_player(), weapon, victim, fighter;

	if (!me->query("dali/employee")) return notify_fail("什么？\n");
	if (!arg) return notify_fail("你要锁捕谁？\n");
	if (environment(me)->query("no_fight")) return notify_fail("这里不准战斗。\n");
	if (!objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tie lian") return notify_fail("你拿什么套？\n");
	victim = present(arg,environment(me));
	if (!victim) return notify_fail("这里并无此人！\n");
	if (victim == me) return notify_fail("何必多此一举？\n");
	if (userp(victim)) return notify_fail("你不能锁捕玩家。\n");
	if (!living(victim)) return notify_fail("这不是活物！\n");
	if ((int)me->query_temp("marks/arrestee")) return notify_fail("你上个要抓的人还没抓到，不要多事了！\n");
	if (strsrch(file_name(environment(me)), "/d/dali/") == -1) return notify_fail("这里不是大理境内，轮不到你来多事！\n");
	if ((!victim->is_fighting() && !victim->query_temp("robbing") && !victim->query_temp("rapping"))
		|| victim->query_temp("last_opponent") == me->query("id")
		|| victim->query("family/family_name")=="大理段家"
		|| (me->query("family/family_name") != "大理段家" && !me->query("dali/employee")))
		return notify_fail("人家没在惹事生非，你锁捕不了！\n");
	fighter = offensive_target(victim);
	if (fighter == me) return 0;
	if (!victim->is_killing(fighter->query("id"))) return notify_fail("此人非肇事者。\n");
	if (fighter->query("qi") > victim->query("qi")) return notify_fail("他们只是在切搓武功。\n");
	if (victim->query_temp("robbing")) message_vision(HIW"$N喝道：大胆！竟敢在本官面前行抢！走！见官去！\n"NOR, me);
	else if (victim->query_temp("rapping")) message_vision(HIW"$N喝道：可恶！竟敢在此调戏良家妇女！跟我回去见官！\n"NOR, me);
	else message_vision(HIW"$N高喊一声：大理境内休得撒野！走！跟我见官去！\n"NOR, me);
	victim->remove_all_killer();
	fighter->remove_all_killer();
	victim->start_busy(1);
	victim->set_temp("arrestee", 1);
	me->start_busy(1);
	me->set_temp("marks/arrestee", victim->query("name"));
	victim->kill_ob(me);
	me->fight_ob(victim);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( victim->query("combat_exp",1)>50) return HIY "铁链呛啷啷的往$n的脖子上套了上去。" NOR;
}
