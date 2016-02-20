//Cracked by Roath
// douzhuan.c 斗转星移

#include <ansi.h>

inherit F_SSERVER;

#define DOU_ZHUAN "douzhuan"
#define DOU_FAKE_NAME "douzhuan/pretend_skill"
#define DOU_FAKE_TYPE "douzhuan/type"

#define UNARM_SKILL 5
#define SHORT_WEAPON_SKILL 3
#define LONG_WEAPON_SKILL 6

string *unarm_skill = ({ "strike", "cuff", "finger", "hand", "claw" });
string *short_weapon_skill = ({ "sword", "blade", "hook" });
string *long_weapon_skill = ({ "stick", "staff", "club", "whip", "hammer", "pike" });

private void remove_effect(object me, object target);

void create()
{
  seteuid(getuid());
}

int perform(object me, object target)
{
  string msg, str;
  object weapon, weapon1;
  string skill, fake_type;
  int ski_num;
  mapping tar_skills;
  
  if(me->query_temp(DOU_ZHUAN)) return notify_fail("你已经在使用斗转星移了。\n");
  
  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character()
      || !me->is_fighting(target) )
    return notify_fail("斗转星移只能对战斗中的对手使用。\n");

  weapon = me->query_temp("weapon");
  weapon1 = target->query_temp("weapon");
  
  if( !weapon1 ) {
    if(weapon) {
      weapon->unequip();
      if( !stringp(str = weapon->query("unwield_msg")) )
        str = "$N放下手中的$n。\n";
      message_vision(str, me, weapon);
    }
    
    ski_num = sizeof(unarm_skill);
    tar_skills = target->query_skill_prepare();
    for(int i = 0; i < ski_num; i++) {
      if(tar_skills[unarm_skill[i]]) {
        skill = tar_skills[unarm_skill[i]];
        me->set_temp(DOU_FAKE_NAME, skill);
        me->set_temp(DOU_FAKE_TYPE, "strike");
        break;
      }
    }
  }
  
  else {
    fake_type = weapon1->query("skill_type");
    skill = target->query_skill_mapped(fake_type);
    
    if(!me->query("env/wiz_test")) return notify_fail("你不是试用此招式之人。\n");
    if(!weapon || weapon->query("skill_type") != fake_type)
      return notify_fail("你没有那样的武器。\n");

    me->set_temp(DOU_FAKE_NAME, skill);
    me->set_temp(DOU_FAKE_TYPE, fake_type); 
    
/*    if(weapon = present("mweapon", me) ) {
      weapon->be_weapon(fake_type);
      me->set_temp(DOU_FAKE_NAME, skill);
      me->set_temp(DOU_FAKE_TYPE, fake_type);
    }
    
    else return notify_fail("暂时不能这么用。\n");*/
  }
  
    
  message_vision(HIY"$N运用斗转星移，对$n以其人之道，还自其人之身。使出"+
    to_chinese(skill)+"\n"NOR, me, target);

  me->add("neili", -80);
  me->add("jingli", -20);

  call_out("remove_effect", 1, me, target);

  return 1;
}

private void remove_effect(object me, object target)
{
  if( !me->is_fighting() || !target || !target->is_character() 
     || !me->is_fighting(target) || !me->query_temp(DOU_ZHUAN) ) 
  {
    message_vision( HIY"斗转星移使完，$N已飞身落地，blah blah blah。\n" NOR, me);
    me->delete_temp(DOU_ZHUAN);
    return;
  }
  
  call_out("remove_effect", 1, me, target);
  return;
}
