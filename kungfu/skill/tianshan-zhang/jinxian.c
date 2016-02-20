//Cracked by Roath
// jinxian.c
// 大罗金仙化功杖
// sdong 7/6/99

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;



void qi_suck(object me, object target);
void neili_suck(object me, object target);


int perform(object me, object target)
{
  object ob;
  string msg;
  int damage;
  int finger, skill, jiali, my_rate, your_rate;
        int sp, dp;
        int dmg;

        if( !target ) target = offensive_target(me);

        if( !target ) return notify_fail("你要吸取谁的内力？\n");

        if( !objectp(target) || target == me
        || target->query("id") == "mu ren"
        || target->query("id") == "shangshan"
        || target->query("id") == "mengzhu"
        || target->query("id") == "fae" )
                return notify_fail("你要吸取谁的内力？\n");

        if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸取过内力！\n");

	if( me->query_temp("pifeng",1) && me->query("tianshan")!=1 )
                return notify_fail("你已在使用披风杖法，无法运用金仙！\n");

        if( !me->is_fighting() || !target->is_fighting() || !living(target) )
                return notify_fail("你必须在战斗中才能吸取对方的内力！\n");

  	if( me->query_skill_mapped("force") != "huagong-dafa" )
         	return notify_fail("你所用的并非化功大法，不能吸取对方的内力！\n");

        if( (int)me->query_skill("huagong-dafa",1) < 60 )
                return notify_fail("你的化功大法功力不够，不能吸取对方的内力！\n");

        if( (int)me->query("neili") < 20 )
                return notify_fail("你的内力不够，不能使用化功大法。\n");

        if( (int)me->query("neili") >= (int)me->query("max_neili") * 5 )
                return notify_fail("你吸取的内力充塞全身，无法再吸取内力！\n");

  	if( (skill = (int)me->query_skill("tianshan-zhang", 1)) < 100 )
         	return notify_fail("你的天山杖法不够娴熟，不会使大罗金仙化功杖。\n");


  msg = HIM "\n$N突然间手舞足蹈，口中念念有词，诵道：“星宿神功，威震寰宇，古今无比”，\n";
  msg += HIM "跟着将手中杖向空中连连抛送，毫无章法，好似跳大罗金仙舞，让人瞠目结舌。\n\n"NOR;

  message_vision(msg, me, target );
  me->start_busy(1);

        if( (int)target->query("neili") < (int)target->query("max_neili") / 10
         || (int)target->query("jingli") < (int)target->query("max_jingli") / 5 )
         {
                if( random(4) ) call_out("qi_suck", 1 + random(3), me, target );
                else return notify_fail( target->name() + "已经内力涣散，你已经无法从他体内吸取任何内力了！\n");
                return 1;
         }

         if(random(3)) call_out("neili_suck", 1 + random(5), me, target );
         else  call_out("qi_suck", 1 + random(5), me, target );

  return 1;
}

void neili_suck(object me, object target)
{
  object ob;
  string msg;
  int damage;
  int finger, skill, jiali, my_rate, your_rate;
        int sp, dp;
        int dmg;

        if( !target ) target = offensive_target(me);
        if( !target ) return;
        if( !objectp(target) ) return;
        if( environment(target) != environment(me) )return;

        message_vision(
                HIW "$N一张脸突然变得惨白，于乱杖之中，左掌直出，猛地对准$n的膻中大穴按了上去！\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
        dp = target->query_skill("force") + target->query_skill("dodge") + target->query_kar();
                  sp *= me->query("combat_exp")/1000;
                  dp *= target->query("combat_exp")/1000;

        me->set_temp("sucked", 1);

        if( random(sp+dp) > dp )
        {
                message_vision(
                        HIR "$N顿觉膻中微痛，如同被尖针刺了个小孔，全身内力如水银般循孔飞泄而出！\n\n" NOR,
                        target );

                tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);

                target->add("neili", -1*(int)me->query_skill("force") );

                me->add("neili", ((int)me->query_skill("force")));
                if( target->query("combat_exp") >= me->query("combat_exp")/2 ) {
                        me->add("potential", 1);
                        me->add("combat_exp", 1);
                if (me->query("potential") > me->query("max_potential"))
                                         me->set("potential", me->query("max_potential"));
                }

                me->start_busy(1+random(3));
                target->start_busy(1+random(3));
                me->add("neili", -(int)me->query_skill("force")/6 );
                me->add("jingli", -5);


                dmg = random( me->query_skill("force")/100 ) * me->query("neili");
                if( dmg > 2000) dmg=2000;
                if( dmg <700) dmg=700;
                target->receive_damage("qi", dmg,me );
                target->receive_wound("qi", random(dmg), me);
                target->add("jingli", -random(dmg)/4);
                COMBAT_D->report_status(target);
                call_out("del_sucked", 1+random(2), me);
        }
        else
        {
                if( target->query("race") != "人类" )
                        message_vision(HIY "可是$p看破了$P的企图，闪开了。\n" NOR, me, target);
                else
                        message_vision(HIY "可是$p看破了$P的企图，冷笑道：“这种幛眼法也骗得了我！”，说完倏地闪开了。\n" NOR, me, target);

                message_vision(RED "结果$N反而手忙脚乱，空耗了不少内力。\n" NOR, me );
                me->add("jingli", -5);
                me->add("neili", -random(me->query_skill("force")) );
                me->start_busy(1 + random(3) );
                call_out("del_sucked", 1+random(3), me);
        }

}

void qi_suck(object me, object target)
{
  object ob;
  string msg;
  int damage;
  int finger, skill, jiali, my_rate, your_rate;
  int sp, dp;
  int dmg;

        if( !target ) target = offensive_target(me);
        if( !target ) return;
        if( !objectp(target) ) return;

        if( environment(target) != environment(me) )return;

        message_vision(
                HIB "$N突然诡异的一笑，双手一扬，于乱杖之中，拇指对准$n的掌心按了过来！\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
        dp = target->query_skill("force") + target->query_skill("dodge") + target->query_kar();
                  sp *= me->query("combat_exp")/1000;
                  dp *= target->query("combat_exp")/1000;

        me->set_temp("sucked", 1);

        if( random(sp+dp) > dp )
        {
                tell_object(target, HIR "你突然觉得全身真气自手掌奔涌而出，四肢无力，再也使不出劲来！\n" NOR);
                tell_object(me, HIG "你觉得" + target->name() + "的真气自手掌源源不绝地流了进来。\n" NOR);
                message_vision(
                        HIR "$N觉得全身真气自手掌奔涌而出，四肢无力，再也使不出劲来！\n\n" NOR,
                        target );

                me->add("qi", (int)me->query_skill("force") );

                if( target->query("combat_exp") >= me->query("combat_exp")/2 )
                        me->add("combat_exp",1);

                me->start_busy(random(2));
                target->start_busy(random(2));
                me->add("neili", -(int)me->query_skill("force")/6);
                me->add("jingli", -5);

                dmg = random( me->query_skill("force")/100 )* me->query("neili");
                if( dmg > 3000) dmg=3000;
                if( dmg <700) dmg=700;
                target->receive_damage("qi", dmg, me );
                target->receive_wound("qi", random(dmg), me);
                COMBAT_D->report_status(target);

                call_out("del_sucked", 1, me);
        }
        else
        {
                if( target->query("race") != "人类" )
                        message_vision(HIY "可是$p看破了$P的企图，哼地一声闪了开去。\n" NOR, me, target);
                else if( target->query("family/family_name") != "星宿派")
                        message_vision(HIY "可是$p看破了$P的企图，哼地一声：“星宿老妖的徒子徒孙也就这水平？”，飘然闪了开去。\n" NOR, me, target);
                else
                        message_vision(HIY "可是$p看破了$P的企图，哼地一声：“这招骗别人还行，骗我？”，飘然闪了开去。\n" NOR, me, target);

                message_vision(RED "结果$N反而手忙脚乱，白费劲。\n" NOR, me );

                me->add("jingli", -5);
                me->add("neili", -random(me->query_skill("force")) );
                me->start_busy(2);
                call_out("del_sucked", 1+random(2), me);
        }

}

void del_sucked(object me)
{
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}

