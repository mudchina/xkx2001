//Cracked by Roath
// mie.c 灭剑

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int dodge, parry, attack, sword, busy_time;

        weapon = me->query_temp("weapon");
	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		weapon = me->query_temp("secondary_weapon");

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("灭剑只能对战斗中的对手使用。\n");

        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，怎能运用「灭剑」心法？！\n");

        if( me->query_temp("huifeng/mie") )
                return notify_fail("你正在运用「灭剑」心法！\n");

        if( me->query_skill("huifeng-jian",1) < 60 )
                return notify_fail("你回风拂柳剑修为还不够，还未领悟「灭剑」！\n");

        if( me->query_skill("linji-zhuang", 1) < 60 )
                return notify_fail("你的内功修为火候未到，施展「灭剑」只会伤及自身！\n");

        if( me->query_skill_mapped("force") != "linji-zhuang")
                return notify_fail("你所用的内功与「灭剑」心法相悖！\n");

        if( me->query("max_neili") <= 600 )
                return notify_fail("你的内力修为不足，劲力不足以施展「灭剑」！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够，劲力不足以施展「灭剑」！\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力有限，不足以施展「灭剑」！\n");

        if ( userp(me) ) {
          me->add("neili", -100);
          me->add("jingli", -30);
        }

        dodge = target->query_skill("dodge")/3;
        parry = target->query_skill("parry")/3;
        attack = sword = me->query_skill("sword")/5;
        me->add_temp("apply/sword", sword);

        if (target->query_temp("pfm-target/huifeng-mie")) { 
          // the target is already being performed by mie

          message_vision(HIY "\n\n$N清啸一声，身形腾空丈许，将峨嵋绝技「灭剑」心法"+
                        "融入回风拂柳剑招之中，\n手中"+weapon->name()+
                         "挽起无数剑花，功势更加淋漓！\n" +
                        "$n本就已经眼花缭乱，惊慌之下更是不知所措！\n" NOR, 
                         me, target);

          // 2/3 the length of tjj's chan, need two person to perform
          // but 100% succ rate !!
          busy_time = me->query_skill("huifeng-jian", 1) / 30;

          // if target was busy before, we shouldn't set him free
          busy_time += target->query_busy();  

          // there is always 1/3 time for the target to escape, unless there are 
          // 3 or more players perform mie on him with good synchronization.
          target->start_busy(busy_time);

          // make sure we can't perform continuously
          call_out("finish_mie2", sword/4, me, target, sword);


        }else {

          if (me->query_temp("huifeng/"+target->name()) ) {
            message_vision(HIY "\n\n$N清啸一声，身形腾空丈许，将峨嵋绝技「灭剑」心法融入回风拂柳剑招之中，\n手中"
                           +weapon->name()+
                           "挽起无数剑花，功势更加淋漓！$n虽已领教过，仍须全神贯注，小心提防。\n" NOR, 
                           me, target);
            target->add_temp("apply/dodge", -dodge/3);
            target->add_temp("apply/parry", -parry/3);
            target->add_temp("apply/attack", -attack/3);
            target->add_temp("apply/speed", -dodge/30);
            call_out("remove_effect", sword/3, me, target, dodge/3, parry/3, 
                     attack/3, sword);
          } else {
            message_vision(HIY "\n\n$N清啸一声，身形腾空丈许，将峨嵋绝技「灭剑」心法融入回风拂柳剑招之中，\n手中"
                           +weapon->name()+"挽起无数剑花，$n眼花缭乱，被攻了个措手不及！\n" NOR, 
                           me, target);
            target->add_temp("apply/dodge", -dodge);
            target->add_temp("apply/parry", -parry);
            target->add_temp("apply/attack", -sword);
            target->add_temp("apply/speed", -dodge/10);
            call_out("remove_effect", sword/2, me, target, dodge, parry, 
                     attack, sword);
          }
        }

        me->set_temp("huifeng/mie", 1);
        me->set_temp("huifeng/"+target->name(), 1);

        // count of how many person perform mie on him
        target->add_temp("pfm-target/huifeng-mie", 1);  

        return 1;
}

void remove_effect(object me, object victim, int dodge, int parry, int attack, int sword)
{
  if (objectp(victim)) {
    victim->add_temp("pfm-target/huifeng-mie", -1);
    victim->add_temp("apply/dodge", dodge);
    victim->add_temp("apply/parry", parry);
    victim->add_temp("apply/attack", attack);
    victim->add_temp("apply/speed", dodge/10);
  }

  if (objectp(me)) {
    me->add_temp("apply/sword", -sword);
    me->delete_temp("huifeng/mie");
  }

  if (objectp(me) && objectp(victim) && victim->is_fighting(me)) {
    message_vision(HIY "\n\n$N渐渐适应了$n的剑路，攻守自如多了。\n" NOR, victim, me);
  }
}

void finish_mie2(object me, object victim, int sword)
{
  if (objectp(victim)) {
    victim->add_temp("pfm-target/huifeng-mie", -1);
  }

  if (objectp(me)) {
    me->add_temp("apply/sword", -sword);
    me->delete_temp("huifeng/mie");
  }

  if (objectp(me) && objectp(victim) && victim->is_fighting(me)) {
    message_vision(HIY "\n\n$N渐渐适应了$n的剑路，攻守自如多了。\n" NOR, victim, me);
  }
}
