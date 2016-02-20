//Cracked by Roath
// exam.c
// exam player's data
// by sdong , adapted from chu's diamond, 11/18/98

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void print_info(object usr);
mapping valid_types =
([
        "finger":   "指法",
        "hand":     "手法",
		  "cuff":     "拳法",
		  "claw":     "爪法",
		  "strike":   "掌法",
		  "kick":     "腿法",
]);


int main(object me, string arg)
{
  object usr;

  if (! arg) return notify_fail("指令格式：exam player.\n");

  usr = present(arg, environment(me));
  if (!usr) usr = present(arg, me);
  if (!usr) usr = find_player(arg);
  if (usr) {
	 print_info(usr);
	 return 1;
  }

  seteuid(geteuid(me));
  usr = new("/clone/test/dummy");
  usr->set("id", arg);
  if ( !usr->restore() )
	 return notify_fail("没有这个玩家。\n");
  print_info(usr);
  destruct(usr);
  return 1;
}

void print_info(object usr)
{
	 mapping skills, prepare,pmap;
	 string  *keys, skill_type,*skill;
	 int     skill_num, i, lvl, attack_points, parry_points, dodge_points;
	 int     age_sec, age_years, age_decimal;
	 object  weapon;

	 if( objectp(weapon = usr->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	 else {
		prepare = usr->query_skill_prepare();
		if ( sizeof(prepare) < 1) skill_type = "unarmed";
		else skill_type = (keys(prepare))[0];
	 }

	 attack_points = COMBAT_D->skill_power(usr, skill_type, SKILL_USAGE_ATTACK);
	 parry_points = COMBAT_D->skill_power(usr, "parry", SKILL_USAGE_DEFENSE);
	 dodge_points = COMBAT_D->skill_power(usr, "dodge", SKILL_USAGE_DEFENSE);
	 age_sec = usr->query("mud_age");

	 if (age_sec >= 864000) { // > 24 years old, 3*24 hours a year after 24
		age_years = 24;
		age_sec -= 864000;
		age_years += age_sec / 259200;
		age_decimal = age_sec % 259200;
		age_decimal = age_decimal / 25920;
	 }else { // < 24 years old, 24 hours a year
		age_years = 14;
		age_years += age_sec / 86400;
		age_decimal = age_sec % 86400;
		age_decimal = age_decimal / 8640;
	 }

	 printf("%s %s [%s] %s 师父：%s 年龄：%d.%d 存款：%s 进入地点：%s\n",
		usr->query("family/family_name"), usr->query("title"),
		usr->query("nickname"), usr->query("name"),usr->query("family/master_name"),
		age_years, age_decimal ,MONEY_D->money_str(usr->query("balance")), usr->query("startroom") );

	 printf("臂力: %d/%d 悟性: %d/%d 根骨: %d/%d 身法: %d/%d 容貌: %d/%d 福缘: %d/%d\n",
		usr->query_str(), usr->query("str"),
		usr->query_int(), usr->query("int"),
		usr->query_con(), usr->query("con"),
		usr->query_dex(), usr->query("dex"),
		usr->query_per(), usr->query("per"),
		usr->query_kar(), usr->query("kar"));
	 printf("死亡次数: %d (有效死亡 %d 次) 杀死人数: %d (杀死玩家 %d 人)\n",
		usr->query("death_count"), usr->query("death_times"),
		usr->query("MKS"), usr->query("PKS"));
	 printf("\n");
	 printf("精: %4d/%4d/%4d 精力: %5d/%5d ",
	usr->query("jing"),
	usr->query("eff_jing"),
	usr->query("max_jing"),
	usr->query("jingli"),
	usr->query("eff_jingli"));
	 printf("气: %4d/%4d/%4d 内力: %5d/%5d\n", usr->query("qi"),
	usr->query("eff_qi"),
	usr->query("max_qi"),
	usr->query("neili"),
	usr->query("max_neili"));
	 skills = usr->query_skills();
	 if (skills) {
		keys  = sort_array( keys(skills), (: strcmp :) );
		skill_num = sizeof(skills);
		for (i=0; i<skill_num; i++) {
	if (i % 2 == 0) printf("\n");
	lvl = skills[keys[i]];
	printf("%10s (%18s):%5d", CHINESE_D->chinese(keys[i]), keys[i], lvl);
	if (i % 2 == 0) printf(" | ");
		}
	 }else{
		  printf(" no skills\n");
	 }

	 printf("\n");
	 skills = usr->query_skill_map();
	 if (skills) {
		keys  = sort_array( keys(skills), (: strcmp :) );
		skill_num = sizeof(skills);
		for (i=0; i<skill_num; i++) {
	if (i % 2 == 0) printf("\n");
	lvl = usr->query_skill(keys[i]);
	if (prepare && prepare[keys[i]]) {
	  printf("*");
	}else{
	  printf(" ");
	}
	printf("%8s :%18s = %5d", CHINESE_D->chinese(keys[i]),
			 CHINESE_D->chinese(skills[keys[i]]), lvl);
	if (i % 2 == 0) printf(" | ");
		}
	 }else{
		printf("no skill map\n");
	 }
	 printf("\n");

	pmap = usr->query_skill_prepare();
	if (!pmap) pmap = ([]);
	skill = keys(valid_types);
	write("组合中的特殊拳术技能:");
	for (i=0; i<sizeof(skill); i++) {
		if( !usr->query_skill(skill[i]) || !pmap[skill[i]] ) continue;
			write(  valid_types[skill[i]] + " (" + skill[i] + ")" + "   " + to_chinese(pmap[skill[i]]) + " ");
	}

	 printf("\n\n经验: %9d 潜能: %4d/%4d   神: %9d\n", usr->query("combat_exp"),
		usr->query("potential"), usr->query("max_potential"),
		usr->query("shen"));
	 printf("攻击: %9d 招架: %9d 躲闪: %9d \n",
		attack_points, parry_points, dodge_points);
	 printf("apply: att=%d, dam=%d def=%d, dodge=%d, parry=%d, arm=%d, speed=%d\n",
		usr->query_temp("apply/attack"),
		usr->query_temp("apply/damage"),
		usr->query_temp("apply/defense"),
		usr->query_temp("apply/dodge"),
		usr->query_temp("apply/parry"),
		usr->query_temp("apply/armor"),
		usr->query_temp("apply/speed"));
}


int help(object me)
{
write(@HELP
指令格式：exam player.

用来检查玩家数据
HELP
	 );
	 return 1;
}

