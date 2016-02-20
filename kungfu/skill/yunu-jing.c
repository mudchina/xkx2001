//Cracked by Roath
///kungfu/skill/yunu-jing 玉女心经
//maco版本
#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("yunu-jing", 1);
                mapping skl; 
        string *sname;
        int i, k=0;
        int t = 1, j;
        for (j = 1; j < lvl / 10; j++) t *= 2;
                skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("this_skill") > 99){

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail
("你体内不同内力互相冲撞，难以领会更高深的武功。\n");
        }

        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的玉女心经。\n");

        if ( me->query("gender") == "男性" && lvl > 80)
                return notify_fail("你身为男子，难以领会高深的玉女心经。\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("玉女心经讲究阴阳调合，有违佛家六根清净之意，"
                        +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

        if ((int)me->query_skill("force", 1) < 10 
          || (int)me->query_skill("force", 1)/2 < lvl/3 )
                return notify_fail("你的基本内功火候还不够。\n");

        if (lvl > 10 && (int)me->query("shen") < t * 100
             && me->query_skill("taoism", 1) < 100) 
                return notify_fail("你的侠义正气太低了。\n");

        return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("yunu-jing", 1) < 150 )
                return notify_fail("你的玉女心经修为不够，只能用学(learn)的来增加熟练度。\n");
        if ( me->query_temp("weapon") )
                return notify_fail("练习玉女心经必须空手，静坐诚心方可。\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("你的体力不够练习玉女心经。\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("你的精力不够练习玉女心经。\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("你的内力不够练习玉女心经。\n");

        me->add("neili", -60);
        me->receive_damage("jingli", 60, "精力透支过度死了");
        me->receive_damage("qi", 60, "体力透支过度死了");
        return 1;
}

string exert_function_file(string func)
{
        return __DIR__"yunu-jing/" + func;
}


mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");
        int ap, dp;
        string result;

        if ( (int)victim->query_skill("yunu-jing", 1) < 80 ) return damage;

        dp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);
        if (objectp(weapon2) && (string)weapon2->query("skill_type") == "sword" ) {
                if ( victim->query_skill_mapped("parry") != "yunu-jian" )
                        return damage;
                dp /= 3;
                dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE)/2;
        } else if (!objectp(weapon2) && ( victim->query_skill_mapped("parry") == "tianluo-diwang" || victim->query_skill_mapped("parry") == "yunu-jian" ) ) {
                if ( victim->query_skill_prepared("strike") != "tianluo-diwang" )
                        return damage;
                dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        } else
                return damage;

        ap = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);
        if (objectp(weapon1))
                ap += COMBAT_D->skill_power(me, weapon1->query("skill_type"), SKILL_USAGE_ATTACK);
        else 
                ap *= 2;

        ap /= 100;
        dp /= 100;

if (wizardp(victim)) tell_object(victim, sprintf("ap: %d, dp: %d\n", ap, dp));
	if(me->query_temp("shentong")) {
                        result = "$n见$N招数凌厉，也不惧怕，旋即以玉女心经上的武功一一破解！\n";
                        damage_bonus = 0;
                                me->start_busy(1+random(1));
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
	
	}
	
        if ( random(ap+dp+dp) > ap ) {
                if (objectp(weapon2) && objectp(weapon1) && (string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") {
                        result = "那知$n所使玉女剑法正是全真剑法的对头，剑尖一颤，陡地弯过，反而先行刺中$N一剑！\n";
                                me->start_busy(1+random(1));
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                } else if (objectp(weapon2) && objectp(weapon1) && (string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("sword") == "duanyun-bian"){
                        result = "那知$n对断云鞭法早已精研透彻，剑尖回转，$N未能伤敌，先中一剑！\n";
                                me->start_busy(1+random(1));
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                }  else if (!objectp(weapon2) && !objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ||((string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") 
||((string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("whip") == "duanyun-bian") ) ){

                        result = "不料$n忽然一掌按出，无影无踪，手掌竟绕过$N手臂，按到了$N胸口，正是玉女心经上制全真武功的绝招！\n";
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);

                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";


		}
                damage_bonus = -5000; // just a number negative enough
                return ([ "result" : result, "damage" : damage_bonus ]);
        } else if( random(ap+dp+dp+dp) > ap ) {
                if (objectp(weapon2)&& objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ||((string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") 
||((string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("whip") == "duanyun-bian") ) ) {
                        result = "$n剑走轻灵，破开了这一招全真武功。\n";
                        damage_bonus = 0;
                } else if (!objectp(weapon2)&& !objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ) ) {
                        result = "但是$n对全真派拳掌招招精熟，随手化解，将$N的内劲全数卸在一旁。\n";
                        damage_bonus = -5000; 
                }
                return ([ "result" : result, "damage" : damage_bonus ]);
        } else 
                return damage;

}
