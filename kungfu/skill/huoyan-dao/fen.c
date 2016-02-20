//Cracked by Roath
// /kungfu/skill/huoyan-dao/fen.c  perform 焚
// Summer, 11/10/96.
// kane, 25/11/98.

#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object armor;
        int damage, jiali, jiajin, ap, dp, pp, dmg, lvl, my_exp, max_dmg;
        string *limbs, limb, type, result, str, dodge_skill;

        my_exp = me->query("combat_exp");
        type = "内伤";

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");

        if ( objectp(me->query_temp("weapon")) )
                return notify_fail("你不是空手。\n");

        if( (lvl=(int)me->query_skill("huoyan-dao", 1)) < 120 )
                return notify_fail("你的火焰刀修为不够。\n");

        if ( me->query_skill_mapped("force") != "xiaowuxiang"
        && me->query_skill_mapped("force") != "longxiang-banruo")
                                         return notify_fail("你所用内功不对！\n");

        if( me->query("neili") <= lvl*2 )
                                         return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 150 )
                                         return notify_fail("你的精力不够！\n");

        message_vision(HIR "$N长吸一口气，身上衣衫缓缓涨起，两掌变得通红，射出一股灼人热气。$n的身影被笼罩在一团火焰之中。\n\n" NOR, me,target);
        lvl = (int)(lvl / 5);
        me->add("neili", -lvl*2); 
        me->add("jingli", -100);  
        jiali = me->query("jiali");
        jiajin = me->query("jiajin");

/*
        attack = me->query("combat_exp")/1000; // 800k /1k = 800
        attack += me->query("max_neili")/5; // assume u have 4k max neili only, it's 4000/5 = 800
        attack += me->query("neili")/5; // now you dazuo to 7k temp neili, you have 7k/5 = 1400
        defense = target->query("combat_exp")/1000; // 800k /1k = 800
        defense += target->query_skill("parry"); // now assume ur opponent has 300 enable parry, it's 300
        defense += target->query_skill("dodge"); // and assume has 300 enable dodge, it's 300
        defense += target->query("jingli"); // add jingli factor, usually 1200 jingli 800k exp
        attack = (attack+random(attack*2))/2; // now  (3000 + random(6000))/2 = 1500 + random(3000)
*/

        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE)/3;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE)/3;

	if (wizardp(me))
		printf("ap = %d , pp = %d , dp = %d .\n",ap*2,pp,dp);	// check overflow

        ap = (ap+random(ap*2))/2.5;

        if( ap > dp ) {
            tell_object(target, RED"你只觉一股热浪扑面，霍的胸口一阵剧痛。\n"NOR);
            if( target->query_temp("armor/cloth")){
                armor = target->query_temp("armor/cloth");
                if( armor->query("armor_prop/armor") < 150){
                
		if( armor->query("id") == "armor")
                     message_vision(HIY"只见$N身上的$n"+HIY+"已被震得粉碎，变成一块块碎片四下飞散！\n"NOR, target, armor);
		else message_vision(HIY"只见$N身上的$n"+HIY+"已被震得粉碎，变成一块块破布掉在地上。\n"NOR, target, armor);

                     armor->unequip();
                     armor->move(environment(target));
                     armor->set("name", "破碎的" + armor->query("name"));
                     armor->set("value", 0);
                     armor->set("armor_prop/armor", 0);
                     target->reset_action();
                }
            }
            dmg = me->query_skill("force")+me->query_skill("strike")+me->query("jiajin");
            dmg = (dmg + random(dmg*2))/2;   
            damage = dmg*(1+random(me->query("jiali")/15)); 
            max_dmg = 2000;
            // set the max damage according to player level
            // since now player can do way more damage to 2k
            // so for a 5M player here, his max damage is 4k
            if (my_exp > 1000000) {
                max_dmg = max_dmg + (int)((my_exp-1000000)/2000);
            }
            if( damage > max_dmg )
            {  
                damage = max_dmg;
            }
            if( ap < pp ) damage = random(damage);
            //damage = random((int)me->query_skill("strike"))*5;  
            target->receive_damage("qi", damage,  me);
            target->receive_wound("qi", damage/2+random(damage/2), me);
            target->start_busy(1+random(2));                                                                        // target busy time > own busy time
            me->start_busy(2+random(2));
            if(jiali > me->query("neili"))
                jiali = me->query("neili");
            if(jiajin > me->query("jingli"))
                jiajin = me->query("jingli")-1;
            
            me->add("neili", -jiali-lvl);                                                               // cost neili 140
            me->add("jingli", -jiajin-lvl/2);                                           // cost jingli 120

            limbs = target->query("limbs");

            result = COMBAT_D->damage_msg(damage, type);
            result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
            result = replace_string( result, "$p", target->name() );
            message_vision(result, me, target);

            str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
            message_vision("($N"+str+")\n", target);
        
        } else {
/*
        dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        limb = limbs[random(sizeof(limbs))];
        str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
        message_vision(str, me, target);
*/
            message_vision(HIY "$p赶紧向後跃开数丈，躲开$P的攻击。\n" NOR, me, target);
            me->start_busy(1+random(3));
        }


        return 1;
}
