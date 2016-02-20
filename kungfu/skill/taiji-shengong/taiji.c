//Cracked by Roath
// taiji.c 「太极心法」
// xQin 3/99

#include <ansi.h>

void remove_effect(object me);

int exert(object me)
{
	object weapon = me->query_temp("weapon");
	string prepare;

	if( !objectp(weapon) && me->query_skill_prepared("cuff") == "taiji-quan"
	&& me->query_skill_mapped("cuff") == "taiji-quan"
	&& me->query_skill_mapped("parry") == "taiji-quan"
	&& me->query_skill_mapped("force") == "taiji-shengong" )
		prepare = "tjq"; // player is using tjq.
	else if( objectp(weapon) && weapon->query("skill_type") == "sword"
	&& me->query_skill_mapped("sword") == "taiji-jian"
	&& me->query_skill_mapped("parry") == "taiji-jian"
	&& me->query_skill_mapped("force") == "taiji-shengong" )
		prepare = "tjj"; // player is using tjj. 
	else
		prepare = "notj";

	if( me->query_temp("taiji") )
		return notify_fail("你已经将太极心法融会入武功之中。\n");

	if( prepare == "notj" )
		return notify_fail("你现在无法将太极心法融会在武功内。\n");

	if( prepare == "tjj" && me->query_skill("taiji-jian", 1) < 300 )
		return notify_fail("你尚未领会到太极剑意。\n");

	if( prepare == "tjq" && me->query_skill("taiji-quan", 1) < 300 )
		return notify_fail("你尚未领会到太极拳旨。\n");

	if( me->query_skill("taiji-shengong", 1) < 300 )
		return notify_fail("你的太极修为尚未登峰造极，无法领悟到其心法。\n");

	if( me->query_skill("taoism", 1) < 280 )
		return notify_fail("你的道学修为尚未豁然贯通，无法领会太极心法。\n");

	if( me->query_int() < 50 )
		return notify_fail("你的悟性太低，无法领会到太极心法。\n");

	if( prepare == "tjj" )
		message_vision("\n$N微微一笑，身子缓缓右转，左手持剑向上提起，剑身横於胸前，"
		"左右双掌掌心相对，如抱圆球。" + weapon->name() + "未出，已然蓄势无穷。\n", me);
	else
		message_vision("\n$N缓缓站起身来，双手下垂，手背向外，手指微舒，两足分开平行，"
		"接着两臂慢慢提起至胸前，左臂半环，掌与面对成阴掌，右掌翻过成阳掌。\n", me);

	me->receive_damage("jing", 500, "精力透支过度死了");
	me->add_temp("taiji", (int)me->query_skill("taiji-shengong", 1)/2);

	call_out("checking", 1, me, prepare);

	return 1;
}

void checking(object me, string prepare)
{
	object weapon = me->query_temp("weapon");
	string tjjzhao, tjqzhao1, tjqzhao2, tjqzhao3;

	tjjzhao = SKILL_D("taiji-jian")->query_skill_name(random(140));
	tjqzhao1 = SKILL_D("taiji-quan")->query_skill_name(random(150));
	tjqzhao2 = SKILL_D("taiji-quan")->query_skill_name(random(150));
	tjqzhao3 = SKILL_D("taiji-quan")->query_skill_name(random(150));

	if( me->query_temp("taiji") < 1 )
	{
		remove_effect(me);
		tell_object(me, "\n你大周天搬运完毕，将内力合于丹田，入窍归元。\n");
		return;
	}
	else if( !living(me) || me->is_ghost() )
	{
		remove_effect(me);
		return;
	}
	else if( prepare == "tjq" && objectp(weapon) )
	{
		remove_effect(me);
		return;
	}
	else if( prepare == "tjj" && (!objectp(weapon) || weapon->query("skill_type") != "sword") )
	{
		if( me->query_temp("taiji_fight") )
			message_vision(CYN "\n$N手中无剑，剑意顿失！\n"NOR, me);
		remove_effect(me);
		return;
	}
	else if( me->query_skill_mapped("force") != "taiji-shengong" )
	{
		remove_effect(me);
		tell_object(me, HIR "\n你忽觉胸口一阵烦恶，原来所用内功与太极心法相逆！\n" NOR);
		me->receive_damage("qi", 1000, "内功走火入魔死了");
		return;
	}
	else if( !me->is_busy() )
	{
		if( me->query_temp("taiji_fight") && !me->is_fighting() )
		{
			remove_effect(me);
			if( prepare == "tjj" )
				message_vision("\n$N使到" + tjjzhao + 
				"，双手同时画圆，复成第五十四式「持剑归原」。\n"NOR, me);
			else
				message_vision("\n$N使到上步" + tjqzhao1 + "，上步" + tjqzhao2 +
				"，" + tjqzhao3 + "而合太极，神定气闲的站在当地。\n"NOR, me);
			return;
		}
		else if( prepare == "tjj" && (me->query_skill_mapped("sword") != "taiji-jian"
		|| me->query_skill_mapped("parry") != "taiji-jian") )
		{
			if( me->query_temp("taiji_fight") )
				message_vision(CYN "\n$N圈转" + weapon->name()+ CYN
				"，突然变招，使出与太极剑意不同的剑法！\n"NOR, me);
			remove_effect(me);
			return;
		}
		else if( prepare == "tjq" && (me->query_skill_prepared("cuff") != "taiji-quan"
		|| me->query_skill_mapped("cuff") != "taiji-quan"
		|| me->query_skill_mapped("parry") != "taiji-quan") )
		{
			if( me->query_temp("taiji_fight") )
				message_vision(CYN 
				"\n$N双手一错，突然使出与太极拳旨相反的招数！\n"NOR, me);
			remove_effect(me);
			return;
		}
	}

	if( !me->query_temp("taiji_fight") )
		me->add_temp("taiji", -1);

	call_out("checking", 1, me, prepare);
} 

void remove_effect(object me)
{
	me->start_busy(1);
	me->delete_temp("taiji");

	if( me->query_temp("taiji_fight") )
		me->delete_temp("taiji_fight");
}
