//Cracked by Roath
// xiaoyao.c 逍遥幻影

#include <ansi.h>

#define FAKE_OBJ "/d/gaibang/obj/fobj.c"


void AddFight(int, object, object, object);

void create()
{
  seteuid(getuid());
}

int perform(object me, object target)
{
  int WorkTime, AtkNum, Total;
  object env, fakeobj;
  object *inarray;
  string name;
  
  inarray = ({0, 0 , 0, 0, 0, 0, 0, 0, 0});
  
  if(me->query_temp("AlreadyPfmXiaoyao")) return notify_fail("你已经在使用逍遥幻影了。\n");
  
  if( !target )
    return notify_fail("你要对谁使用逍遥幻影？\n");

//  if( !target ) target = offensive_target(me);
  if( !target->is_character()
      || !me->is_fighting(target) )
    return notify_fail("逍遥幻影只能对战斗中的对手使用。\n");

  if( (int)me->query_skill("huntian-qigong", 1) < 125 )
    return notify_fail("你的混天气功修为不够！\n");

  if( (int)me->query_skill("xiaoyaoyou", 1) < 125 )
    return notify_fail("你的逍遥游修为不够！\n");

  if( (int)me->query_skill("liuhe-dao", 1) < 125 )
    return notify_fail("你的六合刀法还不够纯熟.\n");
    
   if( (int)me->query("max_neili") < 500 )
      return notify_fail("你的内力修为不够。\n");

   if( (int)me->query("neili") < 150 )
      return notify_fail("你的真气不够。\n");

  // Here should change description
  if(random(2))
    message_vision( HIY
     "忽然$N一个回旋，真似一只玉燕、一只大鹰翩翩飞舞一般，顷刻间化出无数身影，看得$n眼花缭乱。\n"NOR, me, target);
  else 
    message_vision( HIY
      "只见$N双足轻点，大袖飞舞，东纵西跃，身法灵动如燕，正是洪七公的“逍遥幻影”身法。\n"NOR, me);

  me->add("neili", -40);
  me->add("jingli", -20);

  env = environment(me);
  name = "Fake_Image";

  if(!objectp(fakeobj = present(name, env))) {
    fakeobj=new(FAKE_OBJ);
    fakeobj->move(env);
    inarray[0] = me;
    AtkNum = 1;
    Total = 1;
  }
  
  else if(objectp(fakeobj = present(name, env))){
    AtkNum = fakeobj->query("attacker")[1];
    Total = fakeobj->query("attacker")[2];
    inarray = fakeobj->query("attacker")[0];
    for(int i = 0; i< Total+1; i++) {
      if(inarray[i] == 0) {
        inarray[i] = me;
        break;
      }
    }
    AtkNum++;
    Total++;
  }

  fakeobj->set("attacker", ({ inarray, AtkNum, Total }) );
  fakeobj->set("rider", me); // for invisible
  fakeobj->set_leader(me);
  
  me->set_temp("AlreadyPfmXiaoyao", 1);
  me->set_temp("cannot_perform", 1);
  WorkTime = (int)me->query_skill("liuhe-dao") / 20;
  call_out("AddFight", 1, WorkTime, target, fakeobj, me);

  return 1;
}


void AddFight(int WorkTime, object target, object fakeobj, object attacker)
{
  object weapon, *inarray;
  int Total, AtkNum, i;
  
  if(WorkTime == 0 || !attacker->is_fighting()
     || attacker->query_skill_mapped("blade") != "liuhe-dao" 
     || !objectp(weapon = attacker->query_temp("weapon")) 
     || (string)weapon->query("skill_type") != "blade" ) 
  {
    message_vision( HIY
    "逍遥幻影身法招使完毕，$N已飞身落地，身法轻灵飘逸之至。\n" NOR, attacker);
    attacker->delete_temp("AlreadyPfmXiaoyao");
    attacker->delete_temp("cannot_perform");
    if(fakeobj->query("attacker")[1] != 0) {
      Total = fakeobj->query("attacker")[2];
      inarray = fakeobj->query("attacker")[0];
      AtkNum = fakeobj->query("attacker")[1];
      for(i = 0; i<Total; i++) {
        if(inarray[i] == attacker) inarray[i] = 0;
        break;
      }
      AtkNum--;
      fakeobj->set("attacker", ({ inarray, AtkNum, Total }) );
    }

    if(fakeobj->query("attacker")[1] == 0) destruct(fakeobj);
    return;
  }

  else {
    if( !attacker->is_busy())
      COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"), 1);
  
    call_out("AddFight", 1, WorkTime-1, target, fakeobj, attacker);
  }
  
  
  
  return;
}

