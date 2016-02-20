//Cracked by Roath
// zuida.c 八仙醉打
// by  aln 4 / 98
// Modified by Apache 9/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object target, int d0, int d1);

mixed eff_skill = ([
        "dagou-bang"      : ({-3, 0}),
        "dugu-jiujian"    : ({-5, 0}),
        "feifeng-bian"    : ({-2, 0}),
        "fengmo-zhang"    : ({ 1, 5}),
        "jingang-chu"     : ({ 1, 5}),
        "liangyi-dao"     : ({ 1, 4}),
        "lingshe-zhang"   : ({ 1, 5}),
        "liuhe-dao"       : ({ 1, 5}),
        "liuhe-qiang"     : ({ 1, 4}),
        "luan-blade"      : ({ 1, 5}),
        "pixie-jian"      : ({-5, 0}),
        "riyue-lun"       : ({ 1, 4}),
        "taiji-jian"      : ({-4, 0}),
        "taiji-quan"      : ({-3, 0}),
        "tianshan-zhang"  : ({ 1, 5}),
        "wuhu-duanmen"    : ({ 1, 5}),
        "xue-dao"         : ({ 1, 4}),
        "yanxing-dao"     : ({ 1, 4}),
        "zui-gun"         : ({ 0, 0}),
]);                       


void create() { seteuid(getuid()); }

int perform(object me, object target)
{
    object *ob, weapon;
    mapping skill_map, prepare;
    string attack_skill;
    int limit, degree, lvl, lvl2, condt, *damage, d0, d1;

    limit  = me->query("con") + me->query("max_neili")/25;
    degree = me->query_condition("drunk");

    if( !me->is_fighting() )
        return notify_fail("只有在战斗中才能使用八仙醉打！\n");

    target = offensive_target(me);
        if( !target ) return notify_fail("八仙醉打只对战斗中的对手有效！\n");

    weapon = me->query_temp("weapon");
    if( !objectp(weapon) || weapon->query("skill_type") != "club" )
        return notify_fail("你手中无棍，如何使得八仙醉打？\n");

    if( degree < limit/4 )
        return notify_fail("你还没有喝醉呢，怎么能施展八仙醉打？！\n");

    if( environment(me)->query("no_fight") )
        return notify_fail("在这里你不能乱用醉棍打人！\n");

    if( (lvl = me->query_skill("zui-gun", 1)) < 90 )
        return notify_fail("你在棍法上下的功夫还不够，不会使八仙醉打！\n");

    if( me->query_skill("hunyuan-yiqi", 1) < 60 )
        return notify_fail("你的混元一气功火候未到，无法施展八仙醉打！\n");

    if( me->query("max_neili") <= 500 )
        return notify_fail("你的内力修为不足，劲力不能与酒意融和，无法施展八仙醉打！\n");

    if( me->query("jingli") < 500 )
        return notify_fail("你现在的精力不够，无法达到形醉意不醉的状态！\n");
        
    if( me->query_temp("zui-da") ) 
        return notify_fail("你正在使用八仙醉打攻击敌人！\n");

    message_vision( HIY "\n$N呃地打了个酒嗝，脚步突然踉跄起来，手中的" + 
        weapon->name() + "不知指向何方，身形飘忽不定！\n\n" NOR, me);

    condt = 0;
    if( skill_map = target->query_skill_map() ) {
        if( weapon = target->query_temp("weapon") ) {
            attack_skill = weapon->query("skill_type");
            if( skill_map[attack_skill] ) {
                attack_skill = skill_map[attack_skill];
                condt++;
            }
        } 
        else {
            if( prepare = target->query_skill_prepare() ) {
                attack_skill = (keys(prepare))[(int)target->query_temp("action_flag")];
                if( skill_map[attack_skill] ) {
                    attack_skill = skill_map[attack_skill];
                    condt++;
                }
            }
        }
    }

    if( condt < 1 || undefinedp(eff_skill[attack_skill]) )
        damage = ({ 1, 1});
    else
        damage = eff_skill[attack_skill];

    //message("info", sprintf("Damage: %d, %d.\n", damage[0], damage[1]), environment(me), 0);

    lvl2 = (int)target->query_skill(attack_skill, 1);

    d0 = damage[0] * lvl * lvl / (2 * lvl + lvl2) / 10;
    d1 = damage[1] * lvl * lvl / (lvl + lvl2 * 2) / 10;

    me->add_temp("apply/strength", d0);
    me->add_temp("apply/dexerity", d0);
    //me->add_temp("apply/damage", d0);
    me->set_temp("zui-da", 1);

    if( !target->query_temp("zui-da-suffer") ) {
        target->set_temp("zui-da-suffer", 1);
        target->add_temp("apply/strength",  -d1);
        target->add_temp("apply/dexerity",  -d1);
        target->add_temp("apply/parry",     -d1/4);
    }

    call_out("remove_effect", lvl/10, me, target, d0, d1);

    me->add("jingli", -200);

    return 1;
}

void remove_effect(object me, object target, int d0, int d1) {
    if( me ) {
        if( me->query_temp("zui-da") ) {
            me->delete_temp("zui-da");
            me->add_temp("apply/strength", -d0);
            me->add_temp("apply/dexerity", -d0);
            //me->add_temp("apply/damage", -d0);
            message_vision("\n$N一收招式，便从醉态中恢复了过来。\n", me);
        }
    }

    if( target ) {
        if( target->query_temp("zui-da-suffer") ) {
            target->delete_temp("zui-da-suffer");
            target->add_temp("apply/strength",  d1);
            target->add_temp("apply/dexerity",  d1);
            target->add_temp("apply/parry",     d1/4);
        }
    }
}
