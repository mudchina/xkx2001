//Cracked by Roath
// duanshi-shenfa.c
// AceP

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : 
"$n双足一挫，右足点地，一式「旱地拔葱」全身借力跃向半空，忽的硬拔起丈余。\n",
        "dodge"  : 10
]),
([      "action" :
"$n侧身一转，双足一顿，一式「雨燕归巢」猛的往上一窜，向一只雨燕般飞入云端。\n",
        "dodge"  : 20
]),
([      "action" :
"$n左手一引，右手猛的拍向地面，一式「破土而出」顺势飞身跃过$N的头顶。\n",
        "dodge"  : 30
]),
([      "action" :
"$n飞身跃起，一式「无中生有」在半空中猛一提气，身体笔直的又飞起五尺。\n",
        "dodge"  : 40
]),
([      "action" :
"$n使出「乘风而去」，全身真气运转三个周天，刹时飞向半空，有如御风而行。\n",
        "dodge"  : 50
]),
([      "action" :
"$n使出「鲧化大鹏」双臂一伸，运气上提，向一只灵山大鸠，飞起数丈。\n",
        "dodge"  : 60
]),
([      "action" :
"$n忽然脸色一变，双目一闭，一式「青云直上」纵身一挺纵身一挺向一片鸿毛飘入半空。\n",
        "dodge"  : 70
]),
([      "action" :
"$n双足忽然加快，身体猛的后仰，一式「风翔九天」脚一发力，平平的窜入空中。\n",
        "dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("duanshi-shenfa");

        
        if (level < 80 )
                zhaoshu--;
   
        if (level < 70 )
                zhaoshu--;


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
                return notify_fail("你的精力太差了，不能练段氏身法。\n");
        me->receive_damage("jingli", 30, "精力透支过度死了");
        return 1;
}

int is_special()
{
	return 1;
}

mixed hit_by(object me, object victim, int damage)
{
	int ap, dp, diff1, diff2;
	string result;
	object weapon;

	if ((me->query_skill_mapped("force")=="kurong-changong"
		&& me->query("family/family_name")=="大理段家")
		|| victim->query_skill("yiyang-zhi", 1) < 120
		|| victim->query_skill_mapped("force")!="kurong-changong"
		|| victim->query_skill_mapped("parry")!="yiyang-zhi"
		|| !living(victim))
		return damage;
/*
	ap = me->query("combat_exp")/100 + me->query_skill("parry")*100;
	dp = victim->query("combat_exp")/100 + victim->query_skill("finger")*120;

	if (me->query("family/family_name")=="白驼山"
		&& me->query_skill_mapped("force")=="hamagong")
		ap = ap/2;

	if (random(dp)>ap/2 ) {
		if (weapon=me->query_temp("weapon")) {
			if (victim->query_skill("yiyang-zhi",1)>180
				&& victim->query("neili")>30) {
				result = HIY "$n看准了"+weapon->query("name")+"的来路，急运一阳指内劲，凌空一指将其荡了开去！\n" NOR;
				victim->add("neili",-30);
				damage = 0;
				return ([ "result" : result, "damage" : damage ]);
			}
		}
		else {
			damage = 0;
			result = HIY "$n看清了$N攻击的来路，急忙运气出指迎击。\n" NOR;
			if (random(2)==1) {
				damage=damage/2;
				me->receive_damage("qi", damage+random(damage), victim);
				if (random(3)==2) {
					me->receive_wound("qi", (damage+random(damage))/2, victim);
				}
				result = result + HIR "$N变招不及，被$n一指戳中，内劲振荡，眼前一黑，向后噔噔噔退了几步！\n" NOR;
			}
			else 
				result = result + HIY "$N一看$n来势不妙，急忙收招，向旁边一闪，躲开了$n的反击。\n" NOR;
			return ([ "result" : result, "damage" : damage ]);
        }
	}
*/
	if (damage >= (int)victim->query("qi")
		&& victim->query_temp("kurong")
		&& damage >= (victim->query("max_qi")/3*2)) {
		if (damage < (int)victim->query_temp("kurong")) {
			victim->add_temp("kurong", -damage);
			result = HIW "$n看$N这一招势大力沉，急运枯荣心法护体，受了这重重一击。虽安然无恙，护体真气却大受损耗！\n" NOR;
			damage = 0;
			return damage;
		}
		else {
			victim->delete_temp("kurong");
			result = HIR "$n受了一下重击，几乎昏死过去！枯荣心法自生反应护住心脉，保住内腑丹田不受损伤。\n" NOR;
			damage = damage/4;
		}
		return ([ "result" : result, "damage" : damage ]);
	}

	return damage;
}	
