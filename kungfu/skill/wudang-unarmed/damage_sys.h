//Cracked by Roath
mixed damage_sys(object me, object victim, string attack_skill, object weapon, mapping action)
{
	mapping my, your;
	string result;
	string force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int damage, damage_bonus, defense_factor;

        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();

	result = "";
	damage = me->query_temp("apply/damage");
	damage = (damage + random(damage)) / 2;

	// increase attack power for npc who doesn't have special skills 
	if( !userp(me) )
		damage += ((int)me->query_temp("apply/attack") + 1) /10 * damage /10;

	// disable action["damage"] temporarily
	// untill we find a consistent damage sys.
	if( action["damage"] )
		damage += action["damage"] /10 * damage / 30;

	damage_bonus = me->query_str();

	// Let force skill take effect.
	if( my["jiali"] && (my["neili"] > my["jiali"]) ) 
	{
		if( force_skill = me->query_skill_mapped("force") )
		{
			foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
			if( stringp(foo) ) result += foo;
			else if( intp(foo) )
			{
				if( !objectp(weapon) ) damage_bonus += foo;
				else                   damage_bonus += foo / 3;
			}
			else if( mapp(foo) )
			{
				result += foo["result"];
				if( !objectp(weapon) ) damage_bonus += foo["damage"];
				else                   damage_bonus += foo["damage"] / 3;
			}
		}
	}

	if( action["force"] )
	{
		if( !objectp(weapon) )
			damage_bonus += action["force"] /10 * damage_bonus / 100;
		else                    
			damage_bonus += action["force"] /10 * damage_bonus / 300;
	}

	// equal skill, equal power
	if( !objectp(weapon) )
		damage_bonus += ((int)me->query_skill(attack_skill)/4 
			 + (int)me->query_skill("force")/2+1)/10* damage_bonus /10;
	else                    
		damage_bonus += ((int)me->query_skill(attack_skill)/4+1) /10* damage_bonus /10;

	if( martial_skill = me->query_skill_mapped(attack_skill) )
	{
		foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
		if( stringp(foo) ) result += foo;
		else if( intp(foo) ) damage_bonus += foo;
		else if( mapp(foo) )
		{
			result += (string)foo["result"];
			damage_bonus += (int)foo["damage"];
		}
	}

	// Let weapon or monster have their special damage.
	if( weapon )
	{
		foo = weapon->hit_ob(me, victim, damage_bonus);
		if( stringp(foo) ) result += foo;
		else if(intp(foo) ) damage_bonus += foo;
		else if( mapp(foo) )
		{
			result += (string)foo["result"];
			damage_bonus += (int)foo["damage"];
		}
	}
	else
	{
		foo = me->hit_ob(me, victim, damage_bonus);
		if( stringp(foo) ) result += foo;
		else if(intp(foo) ) damage_bonus += foo;
		else if( mapp(foo) )
		{
			result += (string)foo["result"];
			damage_bonus += (int)foo["damage"];
		}
	}

	// Let Jiajin take effect.
	if( my["jiajin"] && (my["jingli"] > my["jiajin"]) )
	{
		foo = my["jingli"]/20 + my["jiajin"] - your["jingli"]/25;
		if (foo > 0)
		{
			if( !objectp(weapon) ) damage_bonus += foo;
			else                   damage_bonus += foo/3;
 		}
		my["jingli"] -= my["jiajin"];
	} 

	if( damage_bonus > 0 )
		damage += (damage_bonus + random(damage_bonus))/2;
	else	damage += (damage_bonus - random(-damage_bonus))/2;
                        
	// Let combat exp take effect
	defense_factor = your["combat_exp"];
	while( random(defense_factor) > my["combat_exp"] )
	{
		damage -= damage / 3;
		defense_factor /= 2;
	}
/*
	// Let special dodge skills take effect.
	dodge_skill = victim->query_skill_mapped("dodge");
	if( dodge_skill && SKILL_D(dodge_skill)->is_special() )
	{
		foo = SKILL_D(dodge_skill)->hit_by(me, victim, damage);
		if( stringp(foo) ) result += foo;
		else if( intp(foo) ) damage = foo;
		else if( mapp(foo) )
		{
			result += (string)foo["result"];
			damage = (int)foo["damage"];
		}
	}
*/
	// Let special parry skills take effect.
	parry_skill = victim->query_skill_mapped("parry");
	if( parry_skill && SKILL_D(parry_skill)->is_special() )
	{
		foo = SKILL_D(parry_skill)->hit_by(me, victim, damage, weapon);
		if( stringp(foo) ) result += foo;
		else if( intp(foo) ) damage = foo;
		else if( mapp(foo) )
		{
			result += (string)foo["result"];
			damage = (int)foo["damage"];
		}
	}

	// Let special armor take effect.
	if( objectp(foo = victim->query_temp("armor/cloth") ) && foo->is_special() )
	{
		foo = foo->hit_by(me, victim, damage, weapon);
		if( stringp(foo) ) result += foo;
		else if( intp(foo) ) damage = foo;
		else if( mapp(foo) )
		{
			result += (string)foo["result"];
			damage = (int)foo["damage"];
		}
	}

	if( damage < 0 ) damage = 0;

	return ([ "result" : result, "damage" : damage ]);
}
