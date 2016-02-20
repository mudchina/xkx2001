//Cracked by Roath
// force.c

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage;

	me->add("force", - factor );
	damage = (int)me->query("force")/20 + factor
		- (int)victim->query("force")/25;

	if( damage < 0 ) {
		if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage;
			me->receive_damage( "qi", damage * 2 );
			me->receive_wound( "qi", damage );
			if( damage < 10 ) return "$N受到$n的内力反震闷哼一声。\n";
			else if( damage < 20 ) return "$N被$n以内力反震「嘿」地一声退了两步。\n";
			else if( damage < 40 ) return "$N被$N以内力一震胸囗有如受到一记重锤连退了五六步ⅵ\n";
			else return "$N被$n的内力一震眼前一黑身子向後飞出丈许\ⅵⅵ\n";
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}
