//Cracked by Roath
// sanhui 「亢龙三悔」
// kane 25/5/1998
// Modified by xQin 1/99

/*
　　萧峰心下又是痛惜，又是愤怒，当即大步迈出，左手一划，右手呼的一掌，便
向丁春秋击去，正是降龙十八掌的一招“亢龙有悔”，他出掌之时，与丁春秋相距
尚有十五六丈，但说到便到，力自掌生之际，两个相距已不过七八丈。

　　天下武术之中，任你掌力再强，也决无一掌可击到五丈以外的。丁春秋素闻“
北乔峰，南慕容”的大名，对他决无半点小觑之心，然见他在十五八丈之外出掌，
万料不到此掌是针对自己而发。殊不料萧峰一掌既出，身子已抢到离他三四丈外，
又是一招“亢龙有悔”，后掌推前掌，双掌力道并在一起，排山倒海的压将过来。

　　只一瞬之间，丁春秋便觉气息窒滞，对方掌力竟如怒潮狂涌，势不可当，双如
是一堵无形的高墙，向自己身前疾冲。他大惊之下，哪里还有余裕筹思对策，但知
若是单掌出迎，势必臂断腕折，说不定全身筋骨尽碎，百忙中将阿紫向上急抛，双
掌连划三个半圆护住身前，同时足尖着力，飘身后退。

　　萧峰跟着又是一招“亢龙有悔”，前招掌力未消，次招掌力又到。丁春秋不敢
正面直撄其锋，右掌斜斜挥出，也萧峰掌力的偏势一触，但觉右臂酸麻，胸中气息
登时沉浊，当即乘势纵出三丈之外，唯恐敌人又再追击，竖掌当胸，暗暗将毒气凝
到掌上。萧峰轻伸猿臂，将从半空中附下的阿紫接住，随手解开了她的穴道。
*/

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{
        string weapon;

        if( !target ) target = offensive_target(me);
/*
        if( !wizardp(me) )
                return notify_fail("你不是萧峰，不会使用「亢龙三悔」！\n");
*/
        if( me->query_temp("sanhui_busy") )
                return notify_fail("你微一运劲，只觉胸中气息沉浊，无力出掌！\n");

        if( me->query_temp("xianglong",1) )
                return notify_fail("你正在使用内功，无法试用「亢龙三悔」！\n");

        if( !target || !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("「亢龙三悔」只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("「亢龙三悔」只能空手运用。\n");

        if( me->query_temp("yield") )
                return notify_fail("你不出掌，如何使出「亢龙三悔」？\n");

        if( me->query_str() < 50 )
                return notify_fail("你的臂力不足以施展「亢龙三悔」！\n");

        if( me->query_con() < 50 )
                return notify_fail("你的体质不足以施展「亢龙三悔」！\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("你所用的内功与「亢龙三悔」气路相悖！\n");

        if( me->query_skill("huntian-qigong", 1) < 280 )
                return notify_fail("你的混天气功火候未到，无法施展「亢龙三悔」！\n");

        if( me->query_skill("xianglong-zhang", 1) < 300 )
                return notify_fail("你降龙十八掌不够娴熟，无法施展「亢龙三悔」！\n");

        if( (int)me->query("max_neili", 1) < 5000 )
                return notify_fail("你的内力修为不够，无力施展「亢龙三悔」！\n");

        if( me->query("neili") < 1000 )
                return notify_fail("你现在的内力太弱，不够使用「亢龙三悔」！\n");

        if( (int)me->query("jingli", 1) < 500 )
                return notify_fail("你现在的体力太弱，不够使用「亢龙三悔」\n");

        message_vision( HIR"\n$N深吸一口气，挫步沉肩，看来要出猛招了！\n"NOR, me);

        me->add("neili", -100);
        me->add("jingli", -100);
        me->set_temp("sanhui", 1);

        me->start_busy(1);
        call_out("sanhui", 1, me, target);
        return 1;

}

int sanhui(object me, object target)
{
        int enfor, skill, amount;

        if ( !living(me) || me->is_ghost() || environment(me) != environment(target) )
        {
                remove_effect(me);
                return;
        }
        else if ( !living(target) || !me->is_fighting(target) )
        {
                message_vision(CYN"\n$N当即收回右掌，左掌在身前画了个圆圈。\n"NOR,me);
                remove_effect(me);
                return;
        }
        else if ( (int)me->query("neili", 1) < 500 )
        {
                tell_object(me, HIR"你待要再发一掌，却发现自己的内力不够了！\n"NOR);     
                remove_effect(me);
                return;
        }
        else
        {
                skill = me->query_skill("force");
                enfor = me->query("jiali");

                // this one count how many strike u hit.
                me->set_temp("sanhui_busy", (int)me->query_temp("sanhui"));

                /*
                 * if 1 strike missed, do attack again. at most can have 3 strike.
                 * the enfor of each strike will add by, but the apply/attack will reduce.
                 */

                switch ( me->query_temp("sanhui") )
                {
                        case 1:         // the first strike is same to leiting's,
                                        // but this will only add on apply/attack.
                                amount = skill/2;
                                me->set("jiali", (int)(enfor+enfor/3));
                                break;
                        case 2:
                                amount = skill/3;
                                me->set("jiali", (int)(enfor+enfor/2));
                                break;
                        case 3:
                                amount = skill/4;
                                me->set("jiali", enfor*2);
                                break;
                }

                me->add_temp("apply/attack", amount);
                me->add_temp("apply/damage", amount);
                me->add_temp("apply/strike", amount/3);

                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));

                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/damage", -amount);
                me->add_temp("apply/strike", -amount/3);
                me->set("jiali", enfor);

                /*
                 * PS: in xianglong-zhang.c mixed hit_ob,
                 * if hit target, will delete_temp("sanhui"),
                 * so start remove_effect.
                 */

                if ( !me->query_temp("sanhui") || me->query_temp("sanhui") == 3 )
                        remove_effect(me);
                else
                {
                        me->add_temp("sanhui", 1);
                        sanhui(me, target);
                }
        }

        return 1;
}

void remove_effect(object me)
{
        int sanhui_busy = me->query_temp("sanhui_busy");

        // if 300 htqg and 300 force, enable force will 450.
        int amount = (int)(450 - me->query_skill("force")) / 2;
        if ( amount < 15 ) amount = 15;

        if ( sanhui_busy == 3 )
                message_vision(RED"\n$N三掌击出，大耗真气，不得不转攻为守，稍事调息。\n"NOR,me);

        // if 3 hit all missed, delete sanhui temp here.
        if ( me->query_temp("sanhui") )
                me->delete_temp("sanhui");

        // more hits, cost more neili, min 100, max 300.
        me->add("neili", -100 * sanhui_busy);

        // more hits, longer busy time, longer to receive heal.
        me->start_busy(sanhui_busy + random(2));
        call_out("receive_heal", (int)amount * sanhui_busy / 3, me);
}

void receive_heal(object me)
{
        if ( !me ) return;

        me->delete_temp("sanhui_busy");
        tell_object(me, MAG"\n你经过一阵运功调息，消去了胸中所凝住的一股浊气。\n"NOR); 
}
