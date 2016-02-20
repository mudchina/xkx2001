//Cracked by Roath
///kungfu/skill/riyue-lun/riyue.c 
// 日月同辉
// snowbird Jan 2000

#include <ansi.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, add, add2, damage, ap, pp, dp, busy_time;
        string *limbs, limb, str, weapon, *pfm_msg, msg, dodge_skill;
   object obj;

   obj = me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");

   if (!(obj) || (obj->query("name")!="法轮" && obj->query("name")!="金轮"))
      return notify_fail("你手中无轮，如何施展日月同辉！\n");

        if( me->query_skill_mapped("hammer") != "riyue-lun" )
                return notify_fail("你所用的非日月轮法，不能施展日月同辉！\n");

   if( me->query_skill_mapped("force") != "longxiang-banruo" )
                return notify_fail("你所用的并非龙象般若功，施展不出日月同辉！\n");

        if( me->query_skill("force") < 250 )
                return notify_fail("你的内功修为不够火候，使用不了日月同辉！\n");

        if( me->query_skill("hammer") < 300 )
                return notify_fail("你的日月轮法火侯不够！\n");

        if( me->query("neili") <= 800 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 600 )
                return notify_fail("你的精力不够！\n");

   busy_time = 0;

   weapon = obj->name();

   pfm_msg = ({ 
   "$N踏上一步，"+weapon+"忽地脱手，向$n飞了过去。但见"+weapon+"急转，向$n砸到！",
   "$N抢身长臂，手掌在轮缘一拨，那"+weapon+"就如活了一般，在空中忽地转身，又向$n追击过去！",
   "$N抢上去突伸左拳，当的一声在轮边一击，"+weapon+
   "来势并不十分迅速，但轮子未到，疾风已然扑至，势道猛恶之极！",
   "$N盛怒之下，伸手推出"+weapon+"，暗用转劲，又将轮子飞出。这时劲力加急，轮子竟然寂然无声！",
   "$N运起龙象之力同时双掌齐出，拍在轮上，那"+weapon+
   "犹似长了眼睛一般，在空中绕了半个圈子，向$n身後急追！",
   "$N收掌跃起，将空中的"+weapon+"收回。"
   });

        me->set_temp("xueshan/riyue",1);

        skill = me->query_skill("hammer") + me->query_skill("force");
        if(skill>1200) skill=1200;
        add = skill / 4;
   if(add > 200) add = 200;
        add2 = add / 4;

        /* add power */
        me->add_temp("apply/attack",add);
        me->add_temp("apply/damage",add2);

/* This the first hit */
        msg = HIY"\n"+ pfm_msg[0] +"\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

/* This the second hit */

        me->add_temp("xueshan/riyue",1);

        me->add_temp("apply/attack",50);
        me->add_temp("apply/damage",10);

        msg = HIY"\n"+ pfm_msg[1] +"\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        /* Remove power */
        me->add_temp("apply/attack",-(add+50));
        me->add_temp("apply/damage",-(add2+10));

        busy_time = 2;
        if (skill > 700)
        {
                        /* This the third hit */
                        me->add_temp("xueshan/riyue",1);

                        msg = HIY"\n"+ pfm_msg[2] +"\n" NOR;
                        message_vision(msg, me, target);
         msg = HIW"\n$N口中喝道：第"+chinese_number(me->query_temp("xueshan/riyue"))+"招来了！\n"NOR;
                        message_vision(msg, me);

        ap = COMBAT_D->skill_power(me,"hammer", SKILL_USAGE_ATTACK)*3;
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
                  ap = (ap+random(ap*2));

        if (ap > (pp+dp))
        {
                          damage = skill*1.5 + random(me->query("jiali") + me->query("jiajin"));
           if (damage > 1500) damage = 1500;

                                target->receive_damage("qi", damage,  me);
                                target->receive_wound("qi", (int)me->query_skill("hammer"), me);

                                me->add("neili", -(50 + me->query("jiali")/2));
                                me->add("jingli", -me->query("jiajin")/3);
           
           str = "$N躲闪不及，被"+weapon+"重重的击中胸口，哇的喷出一口鲜血。\n";
                          message_vision(str,target);

                          str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                          message_vision("($N"+str+")\n", target);
        }
                  else 
                  {
            limbs = target->query("limbs");
            dodge_skill = target->query_skill_mapped("dodge");
            if( !dodge_skill ) dodge_skill = "dodge";
            limb = limbs[random(sizeof(limbs))];
            str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
            message_vision(str, me, target);
            busy_time = busy_time + 1;
                  }
        }

/* add power for my next 2 hits */
        me->add_temp("apply/attack", (add+50));
        me->add_temp("apply/damage", (add2+10));

   if (skill > 900)
   {
                /* This the forth hit */
                me->add_temp("xueshan/riyue",1);
                msg = HIY"\n"+ pfm_msg[3] +"\n" NOR;
                message_vision(msg, me, target);

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      busy_time = busy_time + 1;
        }

        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 10);

   if (skill > 1100)
   {
                /* This the fifth hit */
                me->add_temp("xueshan/riyue",1);
                msg = HIY"\n"+ pfm_msg[4] +"\n" NOR;
                message_vision(msg, me, target);

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      busy_time = busy_time + 1;
        }

/* back to normal*/
        me->add_temp("apply/attack", -(add+100));
        me->add_temp("apply/damage", -(add2+20));

        msg = HIY"\n"+ pfm_msg[5] +"\n" NOR;
        message_vision(msg, me);

        if ( me->query("neili") > 250 )
                me->add("neili", -200);
        else me->add("neili", -(me->query("neili") - 10));
  
        if ( me->query("jingli") > 150 )
                me->add("jingli", -100);
        else me->add("jingli", -(me->query("jingli") - 10));

        me->delete_temp("xueshan/riyue");
        me->start_busy( busy_time+random(2) );

        return 1;
}
