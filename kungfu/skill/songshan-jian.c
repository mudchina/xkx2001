//Cracked by Roath
// songshan-jian.c 嵩山剑法 
// maco 

#include <ansi.h>
#include <combat.h>

inherit SKILL;
int next_sword(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action":"$N$w一立，举剑过顶，弯腰躬身，使一招「万岳朝宗」，正是嫡系正宗的嵩山剑法，突然间剑光一吐，$w化作一道白虹，向$n直刺过来",
	"force" : 100,
        "dodge" : 5,
	"parry" : 5,
	"damage": 0,
	"lvl" : 0,
	"skill_name" : "万岳朝宗",
	"damage_type":	"刺伤"
]),
([	"action":"$N一剑自上而下，朝$n$l直劈下去，这一招「独劈华山」虽平平无奇，但呼的一声响，从空中疾劈而下，确有开山裂石的声势",
	"force" : 180,
        "dodge" : 5,
	"parry" : 5,
	"damage": 30,
	"lvl" : 10,
	"skill_name" : "独劈华山",
	"damage_type":	"割伤"
]),
([	"action":"$N左手向外一分，右手$w向右掠出，使的是一招「开门见山」，招数堂皇，势道凌厉，$w直扫$n$l",
	"force" : 260,
        "dodge" : 8,
	"parry" : 8,
	"damage": 70,
	"lvl" : 20,
	"skill_name" : "开门见山",
	"damage_type":	"割伤"
]),
([	"action":"$N忽尔使出一招「千古人龙」，气度清隽，但虚虚实实，後着甚多，这一剑离$n尚有尺许，便已缩转，一斜身，$w转向$n$l削落",
	"force" : 330,
        "dodge" : 10,
	"parry" : 0,
	"damage": 80,
	"lvl" : 30,
	"skill_name" : "千古人龙",
	"damage_type":	"刺伤"
]),
([	"action":"$N剑路轻灵，使出一招「叠翠浮青」，$w颤动，剑锋上冷光闪动，刷刷刷连环三剑，攻得$n险象环生",
	"force" : 400,
        "dodge" : 15,
	"parry" : 15,
	"damage": 70,
	"lvl" : 32,
	"skill_name" : "叠翠浮青",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w寒光连闪，这一招「玉井天池」威仪整肃，气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽显堂堂之阵、正正之师的气度",
	"force" : 450,
        "dodge" : 15,
	"parry" : 15,
	"damage": 100,
	"lvl" : 50,
	"skill_name" : "玉井天池",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w自左而右急削过去，使出嵩山派正宗剑法「天外玉龙」，$w如灵蛇，如神龙，剑身似曲似直，便如一件活物一般，奔腾矫夭，气势雄浑",
	"force" : 500,
        "dodge" : 10,
	"parry" : 10,
	"damage": 120,
	"lvl" : 60,
	"skill_name" : "天外玉龙",
	"damage_type":	"割伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
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

        int i, level, xuli;
	level   = (int) me->query_skill("songshan-jian",1);
	xuli = me->query_temp("songshan_xuli");

	if (me->query_temp("s_hit"))
	return ([
	"action":HIW"突然间寒光一闪，$N手中$w"+HIW"直刺向$n，剑上震荡而发巨声，实是乾坤一掷的猛击，一剑之出，具雷霆万钧之势！"NOR,
        "force" : 500 + xuli/5,
	"dodge" : 10,
        "parry" : 10,
        "damage": 200 + xuli/10,
	"post_action": (: next_sword :),	
        "damage_type":  "刺伤"
]);

	
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练嵩山剑法。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"songshan-jian/" + action;
}


int next_sword(object me, object victim, object weapon, int damage)
{
	int wap,wdp;
	object ob;
	ob = victim->query_temp("weapon");
        if(victim->query("eff_qi") < 0 && victim->query("qi") < 0) 
        {
        message_vision(HIW"紧跟着剑光带过，"+weapon->name()+HIW"一剑从$n左肩直劈到右腰，这一剑势道之凌厉，端的是匪夷所思，只是闪电般一亮，$n已被斩成两截！\n"NOR, me,victim );
        
        }
        	
        else if( damage==RESULT_PARRY && objectp(ob = victim->query_temp("weapon")) ) 
        {
                
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query_str()
                        + (int)me->query("jiali")
                        + (int)me->query_skill("songshan-jian")/3
                        + me->query_temp("songshan_xuli");
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str()
                        + (int)victim->query("jiali")
                        + (int)victim->query_skill("parry")/3;
                wap = random(wap/2)+wap/2;

                if( wap > 3 * wdp ) {
	message_vision(HIY"$N手上"+weapon->name()+HIY"连连催劲，「」的一声响，与$n的"+ob->name()+HIY"一撞，喀喀喀十余声轻响过去，$n手中"+ob->name()+HIY"寸断，折成数十截掉在地下！\n"NOR, me,victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断碎的" + ob->query("name"));
//                      ob->set("value", (int)ob->query("value") / 10);
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else if( wap > 2 * wdp ) {
                        message_vision(HIW"但是$N手上"+weapon->name()+HIW"连连催劲，$n手臂酸麻，虎口剧痛，"+ob->name()+HIW"登时脱手！\n" NOR,me,victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$N只觉得手中" + ob->name() + "一震，险些脱手！\n",
                                victim);
                } else {
                        message_vision("$N的" + weapon->name() + "和$n的" + ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                }
        }

        return 1;
}
