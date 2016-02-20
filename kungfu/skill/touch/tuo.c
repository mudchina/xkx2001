//Cracked by Roath
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

       if( !objectp(armor = target->query_temp("armor/cloth") ))
	        return notify_fail("对手现在没有穿衣啊～\n");

	if ( target->query_temp("armor/cloth")=="equipped")
		return notify_fail("对手现在没有穿衣啊～\n");

        message_vision(HIM "忽然之间，$N大喝一声，扑向$p身前，双手飞舞乱摸，使出十八摸的「脱」”字决！\n\n" NOR, me,target);
        lvl = (int)(lvl / 5);
        me->add("neili", -lvl*2); 
        me->add("jingli", -100);  
        jiali = me->query("jiali");
        jiajin = me->query("jiajin");


        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE)/3;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE)/3;

        if (wizardp(me))
                printf("ap = %d , pp = %d , dp = %d .\n",ap*2,pp,dp);   // check overflow

        ap = (ap+random(ap*2))/3.5;

        if( ap > dp ) {
            if( target->query_temp("armor/cloth")){
    			tell_object(target,HIY"你只觉身上的发痒，浑身不自在，已经中了「脱」字诀了！\n"NOR);
                	armor = target->query_temp("armor/cloth");
			if( armor->query("id") == "armor")
                     		message_vision(HIW"只见$N身上的$n"+HIW+"已被脱可下来，露出了白白的肌肉！\n"NOR, target, armor);
		        armor->unequip();
            } 
        }
	else message_vision(HIY"哎呀～$N，「脱」字决失败了！\n"NOR,target);
        return 1;
}
