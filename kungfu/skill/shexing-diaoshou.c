//Cracked by Roath
// shexing-diaoshou 蛇形刁手
// qfy August 21, 1996
//changed by wzfeng 2000 6
#include <ansi.h>
#include <combat.h>
inherit SKILL;
mapping *action = ({
([      "action" : "$N左掌护胸，右臂微举作蛇形，续而向外疾伸，一式「灵蛇出洞」攻向$n的$l",
        "force" : 140,
        "dodge" : 10,
        "damage_type" : "瘀伤",
        "lvl" : 0,
        "skill_name" : "灵蛇出洞"
]),
([      "action" : "$N大叫一声使出「虎头蛇尾」，右手虚晃掩饰中；左手从$n意想不到之处疾抓其$l",
        "force" : 180,
        "dodge" : -5,
        "damage_type" : "抓伤",
        "lvl" : 5,
        "skill_name" : "虎头蛇尾"
]),
([      "action" : "$N使出「画蛇添足」，双手向$n抓去，同时又无声无息地一脚踢向$n的$l",
        "force" : 200,
        "dodge" : 0,
        "damage_type" : "跌伤",
	  "lvl" : 10,
        "skill_name" : "画蛇添足"
]),
([      "action" : "只见$N跌扑于地，趁着$n向前探视，突然蹦起使出「杯弓蛇影」，向$n连抓几把",
        "force" : 230,
        "dodge" : -5,
        "damage_type" : "抓伤",
        "lvl" : 20,
        "skill_name" : "杯弓蛇影"
]),
([      "action" : "$N突然抱头欲逃，但却莫明其妙地滚近$n发出凌厉的攻势，好一招「蛇行鼠窜」",
        "force" : 260,
        "dodge" : 15,
        "damage_type" : "跌伤",
        "lvl" : 30,
        "skill_name" : "蛇行鼠窜"
]),
([      "action" : "$N一式「蛇鹰互搏」，双手带着嘶嘶破空之声，猛烈迅速地尽往$n上身要害攻击",
        "force" : 300,
        "dodge" : 5,
        "damage_type" : "瘀伤",
        "lvl" : 38,
        "skill_name" : "蛇鹰互搏"
]),
([      "action" : "$N双手徊旋中幻出万道蛇影，一招「万蛇汹涌」，诡异奇玄、铺天盖地推向$n",
        "force" : 330,
        "dodge" : 0,
        "damage_type" : "跌伤",
        "lvl" : 46,
        "skill_name" : "万蛇汹涌"
]),
([      "action" : "$N出其不意地使一式「白蛇吐信」，右手食中两指微分，闪电般地往$n的$l猛捅",
        "force" : 380,
        "dodge" : 0,
        "damage_type" : "瘀伤",
        "lvl" : 55,
        "skill_name" : "白蛇吐信"
]),
([      "action" : "突见$N双臂柔若无骨地伸缩着，使出「蛇磐青竹」缠住$n，右臂却悄悄地从不可思议处抹到$n的$l",
        "force" : 420,
        "dodge" : 5,
        "damage_type" : "跌伤",
        "lvl" : 65,
        "skill_name" : "蛇磐青竹"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="hand" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练蛇形刁手必须空手。\n");
        if (me->query("family/family_name")=="白驼山") {
        if ((int)me->query_skill("hamagong",1) < 15)
                return notify_fail("你的蛤蟆功火候不够，无法学蛇形刁手。\n");
        }
        else if ((int)me->query_skill("huntian-qigong", 1) < 15)
                return notify_fail("你的混天气功火候不够，无法学蛇形刁手。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练蛇形刁手。\n");
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
        int i, level,ob_lvl,attack;
		object ob;
		
		ob = me->select_opponent();
		level = (int)me->query_skill("shexing-diaoshou", 1)+1;
		
		attack=level/100;
		
		if(level>180
			&&random(level)>level*2/5
			&&(random(me->query_dex())>25)
			&&living(ob)
			&&me->query_skill_mapped("dodge") == "xiaoyaoyou"
			&&me->query("neili")>500
			&&(random(5)>2)
			&&!me->query_temp("gb_ds_auto")
			&&(me->query_temp("gb_huixuan")>1)
			)
	{
			message_vision(YEL "$N揉身而上，自左向右轻轻回旋一周，$n被$N的身行所迷惑，顿时放弃攻击，改为自守。\n" NOR, me,ob);
			ob->start_busy(random(3)+random(level/100));
			me->add("neili", -(100+random(100)));
		}

		

		if(level>150
			&&random(level)>level/3
			&&(random(me->query_dex())>20)
			&&living(ob)
			&&me->query_skill_mapped("dodge") == "xiaoyaoyou"
			&&!me->query_temp("gb_ds_auto")
			&&me->query("neili")>800
			&&(me->query_temp("gb_huixuan")>1)
			)
		{
				if(attack>4) attack=4;
				attack=random(attack);
				if(attack<=1) attack=1;
message_vision(HIY "紧接着，$N口中发出“嘶嘶”的声音，双手半曲，三指上竖成蛇状，陪合着潇遥步法，有如急风暴雨般攻出了"+
			   chinese_number(attack+1)+"招。\n" NOR, me);
					for(i=0;i<attack;i++)
					{
						me->add("neili", -(50+random(50)));
						
						ob = me->select_opponent();
						if(!living(ob))
						{
						break;
						}
						me->set_temp("gb_ds_auto",1);
						COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);  
						me->delete_temp("gb_ds_auto");
					}
		}


        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练蛇形刁手。\n");
        me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"shexing-diaoshou/" + action;
}

