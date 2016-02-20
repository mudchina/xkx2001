//Cracked by Roath
// linji-zhuang.c 临济十二庄 (emei force)
// xuy@xkx

#include <ansi.h>

inherit FORCE;
string check() { return "force"; }

#include "/kungfu/skill/force_list.h"

string *skill_name = ({
  "天字庄",
  "地字庄",
  "之字庄",
  "心字庄",
  "游龙庄",
  "鹤翔庄",
  "旋风庄",
  "飘云庄",
  "大字庄",
  "小字庄",
  "幽字庄",
  "冥字庄",
  "临济十二庄",
});

string *combo_name = ({
  "天地",
  "之心",
  "龙鹤",
  "风云",
  "大小",
  "幽冥",
});

int valid_enable(string usage)
{
  return usage == "force";
}

int valid_learn(object me)
{
  mapping skl; 
  string *sname;
  int v, k=0;

  int i, nb, np, nf, nl;
  nb = (int)me->query_skill("mahayana", 1);
  np = (int)me->query_skill("persuading", 1);
  nf = (int)me->query_skill("force", 1);
  nl = (int)me->query_skill("linji-zhuang", 1);

  skl=this_player()->query_skills();
  sname=sort_array( keys(skl), (: strcmp :) );

  if(me->query_skill("linji-zhuang", 1) > 99){

    for(v=0; v<sizeof(skl); v++) {
      if (SKILL_D(sname[v])->check() == "force")
	k++;  
    }

    if ( k >=2 )
      return notify_fail("你体内不同内力互相冲撞，难以领会更高深的内功。\n");
  }


  if ( nl >= 20 && nb < 150 && nb <= nl )
    return notify_fail("你的大乘涅磐法修为不够，无法修练更高深的临济十二庄。\n");
  if ( (nl >= 60 && np < 150 && np <= nl ) || np <= nl/2 )
    return notify_fail("你的渡世济人善业做得不够，无法修练更高深的临济十二庄。\n");

  if ( nf < 10 || nf/2 < nl/3 )
    return notify_fail("你的基本内功火候还不够，无法修练临济十二庄。\n");

  return 1;
}


int practice_skill(object me)
{
  return notify_fail("临济十二庄只能用学(learn)的来增加熟练度。\n");
}

string query_skill_name(int level)
{
  if (level < 180) return skill_name[level/15];
  else return skill_name[12];
}
string exert_function_file(string func)
{
  return __DIR__"linji-zhuang/" + func;
}

void skill_improved(object me)
{
  int level = me->query_skill("linji-zhuang",1);
  int o_lvl = me->query("linji_lvl");
  int i;

  if ( level > 180 ) return;

  if ( level/15*15 == level ) {
    tell_object(me, HIG "你对「" + skill_name[level/15-1] + "」已豁然贯通。\n"NOR);
    if (o_lvl < level) {
      tell_object(me, HIG"顿时你对基本内功的领悟也大大提高。\n"NOR);
      for (i=0; i< level; i++)		
	me->improve_skill("force", level);
    }
  }

  if ( level/30*30 == level ) 
    if (o_lvl < level) {
      tell_object(me, HIY"此时你" + combo_name[level/30-1] +
		  "二庄融会贯通，一股柔和的真气周游全身，内力修为更精深了一层。\n"NOR);
      me->add("max_neili", level);
    }
	

  if ( o_lvl < level ) me->set("linji_lvl", level);
		
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
  int lvl = victim->query_skill("linji-zhuang", 1);

  // Buddha force (similar to shaolin):
  // 
  // If we have enough neili, no matter how strong our enemy is, we have
  // chance to rebounce.
  // 
  if (victim->query("neili")>lvl*10 && random(lvl*lvl + 32400) > 32400) {
    return - lvl; 
  }

  // If we failed to rebonuce, we have the chance to reduce the damage

  // need certain amount of neili to reduce damage
  if (victim->query("neili") < lvl*3) return damage;

  // note that this only matters with force part of the damage, the other factors of
  // damage, such as weapon, skill will still be applied. So even if we return 0 here,
  // the damage could be a few hundreds still.  Don't panic!
  if (lvl > 200) return 0;

  return damage * (40000 - lvl*lvl)/100000;
}

mapping curing_msg(object me)
{
	return ([
		"start_self"	: HIY"你一运气，立时便觉丹田中一股暖意升将上来。\n"NOR,
	]);
}
