//Cracked by Roath
// feng.c 打狗棒封字决
// fear@xkx 99.12

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_DBASE;

int perform(object me, object target)
{
        string* msghit, msg;
        object weapon;
        int  feng_busy;
        int feng_addspeed;
        int feng_cost;
        int feng_duration;
        int feng_parry;
        string *limb, type, limb_hurt;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) 
        ||          !living (target) )
                return notify_fail("封字诀只能对战斗中的对手使用。\n");

        if( target->is_busy() ) {
                me->add("neili", -10);
                me->add("jingli", -5);
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧　\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("你已在使用拌字诀！\n");

        if( me->query_temp("pfmfeng",1) )
                return notify_fail("你已在使用封字诀！\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("你所用的并非混天气功，无法施展封字诀！\n");

        if( me->query_skill("force") < 250 )
                return notify_fail("你的混天气功火候未到，无法施展封字诀！\n");

        if( me->query_skill("stick") < 250 )
                return notify_fail("你的打狗棒法修为不足，还不能使用封字诀！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 600 )
                return notify_fail("你的精力不够！\n");

        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("空手如何使用封字决？？\n");

                msghit = ({
                        "\n$N运起打狗棒法中的「封」字诀，棒法全是横使，并不攻击敌身，一条"+(string)weapon->query("name")+HIG"化成一片碧墙，挡在面门。\n",
                        "\n$N大喝一声，运起"+(string)weapon->query("name")+HIG"，使出打狗棒法的「封」字诀，紧紧守住门户。\n",
                        "\n$N提起"+(string)weapon->query("name")+HIG"，使个打狗棒法的「封」字诀，护住身前，挡住攻势。\n",
                        "\n$N挥起"+(string)weapon->query("name")+HIG"，使出打狗棒法中的一招「恶犬拦路」，乃属「封」字诀。\n"
                });
                msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

        if(random(me->query("combat_exp")) * me->query_skill("stick") > random(target->query("combat_exp")) * (target->query_skill("dodge")+ target->query_skill("parry"))/3)
        {
                msghit = ({
                        "「封」字诀甚是精妙，东突西冲，$n立感不支，当下攻势全被挡住。\n",
                        "只见棒影飘飘，「封」字诀登时将$n身前数尺之地尽数封住了。\n",
            "$n突见"+(string)weapon->query("name")+HIY"来势神妙无方，一时竟然被封得难以攻入。\n"
                });
                msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

                feng_busy= me->query_skill("stick")/15;
                feng_addspeed=me->query_skill("stick")/30 ;
                feng_parry = feng_busy * 10;
                
                me->add_temp("apply/parry", feng_parry);
                me->add_temp("apply/speed", feng_addspeed);
                target->add("qi",-me->query_skill("stick")/5);
                target->add("jing",-me->query_skill("stick")/5);
                target->set_temp("feng",1);
                me->set_temp("pfmfeng",1);
                target->start_busy(1+random(2));


        feng_duration= feng_addspeed + feng_busy/( weapon->weight()/1000);
                
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me,target, feng_parry, feng_addspeed  :), feng_duration);
//                call_out("remove_effect",2 + feng_busy/( weapon->weight()/1000),me,target,feng_busy);
                }
        else
        {
                msghit = ({
                        "$n攻时敬，守时严，并没有被封住。\n",
                        "$n快速变招，百忙中急退两步，避开了「封」字诀。\n"
                });
                msg = CYN"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                me->start_busy( 1 + random(4));
                message_vision(msg, me, target);
        
        }

        feng_cost = me->query_skill("stick") / 2;
        me->add("neili", -feng_cost );
        me->add("jingli", -feng_cost/2 );

        return 1;
}


private int remove_effect(object me, object target, int feng_parry, int feng_addspeed)
{
	int skills;
        object weapon;
        skills = me->query_skill("stick")/15;
//        me->add_temp("apply/parry",  -skills * 10);
        me->add_temp("apply/parry",  -feng_parry);
        me->add_temp("apply/speed",  -feng_addspeed);
        if(living (target))
                target->delete_temp("feng");
        me->delete_temp("pfmfeng");
//        tell_object(me, HIY"\n你手中的武器太过沉重，数招之后便感变化不灵。\n"NOR); 
//        tell_object(me, HIY"\n你的棒招陡变，打狗棒的「封」字诀已然瓦解。\n"NOR); 
        if(objectp(me) && objectp(target) && target->is_fighting(me) )
                message_vision(HIG"\n$N的棒招陡变，打狗棒的「封」字诀已然瓦解。\n"NOR ,me,target); 
        return 1;
}

