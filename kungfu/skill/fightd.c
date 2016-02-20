//Cracked by Roath
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * // COMBAT_D								*
 * // Experiment by xQin on 8/99					*
 *									*
 * (01) Heart_beat.							*
 * (02) Use atb system to check if we can do attack in this tick.	*
 * (03) Find out what action the attacker will take.			*
 * (04) Use compute_damage to calculate out the damage.			*
 * (05) Use action_power system to calculate out the attack power.	*
 * (06) Find out what dodge action the defender will take.		*
 * (07) Use action_power system to calculate out the dodge power.	*
 * (08) Check if dodge power enough to dodge the attack.		*
 * (09) Find out what parry action the defender will take.		*
 * (10) Use action_power system to calculate out the parry power.	*
 * (11) Check if parry power enough to parry the attack and its damage.	*
 * (12) Reduce the damage by target's armor and force and exp.		*
 * (13) Inflict the damage.						*
 * (14) Check is there a post_action.					*
 *									*
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <combat.h>
#define PRIMARY 1
#define SECONDARY 2

string damage_msg(int damage, string type)
{
        string str;

        if( damage == 0 ) return "结果没有对$n造成任何伤害。\n";

        switch( type )
	{
        case "跌伤":
                if( damage < 100 ) return "结果$p就地一滚，没怎么伤着。\n";
                else if( damage < 200 ) return "结果「吧叽」一声，$p被摔了个屁墩。\n";
                else if( damage < 400 ) return "结果$p的$l着实地被摔了一下！\n";
                else if( damage < 800 ) return "结果$p的$l砸在地上，被摔得青紫！\n";
                else if( damage < 1600 ) return "结果在$p的$l立时肿起一大块，鲜血里透着青紫！\n";
                else return "结果$p的$l被摔得皮开肉绽，骨头从肉里戳出来！！\n";
                break;
        case "咬伤":
                if( damage < 100 ) return "结果只是轻轻地蹭了一下$p的皮肉。\n";
                else if( damage < 200 ) return "结果在$p$l咬出一排牙印。\n";
                else if( damage < 400 ) return "结果$p被咬下一片肉来！\n";
                else if( damage < 800 ) return "结果$p连皮带肉被咬下一大块！\n";
                else if( damage < 1600 ) return "结果在$p的身上咬下来血肉模糊的一大块$l肉！\n";
                else return "结果只听见$n一声惨嚎，$p的$l上的肉被一口咬掉，露出骨头！！\n";
                break;
        case "瘀伤":
        case "淤伤":
        case "挫伤":
                if( damage < 100 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
                else if( damage < 200 ) return "结果在$p的$l造成一处瘀青。\n";
                else if( damage < 400 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
                else if( damage < 800 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
                else if( damage < 1200 ) return "结果「砰」地一声，$n退了两步！\n";
                else if( damage < 1600 ) return "结果这一下「砰」地一声击得$n连退了好几步，差一点摔倒！\n";
                else if( damage < 2400 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！！\n";
                else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
                break;
        case "内伤":
                if( damage < 100 ) return "结果只是把$n打得退了半步，毫发无损。\n";
                else if( damage < 200 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
                else if( damage < 400 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
                else if( damage < 800 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
                else if( damage < 1200 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
                else if( damage < 1600 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
                else if( damage < 2400 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！！\n";
                else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
                break;
	case "震伤":
		if( damage < 100 ) return "结果$p疑惑地看了$P一眼，似乎没有感觉到什么痛处。\n";
		else if( damage < 200 ) return "结果$p身子一晃，立足不定，差点儿就要摔倒。\n";
		else if( damage < 400 ) return "结果$p立足不定，向后接连摔了两个筋斗，哇的一声，喷出一口鲜血！\n";
		else if( damage < 800 ) return "结果$p哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥！\n";
		else if( damage < 1600 ) return "结果$p身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷！\n";
		else if( damage < 2400 ) return "结果只听一声巨响，$p口中鲜血狂喷，全身骨骼碎裂！！\n";
		else return "结果只听一声巨响，$p全身骨骼碎裂，竟似被这排山倒海般的一击将身子打成了两截！！\n";
		break;
        case "擦伤":
        case "抓伤":
                if( damage < 100 ) return "结果$p只被轻轻地蹭破了一点油皮。\n";
                else if( damage < 200 ) return "结果$p的$l上被划出一道细长的血痕。\n";
                else if( damage < 400 ) return "结果「唰」地在$p的$l上蹭掉一大片皮肉！\n";
                else if( damage < 800 ) return "结果「唰」地一声擦出一道血淋淋的伤口！\n";
                else if( damage < 1600 ) return "结果「唰」地一声$p的$l上被撕下血淋淋的一片肉！\n";
                else return "结果只听见$n一声惨嚎，$p$l的皮肉尽裂，露出白森森的骨头！\n";
                break;
        case "割伤":
        case "劈伤":
        case "砍伤":
                if( damage < 100 ) return "结果只是轻轻地划破$p的皮肉。\n";
                else if( damage < 200 ) return "结果在$p$l划出一道细长的血痕。\n";
                else if( damage < 400 ) return "结果「嗤」地一声砍出一道伤口！\n";
                else if( damage < 800 ) return "结果「嗤」地一声劈出一道血淋淋的伤口！\n";
                else if( damage < 1600 ) return "结果「嗤」地一声劈出一道又长又深的伤口，溅得$N满脸鲜血！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p$l砍出一道深及见骨的可怕伤口！！\n";
                break;
        case "刺伤":
                if( damage < 100 ) return "结果只是轻轻地刺破$p的皮肉。\n";
                else if( damage < 200 ) return "结果在$p$l刺出一个创口。\n";
                else if( damage < 400 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
                else if( damage < 800 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
                else if( damage < 1600 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
                break;
        case "砸伤":
		if( damage < 20 ) return "结果只是轻轻地碰撞到了$n一下，没有造成什么伤害。\n";
		if( damage < 60 ) return "结果$w只将$n的$l砸出一块瘀红。\n";
		if( damage < 120 ) return "结果「啪」地一声，$w打中$n的$l，登时肿了一块老高！\n";
		if( damage < 240 ) return "结果$w重重得击中$n的$l，打得$p倒退数步，「哇」地吐出一大口鲜血！\n";
		if( damage < 380 ) return "结果只听见「硼」地一声巨响，$w打在$n身上，将$p像一捆稻草般击飞出去！\n";
		return "只见$w重重地撞击在$n的身上，几声骨碎声中，$p象散了架似的瘫了下去！！\n";
                break;
        case "鞭伤":
                if( damage < 100 ) return "结果只是在$p$l上擦了一道白印。\n";
                else if( damage < 200 ) return "结果在$p的$l上抽出一道血痕。\n";
                else if( damage < 400 ) return "结果「啪」地一声$p被抽了一道伤口！\n";
                else if( damage < 800 ) return "结果$p的$l上被抽了一道血淋淋的创口！\n";
                else if( damage < 1600 ) return "结果「啪」地一声$p被$N的$w抽了一道从头到脚的血印！\n";
                else return "结果只听见「咔嚓」一声，$p的$l的骨头被抽断，$w被染得血红！！\n";
                break;
	case "灼伤":
	case "烧伤":
		if( damage < 100 ) return "结果只是把$p的$l烫了一下。\n";
		else if( damage < 200 ) return "结果$p的$l被$w灼炙得起了个小疱。\n";
		else if( damage < 400 ) return "结果$p的$l被$w烧得红肿疼痛，痛得不住冒汗咬牙！\n";
		else if( damage < 800 ) return "结果「嗤」一声轻响，$p祗觉$l上一片热痛，已被$w烧成了暗红色，犹如焦炭！\n";
		else if( damage < 1600 ) return "结果「嗤嗤」一阵声响过去，$n神色痛楚难当，$l被$w烧得一片焦黑，青烟直冒！\n";
		else return "结果只听见$n长声惨呼，在地上不住打滚，$l已被$w烧得皮肉尽烂，焦臭四溢！！\n";
		break;
	case "冻伤":
		if( damage < 100 ) return "结果$p祗是觉得$l有些冷飕飕地，还挺凉快的。\n";
		else if( damage < 200 ) return "结果$p的$l被冻得有些麻木。\n";
		else if( damage < 400 ) return "结果$p机伶伶地打了个寒颤！\n";
		else if( damage < 800 ) return "结果$p脸色一变，神情有些僵硬，身子也冷得瑟瑟发抖！\n";
		else if( damage < 1600 ) return "结果$p身子打颤，脸色苍白，嘴唇冻得发紫，牙关格格直响！\n";
		else return "结果祗听见$n声音一哑，脸上惨白得没半分血色，颤抖不休，浑身血液似乎都结成了冰！！\n";
        default:
                if( !type ) type = "伤害";
                if( damage < 100 ) str =  "结果只是勉强造成一处轻微";
                else if( damage < 200 ) str = "结果造成轻微的";
                else if( damage < 300 ) str = "结果造成一处";
                else if( damage < 500 ) str = "结果造成一处严重";
                else if( damage < 800 ) str = "结果造成颇为严重的";
                else if( damage < 1200 ) str = "结果造成相当严重的";
                else if( damage < 1700 ) str = "结果造成十分严重的";
                else if( damage < 2300 ) str = "结果造成极其严重的";
                else str =  "结果造成非常可怕的严重";
                return str + type + "！\n";
        }
}

string query_dodge(object me)
{
	string dodge_skill;

	dodge_skill = me->query_skill_mapped("dodge");
	if( !dodge_skill ) return "dodge";

	return dodge_skill;
}

string query_parry(object me)
{
	string parry_skill;
	object weapon;
	mapping prepare;
	int i, check;

	parry_skill = me->query_skill_mapped("parry");

	if( !parry_skill ) return "parry";

	if( objectp(weapon = me->query_temp("weapon"))
	&& me->query_skill_mapped(weapon->query("skill_type")) != parry_skill )
		return "parry";

	prepare = me->query_skill_prepare();
	if( !mapp(prepare) ) return "parry";

	for( i=0; i < sizeof(prepare); i++ )
		if( prepare[(keys(prepare))[i]] == parry_skill )
		{
			check++;
			break;
		}
	if( !check ) return "parry";

	return parry_skill;
}

varargs int action_power(object ob, string skill, mapping action, int usage)
{
        int level, power, jingli_bonus;

        if( !living(ob) ) return 0;

	// 如果是parry，需要用query_parry来判断parry所用的特殊武功是否是使用者正在使用的。
	// 如果不是，level应该只等於(parry, 1)的level。
        level = ob->query_skill(skill);

        switch( usage )
	{
                case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack");
			if( action["attack"] )
				level = level * ( 100 + action["attack"]/10 ) / 100;
                        break;
                case SKILL_USAGE_DEFENSE:
                        level += ob->query_temp("apply/defense");
			if( action["parry"] )
				level = level * ( 100 + action["parry"]/10 ) / 100;
			if( action["dodge"] )
				level = level * ( 100 + action["dodge"]/10 ) / 100;
                        break;
        }

	// 这里应该加入jiajin的bonus，jiajin越高，命中率/防御率越高。
        jingli_bonus = 50 + (int)ob->query("jingli") * 50 / ((int)ob->query("max_jingli")+1);
        if( jingli_bonus > 150 ) jingli_bonus = 150;
	jingli_bonus = jingli_bonus + ob->query("jiajin") / 2;

        if( level < 1 ) return (int)(ob->query("combat_exp")/2 * jingli_bonus/100);

        // here need a modification later
        power = (level*level*level) / 3;

        if( usage == SKILL_USAGE_ATTACK )
                return (power + ob->query("combat_exp")) /30 * ob->query_int() 
                                /100 *jingli_bonus;
        else
                return (power + ob->query("combat_exp")) /30 * ob->query_dex() 
                                /100 *jingli_bonus;
}

// 这个function与现在xkx有一点不同的是，现行xkx是命中对方才计算damage，
// 而这里是一出招就计算damage，并且将内、外伤分开。
// 这个计算结果可能比现行xkx的高，因为现行xkx是一边计算一边reduce damage by victim。
// 而这里仅是单纯计算damage，然後在其他地方执行让victim reduce damage的任务。
// 暂且当作内伤是receive_wound，也就是max_qi，外伤当作receive_damage，也就是qi。
// 这些都需要等以後将人体骨骼肌肉组织与经脉穴道组织分开，才可能真正实现。
// 暂且就这样表示。
mapping compute_damage(mixed user, mixed armed, string attack_skill, mapping action)
{
	int wound, damage, damage_bonus; // 这些var的名字改成正规点的吧。
	// wound，外伤，damage，内伤
	object me, weapon;
	mapping my, prepare;

	// 以下是用来方便以直接用call来进行测试的。
	if( objectp(user) ) me = user;
	else if( stringp(user) ) me = find_living(user);
	else return 0;
	if( !objectp(me) ) return 0;

	my = me->query_entire_dbase();
	// 作为特殊攻击，可以读取预设的武器，也可以让系统自我判断。
	// 就算本身持有武器，为了方便某些特殊情况，也可以排除武器作为计算参数。
	if( objectp(armed) ) weapon = armed;
	else if( intp(armed) )
	{
		switch( armed )
		{
			case PRIMARY : 
				me->query_temp("weapon"); break;
			case SECONDARY :
				me->query_temp("secondary_weapon"); break;
		} 
	}

	// 在并未预设用何种武功作为计算参数的情况下，系统自我判断。
	if( !attack_skill )
	{
		prepare = me->query_skill_prepare();
		if( !prepare ) prepare = ([]);

		if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
		else switch( sizeof(prepare) )
		{
			case 0: attack_skill = "unarmed";
				break;
			case 1: attack_skill = (keys(prepare))[0];
				break;
			case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")];
				break;
			default:attack_skill = (keys(prepare))[random(sizeof(prepare))];
				break;
		}
	}

	// 在并未预设用哪个招数作为计算参数的情况下，系统自我判断。
	if( !mapp(action) )
	{
		me->reset_action();
		action = me->query("actions");
		if( !mapp(action) )
		{
			me->reset_action();
			action = me->query("action");
			if( !mapp(action) )
			{
				CHANNEL_D->do_channel( this_object(), "sys",
					sprintf("%s(%s): bad action = %O",
					me->name(1), me->query("id"), me->query("actions", 1)));
				return 0;
			}
		}
        }

	/******** 从此处开始计算damage ********/
	// 虽然xkx暂时尚未有完善的damage system，
	// 但是为了方便将来的发展，暂以wound为外部伤害，damage为内部伤害。

	// apply/damage通常指的是自身以外的杀伤力，如武器的杀伤力或某些perform所加的额外伤害力。
	// 故以此作为外伤的计算开始。
	damage = me->query_temp("apply/damage") + me->query_str();
	damage = ( damage + random(damage) ) / 2;

	// increase attack power for npc who doesn't have special skills 
	if( !userp(me) ) damage += ((int)me->query_temp("apply/attack") + 1) / 10 * damage /10;

	// 加入这个招数本身的外部杀伤力。
	if( action["damage"] ) damage += action["damage"] /10 * damage /30;

	// 加入所用武功的等级进行计算。
	damage += ((int)me->query_skill(attack_skill) + 1) /10 * damage /10;

	// 以内功等级作为内伤的计算开始
	wound = (int)me->query_skill("force");

	// 这个需要修改。
	if( my["jiali"] && (my["neili"] > my["jiali"]) && me->query_skill_mapped("force") )
	{
		damage_bonus = my["max_neili"] / 2 + my["neili"];
		damage_bonus = damage_bonus / 10 + my["jiali"];
		damage_bonus = damage_bonus * my["jiali"] / (int)me->query_skill("force") * 2;

		if( !objectp(weapon) )	wound += damage_bonus;
		else			wound += damage_bonus / 3;

		my["neili"] -= my["jiali"];
	}

	// 这个也需要修改。
	if( my["jiajin"] && (my["jingli"] > my["jiajin"]) )
	{
		damage_bonus = my["jingli"]/20 + my["jiajin"];

		if( !objectp(weapon) )  wound += damage_bonus;
		else			wound += damage_bonus / 3;

		my["jingli"] -= my["jiajin"];
	} 

	// 加入这个招数本身的内部杀伤力。
	if( action["force"] )
	{
		if( !objectp(weapon) )
			wound += action["force"] /10 * wound / 100;
		else                    
			wound += action["force"] /10 * wound / 300;
	}

	// equal skill, equal power // 这个也需要改，兵器附上内力也能造成内伤。
	if( !objectp(weapon) )
		wound += ((int)me->query_skill(attack_skill)/4 
				+ (int)me->query_skill("force")/2+1)/10 * damage /10;
	else
		wound += ((int)me->query_skill(attack_skill)/4+1)/10 * damage /10;

	return ([ "damage" : damage, "wound" : wound ]);

}
