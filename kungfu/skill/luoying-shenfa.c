//Cracked by Roath
// luoying-shenfa 落英身法

#include <combat.h>
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$n将头一低，双臂内弯，手肘向前，似箭般向$N怀中扑去，正是一招“灵鳌步”，$N大惊之下，所发招数统统打在$n身后，尽数落空。\n",
        "dodge"  : 10,
        "skill_name" : "灵鳌步"
]),
([      "action" : "$n身形疾闪，使出一招“海燕腾空”，身体如同为海风所激，向后飘开一丈有余，避过$N攻击。\n",
        "dodge"  : 20,
        "skill_name" : "海燕腾空"
]),
([      "action" : "$n将身一纵，跃在半空，收腹含胸，一招“长空落雁”，在空中轻轻巧巧一个翻身，悄无声息地落在$N身后。\n",
        "dodge"  : 30,
        "skill_name" : "长空落雁"
]),
([      "action" : "$n眼见敌招攻来，委实避无可避，忽然一招“巫峡云断”，凌空一个铁板桥，全身自膝盖以上，平平折断，$N招数顿时失了准头，全部打在空处。\n",
        "dodge"  : 40,
        "skill_name" : "巫峡云断"
]),
([      "action" : "$n身形闪动，使出一招“青鸟振翼”，双臂展开，宛若翩翩起舞，姿态飘逸，闪过$N攻击。\n",
        "dodge"  : 50,
        "skill_name" : "青鸟振翼"
]),
([      "action" : "$n身法一变，一式“湘灵空舞”，随着$N攻势，敌左则左，敌右则右，$N虽看似大占上风，却无一招能够击中。\n",
        "dodge"  : 60,
        "skill_name" : "湘灵空舞"
]),
([      "action" : "$n一声清啸，身形拔地而起，正是一招“鹏搏九霄”，在空中一连几个转折，扶摇直上，迅若鲲鹏，举重若轻的闪过$N攻击。\n",
        "dodge"  : 70,
        "skill_name" : "鹏搏九霄"
]),
([      "action" : "$n气凝丹田，脚下疾踩后天八卦方位，一式“归去来兮”，当真是望之在前，忽焉在后，$N手忙脚乱，连抵挡都有所不能，更别提还手反击了。\n",
        "dodge"  : 80,
        "skill_name" : "归去来兮"
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("luoying-shenfa");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*
        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
*/
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练落英身法。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

int is_special()
{
        return 1;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        mapping prepare,action;
	string msg,result,attack_skill;
	object w,w2;
	int ap, dp;
	w = victim->query_temp("weapon");
	w2 = me->query_temp("weapon");

	if( !victim->is_busy() ) return damage;

	if( objectp(w2) )	attack_skill = w2->query("skill_type");
	else {
	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);
	else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
	else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];
		}
	attack_skill = me->query_skill_mapped(attack_skill);

	if( !victim->query_temp("wuzhuan") ) return damage;
	
	if( !living(victim) ) return damage;
	if( victim->query_temp("exercise/playing")) return damage;

	ap = me->query("combat_exp")/1000;
	ap += me->query("jiali")*2;
	dp = victim->query("combat_exp")/1000;
	dp += victim->query_skill("bitao-xuangong", 1);
	dp += victim->query_skill("qimen-dunjia", 1);
	dp = (dp + random(dp*3/2)) / 2;
	action = me->query("actions");

	if( ap > dp ) return damage;


	/* //remove special parry  // maco
	if( wizardp(victim) )
			tell_object(victim,"\ndp："+dp+" ap："+ap+" "+to_chinese(attack_skill)+"，"+action["skill_name"]+"，"+action["weapon"]+"。\n");

	if( !victim->is_busy() ) {
	if(victim->query_skill_mapped("parry") !="tanzhi-shentong") return damage;
	if((int)victim->query_skill("tanzhi-shentong", 1) < 120) return damage;
	if((victim->query_temp("th_jianzhi") > 1 && objectp(w) && w->query("skill_type") == "sword") || !objectp(w) ) {
		if( victim->query_skill_prepared("finger") != "tanzhi-shentong")
		return damage;
		else if( victim->query_temp("wuzhuan_hit") < 0) return damage;
		else if(attack_skill=="tanzhi-shentong")
		result = HIG"$n伸指一弹，嗤的一声轻响，一股细细的劲力激射出去，两股「弹指神通」指力互击，登时消弭於无形。\n" NOR;
//		else if( objectp(w2) &&  stringp(action["skill_name"]) )
//		result = HIG"$n伸指一弹，嗤的一声轻响，一股细细的劲力激射出去，登时将"+w2->name()+HIG"上所附内劲尽数抵销，化解了这招"+to_chinese(attack_skill)+"的「"+action["skill_name"]+"」。\n" NOR;
		else if( objectp(w2) )
		result = HIG"$n伸指一弹，嗤的一声轻响，一股细细的劲力激射出去，登时将"+w2->name()+HIG"上所附内劲尽数抵销，化解了这招"+to_chinese(attack_skill)+"。\n" NOR;
		else result = HIG"$n伸指一弹，嗤的一声轻响，一股细细的劲力激射出去，这「弹指神通」与$N的「"+to_chinese(attack_skill)+"」斗了个旗鼓相当，谁也没能伤谁。\n" NOR;
                                victim->add("neili",- (30+me->query("jiali")/2));
                                victim->add_temp("wuzhuan_hit",-1);

                                damage = 0;
                                return ([ "result" : result, "damage" : damage ]);

			}

	else return damage;
	}
	else {
	*/

        victim->start_busy(1);
        victim->interrupt_me();
	msg = HIB "$N一声长啸，脚下踩着奇门步法，趋前抢后，尤如天神行法，";
        msg += "鬼魅遁影，瞬间只见数十个身影飞射而出，游走不定！\n"NOR;
        
	message_vision(msg, victim);
	return damage;
//	}
}

