//Cracked by Roath
// kungfu/skill/jiuyin-zhao/shenzhua.c  
// 2000/09/12 yasuko

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int o_def,o_dod,o_par;

int perform(object me, object target)
{
        object report;
        int damage,lvl,k,l;
        string str;

        if (!target ) target = offensive_target(me);
        if (!target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");
        if (objectp(me->query_temp("weapon")))
                return notify_fail("你不是空手。\n");
        if ((lvl=(int)me->query_skill("jiuyin-zhao",1))< 200)
                return notify_fail("你的九阴白骨爪修为不够。\n");
        if ((lvl=(int)me->query_skill("cuixin-zhang",1))< 150)
                return notify_fail("你的摧心掌修为不够。\n");
        if (me->query_temp("jyz_pfmed")==1)
                return notify_fail("你刚使过这一招，不能聚集足够的元气。\n");
        if (!me->query("jiali"))
                return notify_fail("你的出手这么轻，又何必痛下杀手呢？\n");
        if (me->query("neili")<=lvl*4) return notify_fail("你的内力不够！\n");
        if (me->query("jingli")<=lvl*2) return notify_fail("你的精力不够！\n");

        message_vision(HIW "$N突然凌空虚劈一掌，右手疾伸。五根手指后发先至，竟已悄无声息地扣住了$n的咽喉。\n\n" NOR, me,target);
        me->add("neili", -lvl);
        me->add("jingli", -lvl);
        o_def=me->query_temp("apply/defense");
        o_dod=me->query_temp("apply/dodge");
        o_par=me->query_temp("apply/parry");
        me->add_temp("apply/defense", -100);
        me->add_temp("apply/dodge", -100);
        me->add_temp("apply/parry", -100);
        me->set_temp("jyz_pfmed",1);
        if (!target->is_killing(me->query("id"))) target->kill_ob(me);
        call_out("delay",1800/lvl,me);

        //the accurate is decied by dex and used times and exp
        k=me->query("combat_exp")/10*(9+random(21))-target->query("combat_exp")-random(me->query("combat_exp")/10);
        l=random(me->query_dex()-me->query_temp("jyz_pfm"))-random(target->query_dex()*2/3);
        me->add_temp("jyz_pfm",1);
        if (k<=0 && l<0) {
                message_vision(HIC "$n早有提防，从容地向后退了半步，便已避开了$N的致命一击！\n\n" NOR, me,target);
       	        tell_object(me, HIR"你奋力一击，只道就此得手。不想却被对手轻易闪过，背后登时露出了极大的空门。\n\n"NOR);
                me->start_busy(3+random(3));
                return 1;
        }
        if (k<=0 && l>=0) {
                message_vision(CYN "$n自知无幸，不料$N功力尚浅，虽然一击命中，却已是强弩之末，再也无力按下去了。\n\n" NOR, me,target);
                return 1;
        }
        if (k>0 && l<0) {
                damage=me->query_str()*me->query("jiali")/target->query_con();
                if (me->query("id")=="yasuko") tell_object(me,sprintf("k:%d, l:%d, damage:%d \n",k,l,damage));
                if (damage<=100) message_vision(BLU "$n心知此招厉害，竭力向后闪躲。虽是堪堪避过，早已惊出了一身冷汗。\n\n" NOR, me,target);
                else {
                        message_vision(MAG "$n心知此招厉害，竭力向后闪躲。虽然避过了咽喉要害，胸前却已被重重地印上了一掌。\n\n" NOR, me,target);
                        target->receive_damage("qi",damage,me);
                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("($N"+str+")\n", target);
                }
                target->start_busy(3+random(3));
                me->add("neili", -lvl);
                me->add("jingli", -lvl);
                return 1;
        }
        if (k>0 && l>=0) {
                //the damage is decide by str and jiali and jiuyin-zhao lvl
                damage=(me->query_str()+me->query("jiali")/10)*lvl/100*(9+random(21));
                me->add("neili", -lvl*3);
                me->add("jingli", -lvl);
                if (me->query("id")=="yasuko") tell_object(me,sprintf("k:%d, l:%d, damage:%d \n",k,l,damage));
                //3 level wonder
                if ((int)damage/target->query("eff_qi")*100>=100) {
                        message_vision(HIR "只听噗的一声响，$N的五根手指已抓断了$n的喉管。\n\n" NOR, me,target);
                        target->die();
                        return 1;
                }
                if ((int)damage/target->query("eff_qi")*100>=50&&(int)damage/target->query("eff_qi")*100<100)
                        message_vision(HIR "只听唰的一声，$n的喉头已被扯下一大块皮肉，顿时血流如注。\n\n" NOR, me,target);
                if ((int)damage/target->query("eff_qi")*100<50)
                        message_vision(HIR "只听哧的一声，$n的喉部已被抓出了五条鲜血淋漓的爪痕。\n\n" NOR, me,target);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi", damage, me);
                str = COMBAT_D->status_msg((int)target->query("eff_qi") * 100 /(int)target->query("max_qi"));
                message_vision("($N"+str+")\n", target);
                return 1;
        }
}

int delay(object me)
{
        me->delete_temp("jyz_pfmed");
        if (me->query("id")=="yasuko") tell_object(me,"ok,u can use it again.\n");
        me->set_temp("apply/defense", o_def);
        me->set_temp("apply/dodge", o_dod);
        me->set_temp("apply/parry", o_par);
        return 1;
}