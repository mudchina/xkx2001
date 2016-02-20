//Cracked by Roath
// quanzhen-jianfa ȫ�潣��
// by sdong

#include <ansi.h>
#include <combat.h>

inherit SKILL;
#include "/kungfu/skill/force_list.h"

mapping *action = ({
([	"action":"$N�ζ�$w��̤���ţ���ƫ�棬������˼�����һ�������ޱȵġ��ֻ�������������ʵ�ң��ѵ���$n$l",
	"force" : 150,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "�ֻ�����",
	"damage_type":	"����"
]),
([	"action":"$Nʹһ�С���������������������Ʈ������$w����ʵʵ�ó����㺮������$n$l",
	"force" : 180,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 9,
	"skill_name" : "��������",
	"damage_type":	"����"
]),
([	"action":"$N������$nһת����Ȼһʽ���ɨҶ������$w������콣Ӱ��Ю�ž�����$nɨȥ",
	"force" : 250,
	 "dodge" : 10,
	"parry" : 10,
	"damage": 60,
	"lvl" : 25,
	"skill_name" : "�ɨҶ",
	"damage_type":	"����"
]),
([	"action":"$N���쳤Ц������ƮȻ�����ڰ��������һ����һʽ�����ʹ��������$w����ػ���$n��$l",
	"force" : 380,
	 "dodge" : 15,
	"parry" : 15,
	"damage": 75,
	"lvl" : 32,
	"skill_name" : "���ʹ��",
	"damage_type":	"����"
]),
([	"action":"$N�������Ž���������̤��һ�С������롱����б�̣�$w��ȻԾ��ٿ�Ļ��������ǹ�����$n��$l",
	"force" : 220,
	 "dodge" : 8,
	"parry" : 8,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "������",
	"damage_type":	"����"
]),
([	"action":"$N��ǰ��ȥһ�󲽣�ʹ����̽��������������$w���һ������Ѹ�����׻���$n��$l",
	"force" : 350,
		  "dodge" : 10,
	"parry" : 10,
	"damage": 65,
	"lvl" : 48,
	"skill_name" : "̽������",
	"damage_type":	"����"
]),
([	"action":"$N����һ��$w��һʱ�������仨����$w�ó���㽣����ƮȻ����$n��$l",
	"force" : 310,
		  "dodge" : 15,
	"parry" : 15,
	"damage": 35,
	"lvl" : 56,
	"skill_name" : "�����仨",
	"damage_type":	"����"
]),
([	"action":"$N����$wһָ���������࣬һʱ������Į������$w����������$n��$l",
	"force" : 310,
		  "dodge" : 15,
	"parry" : 15,
	"damage": 45,
	"lvl" : 62,
	"skill_name" : "����Į��",
	"damage_type":	"����"
]),
([      "action":"$N���һ����һ�С��׺羭�졹��$w����㻮��һ����Բ������$n��$l",
	"force" : 390,
	 "dodge" : 5,
	"parry" : 5,
	 "damage": 65,
	 "lvl" : 70,
	 "skill_name" : "�׺羭��",
	 "damage_type":  "����"
]),
([      "action":"$N��������Ʈ��ͻȻһת����ͷ�½��ϣ�����$w��һ�С���׹��������������Ϣ�ع���$n��$l",
		  "force" : 410,
		  "dodge" : 8,
		"parry" : 8,
		  "damage": 65,
		  "lvl" : 75,
		  "skill_name" : "��׹����",
		  "damage_type":  "����"
]),
([	"action":"$N����$wһ����һ�С�������Ե����$w�Ƴ�ҫ�۹�â����������$n",
	"force" : 400,
	 "dodge" : 10,
	"parry" : 10,
	"damage": 85,
	"lvl" : 80,
	"skill_name" : "������Ե",
	"damage_type":	"����"
]),
([	"action":"$N��Ȼ���θ߸�Ծ��ʹ�����˼����ġ���$w�ó����컨�꣬Ѹ����������$n��$l",
	"force" : 450,
	 "dodge" : 20,
	"parry" : 20,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "�˼�����",
	"damage_type":	"����"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry" || usage == "zuoyou-hubo" ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
    if ((int)me->query_skill("xiantian-gong", 1) < 10
		&& (int)me->query_skill("yunu-xinjing", 1)<25)
		return notify_fail("������칦���̫ǳ��\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
		  for(i = sizeof(action)-1; i >= 0; i--)
					 if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
		  int i, level;
	level   = (int) me->query_skill("quanzhen-jian",1);
		  for(i = sizeof(action); i > 0; i--)
					 if(level > action[i-1]["lvl"])
								return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ���������ȫ�潣����\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
		  return __DIR__"quanzhen-jian/" + action;
}
