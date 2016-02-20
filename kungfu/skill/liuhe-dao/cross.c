//Cracked by Roath
// cross.c  // 十字砍

#include <ansi.h>
inherit F_SSERVER;

void AddFight(int, object, object, object);

int perform(object me, object target)
{
  int WorkTime;
  object SecWeapon, *inv;
  string str;
  
  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() || !me->is_fighting(target) )
     return notify_fail("十字砍只能对战斗中的对手使用。\n");

  if( (int)me->query_skill("huntian-qigong", 1) < 150 )
    return notify_fail("你的混天气功修为不够！\n");

  if( (int)me->query_skill("liuhe-dao", 1) < 150 )
    return notify_fail("你的六合刀法还不够纯熟.\n");
    
  if( (int)me->query("max_neili") < 500 )
    return notify_fail("你的内力修为不够。\n");

  if( (int)me->query("neili") < 150 )
    return notify_fail("你的真气不够。\n");

  inv = all_inventory(me);
  
  for(int i = 0; i < sizeof(inv); i++) {
    if(!inv[i]->query("equipped") && inv[i]->query("skill_type") == "blade" ) {
      SecWeapon = inv[i];
      break;
    }
  }
  
  if(!SecWeapon) return notify_fail("你身上没有多余的刀。\n");
  
  if(!stringp(str = SecWeapon->query("wield_msg")) )
    str = "$N「唰」的一声抽出一柄$n握在手中。\n";

        message_vision(str, me, SecWeapon);

  if(random(2))
    message_vision( HIG
      "紧接者当当两声响，$N双刀齐出，快如飘风般近前，向$n急砍两刀，\n"
      "这正是$N成名绝技“十字砍”，不知有多少江湖好汉曾丧在这毒招之下。\n"NOR, me, target);
  else 
    message_vision( HIG
      "$N大喝一声，突然挺起$n"+HIG"疾砍，双刀上下翻飞，舞成一团白光，使出“十字砍”的凌厉刀势。\n"NOR, me, SecWeapon);

  me->add("neili", -80);
  me->add("jingli", -20);

  SecWeapon->set("equipped", 1);
  if(SecWeapon->query("no_drop") ) SecWeapon->set("no_drop", 10);
  
  me->set_temp("cannot_perform", 1);
  WorkTime = (int)me->query_skill("liuhe-dao") / 20;
  call_out("AddFight", 1, WorkTime, target, SecWeapon, me);

  return 1;
}


void AddFight(int WorkTime, object target, object SecWeapon, object attacker)
{
  object weapon;
  string str;
  
  if(WorkTime == 0 || !attacker->is_fighting() || !target 
     || !target->is_character() || !attacker->is_fighting(target)
     || attacker->query_skill_mapped("blade") != "liuhe-dao" 
     || !objectp(weapon = attacker->query_temp("weapon")) 
     || (string)weapon->query("skill_type") != "blade" )
  {
    message_vision( HIY
    "突然间$N双刀交错，“十字砍”已然招毕，铮的一声响，收起了$n"+HIY"。\n" NOR, attacker, SecWeapon);

    attacker->delete_temp("cannot_perform");
          
                if( !stringp(str = SecWeapon->query("unwield_msg")) )
      str = "$N将手中的$n插回刀鞘。\n";
        message_vision(str, attacker, SecWeapon);
    
    SecWeapon->delete("equipped");
    if(SecWeapon->query("no_drop") == 10) SecWeapon->set("no_drop", 1);
    else SecWeapon->delete("no_drop");
    return;
  }

  else {
    if( !attacker->is_busy()) {
//      weapon = attacker->query_temp("weapon");
//      attacker->set_temp("weapon", SecWeapon
//      COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"), 1);
      COMBAT_D->do_attack(attacker, target, SecWeapon, 1);
    }
    
    call_out("AddFight", 1, WorkTime-1, target, SecWeapon, attacker);
  }
  
  
  
  return;
}


