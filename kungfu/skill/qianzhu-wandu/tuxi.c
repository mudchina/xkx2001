//Cracked by Roath
// 千蛛万毒突袭
// chu@xkx   3/6/99

// Apache: modified so that player can't perform it continuously.
// Other parts wait for chu for balancing.

inherit F_SSERVER;
#include <ansi.h>

void remove_temp(object me) {
	if (me->query_temp("perform_tuxi"))
		me->delete_temp("perform_tuxi");
}

int perform(object me, object target)
{
  string msg; 
  int finger, ap, dp, dodge, parry, damage, poison;

  if (me->query_temp("perform_tuxi")) {
  	return notify_fail("你的突袭已被对方察觉！等一下吧。\n");
  }

  if ( !target ) target = offensive_target(me);

  if( !target || !target->is_character())
    return notify_fail("你想突袭谁?\n");

  if( environment(target)->query("no_fight"))
    return notify_fail("这里不能偷袭。\n");
    
  if(target->query_temp("surrender/ownder")!=0)
    return notify_fail("你现在不能偷袭他!");

  if( (finger = (int)me->query_skill("qianzhu-wandu", 1)) < 120 )
    return notify_fail("你的千蛛万毒手不够纯熟.\n");

  if (me->query("neili") < 1000)
        return notify_fail("你的内力不够用.\n");

  msg = "$N趁$n不备, 悄然错步转身, 从背后出指突袭。\n\n";
  dodge = target->query_skill("dodge", 1);
  parry = target->query_skill("parry", 1);
  poison = target->query_skill("qianzhu-wandu", 1);
  ap = me->query("combat_exp")*10+finger*finger*finger;
  dp = target->query("combat_exp")*10+dodge*dodge*dodge+parry*parry*parry+poison*poison*poison;
  dp = dp/3;
  damage = finger + me->query("neili")/20;
  damage += random(damage/2);

  if (random(ap) > dp/2) {
        msg += "只听$n闷哼了一声, 后心已被$N指力戳中.\n";
        target->start_busy(1+random(2));
        target->receive_wound("qi", damage, me);
        target->apply_condition("qianzhu-poison", 
            damage/10+target->query_condition("qianzhu-poison"));
        if(target->query("poisoner") != me) target->set("poisoner", me);
        target->set_temp("last_damage_from", me);
  }else {
        msg += "不料$n早有防备, 侧身躲过.\n";
        me->start_busy(1+random(3));
  }
  if (! target->killing_ob(me))  target->kill_ob(me);
  me->add("neili", -damage);

  me->set_temp("perform_tuxi", 1);  
  call_out("remove_temp", 5, me);
  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}
