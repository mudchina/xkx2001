// xiaohun.c 黯然消魂
// By liu 15/07/01

/*
。    杨过心知今日已然无幸，非但救不了郭襄，连自己这条性命也要赔在台
上，凄然向小龙女望了一眼，叫道：“龙儿，别了，别了，你自己保重。”便
在此时，法王铁轮砸向他的脑门。杨过心下万念俱灰，没精打采的挥袖卷出，
拍出一掌，只听得噗的一声，这一掌正好击在法王肩头。
    忽听得台下周伯通大声叫道：“好一招‘拖泥带水’啊！”杨过一怔，这
才醒觉，原来自己明知要死，失魂落魄，随手一招，恰好使出了“黯然销魂掌”
中的“拖泥带水”。这套掌法心使臂、臂使掌，全由心意主宰。那日在万花谷
中，周伯通只因无此心情，虽然武术精博，终是领悟不到其中的妙境。杨过既
和小龙女重逢，这路掌法便已失却神效，直到此刻生死关头，心中想到便要和
小龙女永诀，哀痛欲绝之际，这“黯然销魂掌”的大威力才又不知不觉的生了
出来。
    法王本已稳操胜券，突然间肩头中掌，身子一晃，惊怒交集，立即和身扑
上。杨过退步避开，跟着“魂不守舍”、“倒行逆施”、“若有所失”，连出
三招，跟着是一招“行尸走肉”，踢出一脚。这一脚发出时恍恍惚惚，隐隐约
约，若有若无，法王那里避得过了？砰的一响，正中胸口。法王大叫一声，一
口鲜血喷出，翻下高台。

书中的描述比较简略，就用liu的描述吧：）
*/

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int damage;
	object weapon,ob;
	int skill, jiali, my_rate, your_rate;

	skill = me->query_skill("xiaohun-zhang",1);
	jiali=(int)me->query("jiali");
	weapon = me->query_temp("weapon");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「黯然消魂」只能在战斗中使用。\n");

	if(me->query("spouse/id"))
		return notify_fail("你有娇妻陪伴左右，终是领悟不到「黯然消魂」其中的妙境。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「黯然消魂」只能空手使用。\n");

	if( (int)me->query_skill("yunu-xinjing", 1) < 150 )
		return notify_fail("你的玉女心经修为不够，不会使用「黯然消魂」。\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return notify_fail("你所用的并非玉女心经，使不出「黯然消魂」！\n");

	if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力不够！\n");

	if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("xiaohun-zhang",1) < 150 )
                return notify_fail("你的黯然消魂掌火候不够，无法使用「黯然消魂」！\n");

	if( jiali < 50 )
	 return notify_fail("「黯然消魂」的威力全系于个人内力，你掌上不带内力怎能使出？\n");

	if(me->query("married_times"))
        msg = CYN "\n$N深深思念自己的妻子，哀痛欲绝之际不禁潸然泪下。\n" NOR;
	if(!me->query("married_times"))
        msg = CYN "\n$N深深思念自己的爱人，渐渐心若止水。\n" NOR;

	msg += WHT "$N大喝一声：“黯然消魂掌”！所有的悲愤与哀怨随掌劲倾泻而出，顿时天地间一片苦涩！\n"NOR;

	damage = random( me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
	if( me->query("eff_qi",1) < me->query("max_qi",1)/2 )
	damage = damage * 2;
	if( me->query("eff_qi",1) < me->query("max_qi",1)*2/3 )
	damage = damage * 2 / 3;

	if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/2 ) || !living(target) )
	{
/*
		damage = random( me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
		if( me->query("eff_qi",1) < me->query("max_qi",1)/2 )
		damage = damage * 2;
		if( me->query("eff_qi",1) < me->query("max_qi",1)*2/3 )
		damage = damage * 2 / 3;
*/

		if(damage > 4000) damage = 4000;
		me->add("neili", -jiali*2 - 500 );
		me->add("jingli", -me->query("jiajin")/2);

		target->receive_damage("qi", damage,  me);
		target->receive_wound("qi", random(damage), me);

		msg += HIR"\n$n还在反应之即，猛听得砰然一声大响，正中胸口。\n"NOR;

		msg += NOR;
		me->start_busy(2+random(2));
	}
	else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
				&&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )

	{

		damage = damage / 2;

		if(damage > 2500) damage = 2500;

		me->add("neili", -jiali*2  - 500);
		me->add("jingli", -me->query("jiajin")/2);

		target->receive_damage("qi", damage,  me);
		target->receive_wound("qi", random(damage), me);

		msg += HIR"\n$n连忙发力抵抗，哪知此招蕴藏着无尽的悲怨，「砰」一声$n被震出数丈。\n"NOR;

		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
	}
	else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) 
		&& random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
	{
		damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
		damage = damage / 3;

		if(damage < 1000) damage = 1000;

		me->add("neili", -jiali*2  - 500);
		me->add("jingli", -me->query("jiajin")/2);

		target->receive_damage("qi", damage,  me);
		target->receive_wound("qi", random(damage), me);

		msg += HIR"\n$p知道此掌不可招架，身行刚转，只觉得后心一震！\n"NOR;

		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else {
	 msg += HIG"\n$n知道此掌不可招架，身行一转，逃出了$N的攻击范围。\n\n"NOR;
	 me->add("neili", -jiali*2 );
	 me->add("jingli", -me->query("jiajin") );
	 me->start_busy(2 + random(2));
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}

