//Cracked by Kafei
// s_combatd.c
// cyz&kitten@xeno 1999.06.08
/*******************************************************
This is only intented to serve as protocode.  It should
not interfer in anyways with normal mud running. If any1
encounters bug or have suggestions.  Please talk to me
first.  Changes shall not be made without notifying us.
P.S. We do not think ES2 sytled combat system is adequate,
The things you can do within that boundry of sytle are 
still very limited.
*******************************************************/

#pragma optimize all

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

string *guard_msg = ({
	CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
	CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
	CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
	CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
	CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR,
});

string *catch_hunt_human_msg = ({
	HIW "$N和$n仇人相见份外眼红，立刻打了起来！\n" NOR,
	HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
	HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
	HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
	HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
	HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
	HIW "$N喝道：「$n，看招！」\n" NOR,});

string *catch_hunt_beast_msg = ({
	HIW "$N怒吼一声，扑了过来攻击$n！\n" NOR,
        HIW "$N对著$n大吼，想杀死$n！\n" NOR,
	HIW "$N发出连串低吼，突然暴起攻击$n！\n" NOR,});

string *catch_hunt_bird_msg = ({
        HIW "$N对著$n一声怒鸣，飞冲了过来！\n" NOR,
        HIW "$N怒鸣几声，突然暴起攻击$n！\n" NOR,
	HIW "$N一声锐鸣，猛然向$n发动攻击！\n" NOR,});

string *winner_msg = ({
	CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
	CYN "\n$N双手一拱，笑著说道：承让！\n\n" NOR,
	CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
	CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
	CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
	CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});

string *winner_animal_msg = ({
	CYN "\n$N退在一旁，警戒地向$n盯视！\n\n" NOR,
	CYN "\n$N退守开来，但仍然豪不放松地盯着$n！\n\n" NOR,
        CYN "\n$N退了几步，但随时可能再冲过来！\n" NOR,});

void create()
{
	seteuid(getuid());
	set("name", "战斗精灵");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "造成 " + damage + " 点" + type + "。\n";

	if( damage == 0 ) return "结果没有对$n造成任何伤害。\n";

	switch( type ) {
	case "擦伤":
	case "抓伤":
//Ryu: it needs to be redifend. Cann't share same action with 割伤. 
//Mongol: now it can be used by unarmed skills.
                if( damage < 20 ) return "结果$p只被轻轻地蹭破了一点油皮。\n";
                else if( damage < 40 ) return "结果$p的$l上被划出一道细长的血痕。\n";
                else if( damage < 80 ) return "结果「唰」地在$p的$l上蹭掉一大片皮肉！\n";
                else if( damage < 120 ) return "结果「唰」地一声擦出一道血淋淋的伤口！\n";
                else if( damage < 160 ) return "结果「唰」地一声$p的$l上被撕下血淋淋的一片肉！\n";
					 else return "结果只听见$n一声惨嚎，$p$l的皮肉尽裂，露出白森森的骨头！\n";
                break;
	case "割伤":
	case "劈伤":
	case "砍伤":
		if( damage < 20 ) return "结果只是轻轻地划破$p的皮肉。\n";
		else if( damage < 40 ) return "结果在$p$l划出一道细长的血痕。\n";
		else if( damage < 80 ) return "结果「嗤」地一声砍出一道伤口！\n";
		else if( damage < 120 ) return "结果「嗤」地一声劈出一道血淋淋的伤口！\n";
		else if( damage < 160 ) return "结果「嗤」地一声劈出一道又长又深的伤口，溅得$N满脸鲜血！\n";
		else return "结果只听见$n一声惨嚎，$w已在$p$l砍出一道深及见骨的可怕伤口！！\n";
		break;
	case "刺伤":
		if( damage < 20 ) return "结果只是轻轻地刺破$p的皮肉。\n";
		else if( damage < 40 ) return "结果在$p$l刺出一个创口。\n";
		else if( damage < 80 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
		else if( damage < 120 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
		else if( damage < 160 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
		else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
		break;
        case "跌伤":
                if( damage < 20 ) return "结果$p就地一滚，没怎么伤着。\n";
                else if( damage < 40 ) return "结果「吧叽」一声，$p被摔了个屁墩。\n";
                else if( damage < 80 ) return "结果$p的$l着实地被摔了一下！\n";
                else if( damage < 120 ) return "结果$p的$l砸在地上，被摔得青紫！\n";
                else if( damage < 160 ) return "结果在$p的$l立时肿起一大块，鲜血里透着青紫！\n";
                else return "结果$p的$l被摔得皮开肉绽，骨头从肉里戳出来！！\n";
                break;
        case "鞭伤":
                if( damage < 20 ) return "结果只是在$p$l上擦了一道白印。\n";
                else if( damage < 40 ) return "结果在$p的$l上抽出一道血痕。\n";
                else if( damage < 80 ) return "结果「啪」地一声$p被抽了一道伤口！\n";
                else if( damage < 120 ) return "结果$p的$l上被抽了一道血淋淋的创口！\n";
                else if( damage < 160 ) return "结果「啪」地一声$p被$N的$w抽了一道从头到脚的血印！\n";
                else return "结果只听见「咔嚓」一声，$p的$l的骨头被抽断，$w被染得血红！！\n";
                break;
        case "咬伤":
                if( damage < 20 ) return "结果只是轻轻地蹭了一下$p的皮肉。\n";
                else if( damage < 40 ) return "结果在$p$l咬出一排牙印。\n";
                else if( damage < 80 ) return "结果$p被咬下一片肉来！\n";
					 else if( damage < 120 ) return "结果$p连皮带肉被咬下一大块！\n";
                else if( damage < 160 ) return "结果在$p的身上咬下来血肉模糊的一大块$l肉！\n";
                else return "结果只听见$n一声惨嚎，$p的$l上的肉被一口咬掉，露出骨头！！\n";
                break;
	case "瘀伤":
	case "挫伤":
		if( damage < 10 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
		else if( damage < 20 ) return "结果在$p的$l造成一处瘀青。\n";
		else if( damage < 40 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
		else if( damage < 80 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
		else if( damage < 120 ) return "结果「砰」地一声，$n退了两步！\n";
		else if( damage < 160 ) return "结果这一下「砰」地一声击得$n连退了好几步，差一点摔倒！\n";
		else if( damage < 240 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
		else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
		break;
	case "内伤":
		if( damage < 10 ) return "结果只是把$n打得退了半步，毫发无损。\n";
		else if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
		else if( damage < 40 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
		else if( damage < 80 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
		else if( damage < 120 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
		else if( damage < 160 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
		else if( damage < 240 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
		else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		break;
	default:
		if( !type ) type = "伤害";
		if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
		else if( damage < 20 ) str = "结果造成轻微的";
		else if( damage < 30 ) str = "结果造成一处";
		else if( damage < 50 ) str = "结果造成一处严重";
		else if( damage < 80 ) str = "结果造成颇为严重的";
		else if( damage < 120 ) str = "结果造成相当严重的";
		else if( damage < 170 ) str = "结果造成十分严重的";
		else if( damage < 230 ) str = "结果造成极其严重的";
		else str =  "结果造成非常可怕的严重";
		return str + type + "！\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
	if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
	if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
	if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
	if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
	if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
	if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
	if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
	return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
	if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
	if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
	if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
	if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
	if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
	if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
	return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

varargs void report_status(object ob, int effective)
{
	if( effective ) 
		message_vision( "( $N" + eff_status_msg(
			(int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n", ob);
	else
		message_vision( "( $N" + status_msg(
			(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n", ob);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int status, level, power, jingli_bonus;

	if( !living(ob) ) return 0;

	level = ob->query_skill(skill);

	switch(usage) {
		case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level += ob->query_temp("apply/defense");
			if (ob->is_fighting())
				level = level * (100 + ob->query_temp("fight/dodge")/10 ) / 100;
			break;
	}

	jingli_bonus = 50 + (int)ob->query("jingli") *50 / (int)ob->query("max_jingli");
	if (jingli_bonus > 150) jingli_bonus = 150;

	if( level<1 ) return (int)(ob->query("combat_exp")/2 * jingli_bonus/100);

	// here need a modification later
	power = (level*level*level) / 3 ;

	if (usage == SKILL_USAGE_ATTACK)
		return (power + ob->query("combat_exp")) /30 * ob->query_str() 
				/100 *jingli_bonus ;
	else
		return (power + ob->query("combat_exp")) /30 * ob->query_dex() 
				/100 *jingli_bonus ;
}

/************************Special Attack----Anubis****************/
varargs int anubis_attack(object me, object victim, mapping actions, int 
attack_type)
{
        object anubis, weapon;
        mapping fight_dbase;
        string *my_actions, limb, *limbs, result, counter, *counters;
        string action = actions["action"];
        
        weapon = me->query_temp("weapon");
        anubis = victim->query_temp("weapon");
        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        result = "\n"+action + "\n";
        
	if (anubis && objectp(anubis))
	{
		fight_dbase = anubis->query("fightdbase");
		if (mapp(fight_dbase) && 
			arrayp(my_actions = fight_dbase[me->query("id")]) &&
			(member_array(action, my_actions)!= -1))
		{
			result = replace_string( result, "$l", limb );
			if( objectp(weapon))
                	result = replace_string( result, "$w", weapon->name() );
        		else if( stringp(actions["weapon"]) )
                	result = replace_string( result, "$w", actions["weapon"] );
        		message_vision(result, me, victim );
			counters = anubis->query("counters");
			counter = counters[random(sizeof(counters))];
			message_vision(HIW+counter+NOR, victim, me);
			me->receive_wound("qi", 40+random(40));
			report_status(me, 1);
		}else
		{
			anubis->add("fightdbase/"+me->query("id"), ({action})); 
			return 0;
		}					
	}
	return 1;
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special ujinglize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
	mapping my, your, prepare, action;
	string limb, *limbs, result;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int ap, dp, pp;
	int damage, damage_bonus, defense_factor;
	int brief; 
	int wounded = 0;

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
	
	if (userp(me) && userp(victim))
		brief = me->query("env/brief") && victim->query("env/brief");
	else 	
		brief = me->query("env/brief") || victim->query("env/brief");

	//
	// (0) Choose skills.
	//
	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);

	if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
	else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
	else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];
	

	//
	// (1) Find out what action the offenser will take.
	//
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
		me->reset_action();
		action = me->query("action");
		if( !mapp(action) ) {
			CHANNEL_D->do_channel( this_object(), "sys",
				sprintf("%s(%s): bad action = %O",
				me->name(1), me->query("id"), me->query("actions", 1)));
			return 0;
		}
	}

	if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "！\n";
	else
		result = "\n" + "紧跟着"+action["action"] + "！\n"; 
	
	if (victim->query_temp("stand/anubis"))
	{
		//CHANNEL_D->do_channel( this_object(), "sys", "anubis activated");
		if (anubis_attack(me, victim, action, attack_type))
		 	return 0;
	}

	//
	// (2) Prepare AP, DP for checking if hit.
	//
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];

	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	if( ap < 1) ap = 1;
	
	// disable it temporarily until we find a consistent skill power system
	if (userp(me) && intp(action["dodge"]))
		me->set_temp("fight/dodge", action["dodge"]);

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
//	if( dp < 1 || victim->query_temp("yield") ) dp = 1;
	if( dp < 1 ) dp = 1;
	if( victim->is_busy() ) dp /= 3;

	//
	// (3) Fight!
	//     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
	//     AP and DP are greater than zero, so we always have chance to hit
	//     or be hit.
	//
	if( random(ap + dp) < dp ) { 	// Does the victim dodge this hit?

		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		if (!brief)
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

		if( dp <= ap && (!userp(victim) || !userp(me)) 
		&&	random(your["jingli"]*100/your["max_jingli"] + your["int"]) > 50 ) {
			your["combat_exp"] += 1;
			victim->improve_skill("dodge", 1);
		}

		// This is for NPC only. NPC have chance to get exp when fail to hit.
		if( (ap < dp) && !userp(me) ) {
			if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
			me->improve_skill(attack_skill, random(my["int"]));
		}		

		// If we are more than 2 times tougher, victim cost jingli to dodge away.
		if( random(my["combat_exp"]) >= random(your["combat_exp"]) * 2)
		your["jingli"] -= 1;

		// We lost jingli by this missing hit.
		my["jingli"] -= my["jiajin"];

		damage = RESULT_DODGE;

	} else {

		//
		//	(4) Check if the victim can parry this attack.
		//
		if( victim->query_temp("weapon") ) {
			pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
			if( !weapon && undefinedp(action["weapon"]) ) pp *= 2;
		} else {
			if( weapon ) pp = 0;
			else pp = skill_power(victim, attack_skill, SKILL_USAGE_DEFENSE);
		}

		if( victim->is_busy() ) pp /= 2;
		if( pp < 1 ) pp = 1;
//		if( pp < 1 || victim->query_temp("yield") ) pp = 1;

		if( random(ap + pp)< pp ) {

			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
			parry_skill = "parry";
			//if (!brief)
			result += SKILL_D(parry_skill)->query_parry_msg(weapon, victim);

			if( pp <= ap && (!userp(victim) || !userp(me)) 
			&&	random(your["jingli"]*100/your["max_jingli"] + your["int"]) > 50 ) {
				your["combat_exp"] += 1;
				victim->improve_skill("parry", 1);
			}

			// If we are more than 2 times tougher, victim cost jingli to parry away.
			if( random(my["combat_exp"]) >= random(your["combat_exp"]) * 2)
			your["jingli"] -= 1;

			// We lost jingli by this missing hit.
			my["jingli"] -= my["jiajin"];

			damage = RESULT_PARRY;

		} else {

			//
			//	(5) We hit the victim and the victim failed to parry
			//

			damage = me->query_temp("apply/damage");
			damage = (damage + random(damage)) / 2;
			
			// increase attack power for npc who doesn't have special skills 
			if (!userp(me))
				damage += ((int)me->query_temp("apply/attack") + 1) /10 * damage /10;

			// disable action["damage"] temporarily
			// untill we find a consistent damage sys.
			if( action["damage"] )
				damage += action["damage"] /10 * damage / 30;

			// equal skill, equal power
			// make weapon and unarmed has close damage power
			// if (objectp(weapon))
				damage += ((int)me->query_skill(attack_skill) + 1) /10 * damage /10;

			damage_bonus = me->query_str();

			// Let force skill take effect.
			if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
				if( force_skill = me->query_skill_mapped("force") ) {
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					else if( intp(foo) ) {
						if( !objectp(weapon) ) damage_bonus += foo;
						else 		       damage_bonus += foo / 3;
					} else if( mapp(foo) ) {
						result += foo["result"];
						if( !objectp(weapon) ) damage_bonus += foo["damage"];
						else		       damage_bonus += foo["damage"] / 3;
					}
				}
			}

			if( action["force"] ) {
				if( !objectp(weapon) )
					damage_bonus += action["force"] /10 * damage_bonus / 100;
				else 			
					damage_bonus += action["force"] /10 * damage_bonus / 300;
			}

			// equal skill, equal power
			if (!objectp(weapon))
				damage_bonus += ((int)me->query_skill(attack_skill)/4 
					+ (int)me->query_skill("force")/2+1)/10* damage_bonus /10;
			else 			
				damage_bonus += ((int)me->query_skill(attack_skill)/4+1) /10* damage_bonus /10;

			if( martial_skill = me->query_skill_mapped(attack_skill) ) {
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			// Let weapon or monster have their special damage.
			if( weapon ) {
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			} else {
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			// Let Jiajin take effect.
			if( my["jiajin"] && (my["jingli"] > my["jiajin"]) ) {
				foo = my["jingli"]/20 + my["jiajin"] - your["jingli"]/25;
				if (foo > 0) {
					if( !objectp(weapon) ) damage_bonus += foo;
					else		       damage_bonus += foo/3;
				}
				my["jingli"] -= my["jiajin"];
			} 

			// quick attack only inflict half damage
			if( attack_type==TYPE_QUICK) damage /= 2;

			// Temporally tuning down damage power
			// Seems need not this now, player's qi are much longer.
			//if( damage_bonus > 360 ) damage_bonus = 180 + damage_bonus/2;
			//if( damage_bonus > 180 && userp(me) ) damage_bonus = 120 + damage_bonus/3;

			if( damage_bonus > 0 )
				damage += (damage_bonus + random(damage_bonus))/2;
			else    damage += (damage_bonus - random(-damage_bonus))/2;
			if( damage < 0 ) damage = 0;
			
			// Let combat exp take effect
			defense_factor = your["combat_exp"];
			while( random(defense_factor) > my["combat_exp"] ) {
				damage -= damage / 3;
				defense_factor /= 2;
			}

			// Let special armor take effect.
			if( objectp(foo = victim->query_temp("armor/cloth"))
			 && foo->is_special() ) {
				foo = foo->hit_by(me, victim, damage, weapon);
				if (stringp(foo)) result += foo;
				else if (intp(foo)) damage = foo;
				else if (mapp(foo)) {
					result += (string)foo["result"];
					damage = (int)foo["damage"];
				}
			}

			// Let special dodge skills take effect.
			dodge_skill = victim->query_skill_mapped("dodge");
			if( dodge_skill && SKILL_D(dodge_skill)->is_special() ) {
				foo = SKILL_D(dodge_skill)->hit_by(me, victim, damage);
				if (stringp(foo)) result += foo;
                                else if (intp(foo)) damage = foo;
                                else if (mapp(foo)) {
                                        result += (string)foo["result"];
                                        damage = (int)foo["damage"];
                                }
                        }

			//
			//	(6) Inflict the damage.
			//


			damage = victim->receive_damage("qi", damage, me );

			if( random(damage) > (int)victim->query_temp("apply/armor")
			&& ( (me->is_killing(victim->query("id"))) 
				&& ((!weapon) && !random(4) || weapon && !random(2) )
			    || ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
			{
				// We are sure that damage is greater than victim's armor here.
				victim->receive_wound("qi",
					damage - (int)victim->query_temp("apply/armor"), me);
				wounded = 1;
			}

			result += damage_msg(damage, action["damage_type"]);

			//
			//	(7) Give experience and yield gain
			//

			if( !userp(me) || !userp(victim) ) {
				if( (ap <= dp)
				&& !me->query_temp("yield")
				&& !victim->query_temp("yield")
				&&	(random(my["jingli"]*100/my["max_jingli"] + my["int"]) > 30) ) {
					my["combat_exp"] += 1;
					if( my["potential"] < my["max_potential"] )
					        my["potential"] += 1;
					if( attack_skill != "unarmed")//disable unarmed skill improving.
					me->improve_skill(attack_skill, 1);
				}
				if( random(your["max_qi"] + your["qi"]) < damage ) {
					your["combat_exp"] += 1;
					if( your["potential"] < your["max_potential"] )
					        your["potential"] += 1;
				}
				if( victim->query_temp("yield") 
				&& damage <= your["qi"]/2
				&& random(my["combat_exp"]) >= random(your["combat_exp"])
				&& random(5) == 0 )
					victim->improve_skill("parry", random(damage));
			}
		}
	} 

	result = replace_string( result, "$l", limb );
	if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "finger" ) 
		result = replace_string( result, "$w", "手指" );
	else if( attack_skill == "cuff" )
                result = replace_string( result, "$w", "拳头" );
	else if( attack_skill == "strike" )
                result = replace_string( result, "$w", "手掌" );
	else if( attack_skill == "claw" )
                result = replace_string( result, "$w", "手爪" );
	else result = replace_string( result, "$w", "" );

	message_vision(result, me, victim );

	if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
		if( damage > 0 )
			tell_object(me, sprintf( GRN "AP：%d，DP：%d，PP：%d，伤害力：%d\n" NOR,
				ap/100, dp/100, pp/100, damage));
		else
			tell_object(me, sprintf( GRN "AP：%d，DP：%d，PP：%d\n" NOR,
				ap/100, dp/100, pp/100));
	}

	if( damage > 0 ) {
		report_status(victim, wounded);
		if( victim->is_busy() ) victim->interrupt_me(me);
		if( (!me->is_killing(your["id"])) && 
		(!victim->is_killing(my["id"])) &&
		victim->query("qi")*2 <= victim->query("max_qi")) {
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			if ( me->query("race") == "人类" )
			   message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
			else
			   message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, victim);
		}
	}

	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);

	// See if the victim can make a riposte.
	if( attack_type==TYPE_REGULAR
	&&	damage < 1
	&&	victim->query_temp("guarding") 
	&&	random(1-(int)victim->query_temp("apply/speed"))
	      < random((1-(int)me->query_temp("apply/speed"))*6) ) {
		victim->set_temp("guarding", 0);
		if( random(my["dex"]) < 5 ) {
			message_vision("$N一击不中，露出了破绽！\n", me);
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
		} else {
			message_vision("$N见$n攻击失误，趁机发动攻击！\n", victim, me);
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}
}

//	fight()
//
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
	object ob;
	
	if( !living(me) ) return;

//	if( !me->visible(victim)
//	&& (random(100 + (int)me->query_skill("perception")) < 100) )
//		return;

	// If victim is busy or unconcious, always take the chance to make an attack.
	if( victim->is_busy() || !living(victim) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) 
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon")) 
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian"
		   && me->query("gender") == "无性") )
		{
			me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		   me->set_temp("action_flag",0);
	     	}

	// Else, see if we are brave enough to make an aggressive action.
	} else if( random((int)victim->query_dex()*3 ) < (int)me->query_str()*2 
					+ (int)me->query_temp("apply/speed") ) { 
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);  
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) 
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon")) 
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian"
		   && me->query("gender") == "无性") )
		{
		   me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
		   me->set_temp("action_flag",0);
	     	}

	// Else, we just start guarding.
	} else if( !me->query_temp("guarding") ) {
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
		return;
	} else return;
}

//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);

	if( !userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 ) return;

	if( shen > (int)me->query("quest_exp") 
	&&	!wizardp(obj) ) {
		message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me)
			+ "看你实在很不顺眼，去死吧。\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj)
			+ "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our hatred! Charge!
	if ( me->query("race") == "人类" )
        	message_vision( catch_hunt_human_msg[random(sizeof(catch_hunt_human_msg))], me, obj);
	if ( me->query("race") == "野兽" )
		message_vision( catch_hunt_beast_msg[random(sizeof(catch_hunt_beast_msg))], me, obj);
	if ( me->query("race") == "飞禽" )
		message_vision( catch_hunt_bird_msg[random(sizeof(catch_hunt_bird_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
	switch(event) 
	{
	case "dead":
		message_vision(ob->query("dead_message"), ob);
		break;
	case "unconcious":
		message_vision(ob->query("unconcious_message"), ob);
		break;
	case "revive":
		message_vision(ob->query("revive_message"), ob);
		break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void death_penalty(object victim)
{
	int amount;
	if (!userp(victim)) return;

	if (wizardp(victim)) return;
	victim->clear_condition();
	// Give the death penalty to the dying user.
	if( (int)victim->query("combat_exp") >= 10000 * (int)victim->query("death_times") )    
	victim->add("death_times", 1);	
	victim->add("shen", -(int)victim->query("shen") / 20);
	victim->add("behavior_exp", -(int)victim->query("behavior_exp") / 20);
	amount = (int)victim->query("combat_exp") / 100;
	if (amount > 5000) amount = 5000;
	if (amount > 50) {
		victim->add("combat_exp", -amount);
		if( (int)victim->query("potential") > 0)
			victim->add("potential", - (int)victim->query("potential")/2 );
	}
	else if (victim->query("combat_exp") > 20)
		victim->add("combat_exp", -20);

	amount = (int)victim->query("balance") - 10000;
	if (amount > 0) victim->add("balance", -amount/2);
	victim->add("death_count", 1);
	victim->delete("vendetta");
	victim->delete_temp("rob_victim");
	victim->delete_temp("initiator");
	if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);
	victim->skill_death_penalty();
	victim->save();

} // End of death_penalty


void killer_reward(object killer, object victim)
{
	int bls;
	object room;
	string vmark, mode, winner;

	if ( !environment(victim)->query("no_death")) { 

	// Call the mudlib killer apply.
	killer->killed_enemy(victim);

	if( userp(victim) ) {
		killer->add("PKS", 1);
		if( userp(killer) && strsrch(file_name(environment(victim)), "/d/city/") >= 0 )
			killer->apply_condition("killer", 100); // PKer pursue added by Zhuang@XKX
		
		bls = 10;

		if( killer->query("race") == "野兽" 
		||  killer->query("race") == "蛇类" 
		||  killer->query("race") == "游鱼"
		||  killer->query("race") == "昆虫" )      mode = "咬";
		else if( killer->query("race") == "家畜" ) mode = "踩"; 
		else if( killer->query("race") == "飞禽" ) mode = "啄"; 
		else mode = "杀";

		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("%s被%s" + mode + "死了。", victim->name(1), killer->name()));
	} else {
		if(victim->query("race") == "人类") killer->add("MKS", 1);
		bls = 1;
	}
	//prevent ppl gain any bonus from killing mengzhu.
        if( !objectp(room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");
                winner = room->query("winner");
        if( victim->query("id") == winner )
		killer->set_temp("free_rider", 1);
	
	if (userp(killer) && !killer->query_temp("free_rider") 
			  && killer->query("combat_exp") < victim->query("combat_exp")
			  && killer->query("combat_exp") > victim->query("combat_exp") / 4 ) 
		killer->add("shen", -(int)victim->query("shen") / 10);
		killer->add("behavior_exp", -(int)victim->query("behavior_exp") / 10);

//Ryu: disalbe ppl gaining award from killing the npc that fainted by others
 if (killer->query_temp("free_rider")){
                victim->delete_temp("my_killer");
                killer->delete_temp("free_rider");
        }

        if( userp(killer) && userp(victim) &&
            killer->query_temp("pking/"+victim->query("id")) )
                killer->apply_condition("pker", killer->query_condition("pker")+120);

        if( stringp(vmark = victim->query("vendetta_mark")) )
                killer->add("vendetta/" + vmark, 1);

        }
//      else CHANNEL_D->do_channel(this_object(), "rumor",
//                      sprintf("%s被%s杀死了。", victim->name(1), killer->name(1)));

}

// end of file
