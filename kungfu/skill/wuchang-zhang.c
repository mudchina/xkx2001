//Cracked by Roath
// wuchang-zhang.c 无常杖法

inherit SKILL;

mapping *action = ({
([	"action":"$N微一躬身，一招「庸人自扰」，$w带着刺耳的吱吱声，擦地扫向$n的脚踝",
	"force" : 100,
        "dodge" : -10,
        "parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "庸人自扰",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「想入非非」，右手托住杖端，左掌居中一击，令其凭惯性倒向$n的肩头",
	"force" : 110,
        "dodge" : -10,
        "parry" : 10,
	"damage": 15,
	"lvl" : 7,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "想入非非",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「六神不安」，举起$w乒乒乓乓地满地乱敲，让$n左闪右避，狼狈不堪",
	"force" : 120,
        "dodge" : -5,
        "parry" : 5,
	"damage": 20,
	"lvl" : 14,
	"skill_name" : "六神不安",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「面无人色」，举起$w，呆呆地盯了一会，突然猛地一杖打向$n的$l",
	"force" : 130,
        "dodge" : -5,
        "parry" : 5,
	"damage": 20,
	"lvl" : 20,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "面无人色",
	"damage_type":"挫伤"
]),
([	"action":"$N将$w顶住自己的胸膛，一端指向$n，一招「心惊肉跳」，大声叫喊着冲向$n",
	"force" : 140,
        "dodge" : -15,
        "parry" : 15,
	"damage": 30,
	"lvl" : 25,
	"skill_name" : "心惊肉跳",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「行尸走肉」，全身僵直，蹦跳着持杖前行，冷不防举杖拦腰向$n劈去",
	"force" : 150,
        "dodge" : 5,
        "parry" : -15,
	"damage": 30,
	"lvl" : 30,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "行尸走肉",
	"damage_type":"挫伤"
]),
([	"action":"$N面带戚色，一招「饮恨吞声」，趁$n说话间，一杖向$n张大的嘴巴捅了过去",
	"force" : 300,
        "dodge" : -5,
        "parry" : 20,
	"damage": 40,
	"lvl" : 35,
	"skill_name" : "饮恨吞声",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「力不从心」，假意将$w摔落地上，待$n行来，一脚勾起，击向$n的$l",
	"force" : 350,
        "dodge" : -5,
        "parry" : 25,
	"damage": 40,
	"lvl" : 40,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "力不从心",
	"damage_type":"挫伤"
]),
([	"action":"$N伏地装死，一招「穷途没路」，一个翻滚，身下$w往横里打出，挥向$n的裆部",
	"force" : 400,
        "dodge" : -5,
        "parry" : 25,
	"damage": 50,
	"lvl" : 45,
	"skill_name" : "穷途没路",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「呆若木鸡」，身不动，脚不移，$w却直飞半空，不偏不倚地砸向$n的$l",
	"force" : 450,
        "dodge" : -5,
        "parry" : 25,
	"damage": 50,
	"lvl" : 50,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "呆若木鸡",
	"damage_type":"挫伤"
]),
([	"action":"$N高举$w，一招「人鬼殊途」，身形如鬼魅般飘出，对准$n的天灵盖一杖打下",
	"force" : 500,
        "dodge" : -5,
        "parry" : 25,
	"damage": 60,
	"lvl" : 55,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "人鬼殊途",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「我入地狱」，单腿独立，$w舞成千百根相似，根根砸向$n全身各处要害",
	"force" : 550,
        "dodge" : -5,
        "parry" : 25,
	"damage": 60,
	"lvl" : 60,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "我入地狱",
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
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
	level   = (int) me->query_skill("wuchang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if (me->query_str() < 20)
                return notify_fail("你的臂力不够练无常杖法。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练无常杖法。\n");

        if( (int)me->query_skill("qianye-shou", 1) < 100 )
                return notify_fail("你的如来千叶手修为还不够。\n");

	me->receive_damage("jingli", 20);
        if(me->query_skill("wuchang-zhang", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("wuchang-zhang", 1) > 150)
        me->receive_damage("jingli", 5);
	return 1;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("zui-gun", 1) >= 200
        &&  (int)me->query_skill("wuchang-zhang", 1) >= 200
        &&  !me->query("sl_gifts/zg") ) {
                me->add("dex", 1);
                me->set("sl_gifts/zg", 1);
                write("\n你的醉棍和无常杖学有所成，提高了你的身法。\n");
        }
}
