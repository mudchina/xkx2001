//Cracked by Roath
// chan.c  「缠」字诀
// by aln 2 / 98

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg, skill, spskill, spforce;
        object weapon;

        mapping forces = ([
                "sword" : "taiji-shengong",
                "stick" : "huntian-qigong",
                "whip"  : "hunyuan-yiqi",
        ]);

        mapping skills = ([
                "sword" : "taiji-jian",
                "stick" : "dagou-bang",
                "whip"  : "riyue-bian",
        ]);

        if( me->is_busy() ) {
                tell_object(me, "你上一个动作还没有完成，不能施用外功。)\n");
                return 1;
        }

        if( me->query("neili") <= 300 ) {
                tell_object(me, "你的内力不够！\n");
                return 1;
        }

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) ) {
                tell_object(me, "牵制攻击只能对战斗中的对手使用。\n");
                return 1;
        }

        if( target->is_busy() ) {
                tell_object(me, target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
                return 1;
        }

        if( !(weapon = me->query_temp("weapon")) ) {
                tell_object(me, "你手中没有武器，如何使得缠字诀？\n");
                return 1;
        }

        skill = (string)weapon->query("skill_type");
        if( member_array(skill, keys(skills)) == -1 ) {
                tell_object(me, "你使用的武器不能使你施展缠字诀！\n");
                return 1;
        }

        spskill = skills[skill];
        if( me->query_skill_mapped(skill) != spskill ) {
                tell_object(me, "你现在不在使用" + to_chinese(spskill) + "。\n");
                return 1;
        }

        if( (int)me->query_skill(skill) < 100 ) {
	        tell_object(me, "你的" + to_chinese(spskill) + "不够娴熟，不会使用「缠」字诀。\n");
                return 1;
        }

        spforce = forces[skill];
        if( (int)me->query_skill(spforce, 1) < 80 ) {
                tell_object(me, "你的" + to_chinese(spforce) + "修为不够，不会使用「缠」字诀。\n");
                return 1;
        }

        if( me->query_skill_mapped("force") != spforce ) {
                tell_object(me, "你所用的内功不符。\n");
                return 1;
        }

        me->add("neili", -80);
        me->add("jingli", -20);

        switch(spskill) {
        case "taiji-jian":
                msg = CYN "$N使出太极剑法「缠」字诀，连递数个虚招企图扰乱$n的攻势。\n";
                break;
        case "dagou-bang":
		msg = CYN "$N使出打狗棒法「缠」字诀，幻出连山棒影，将$n吞没！\n";
                break;
	case "riyue-bian":
		msg = HIY "$N使出日月鞭法的天缠地绕诀，连挥数鞭，如黑龙般着地向$n的全身卷去！\n";
                break;
        }

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                switch(spskill) {
                case "riyue-bian":
                        msg += "结果$p被$P攻了个措手不及，浑身被漫天鞭影裹在其中！\n" NOR;
                        break;
                case "taiji-jian":
                        msg += "结果$p被$P攻了个措手不及ⅵ\n" NOR;
                        break;
                case "dagou-bang":
                        msg += "结果$p被$P缠了个手忙脚乱，一时无法还招进攻！\n" NOR;
                        break;
                }
                target->start_busy(1 + random( (int)me->query_skill(spskill, 1) / 20));
        } else {
                switch(spskill) {
                case "riyue-bian":
                        msg += "可是$p看破了$P的鞭法去路，敏捷地闪了开去。\n" NOR;
                        break;
                default:
                        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                        break;
                }

                me->start_busy(1 + random(3));

        }

        message_vision(msg, me, target);
        return 1;
}

