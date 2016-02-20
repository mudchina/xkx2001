//Cracked by Roath
//dugu-jiujian.c 独孤九剑
//by qfy 
//June 17, 96

inherit SKILL;

string *dodge_msg = ({
	"$n挺剑一招象是「白云出岫」回刺$N的$l，企图将$N的攻势化解。\n",
	"$n不闪不避，举剑闪电般使出「叠翠浮青」反削$N的$l，想挡过$N此招。\n",
	"只见$n不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地指向$N的$l。\n",
	"$n运剑如风，剑光霍霍中反攻$N的$l，尝试逼$N自守，剑招似是「伏魔剑」的「龙吞式」。\n",
	"$n以攻为守，以进为退，凝神运气向$N猛攻快打地挥出方位大异的泰山「快活三」三剑。\n",
	"却见$n踏前一步，剑式斜指$N的$l，想要使$N闪身而退。\n",
	"$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」回攻$N。\n",
	"$n举剑狂挥，迅速无比地点向$N的$l，却令人看不出其所用是什么招式。\n",
});

mapping *action = ({
([      "action":"$N挺剑回刺$n的$l。此招象是华山剑法的「白云出岫」，嵩山剑法的「万岳朝宗」，逼得$n回守，停止对$N的攻势",
	"force" : 100,
	"dodge" : 15,
	"damage" : 25,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([      "action":"$n窥准$N一招华山剑法「有风来仪」的趋势，准备进行反击，却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招",
        "force" : 110,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 1,
        "damage_type" : "刺伤"
]),
([      "action":"只见$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的$l",
	"force" : 130,
	"dodge" : 15,
	"damage" : 30,
	"lvl" : 5,
	"damage_type" : "割伤"
]),
([      "action":"$N飞身跃起，出剑宛如「金雁横空」，但不等剑招变老，已转为「风声鹤泣」，剑尖划向$n的$l",
	"force" : 150,
	"dodge" : 20,
	"damage" : 35,
	"lvl" : 7,
	"damage_type" : "割伤"
]),
([      "action":"$N突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，$w对着$n一绞，企图突破$n的攻势",
        "force" : 160,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 10,
        "damage_type" : "割伤"
]),
([      "action":"但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n的$l",
	"force" : 165,
	"dodge" : 10,
	"damage" : 40,
	"lvl" : 12,
	"damage_type" : "割伤"
]),
([      "action":"$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑式有如云卷雾涌，旁观者不由得目为之眩",
	"force" : 170,
	"dodge" : 15,
	"damage" : 40,
	"lvl" : 15,
	"damage_type" : "割伤"
]),
([      "action":"$n攻向$N的$l，$N不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周",
	"force" : 175,
	"dodge" : 15,
	"damage" : 42,
	"lvl" : 18,
	"damage_type" : "割伤"
]),	
([      "action":"$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中途，突然转向，大出$n意料之外",
        "force" : 180,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 20,
        "damage_type" : "割伤"
]),
([      "action":"$N剑光一吐，长剑化作一道白虹，向$n直刺过去。这一招端严雄伟，似是嵩山剑法中的「千古人龙」，又似是华山剑法的「无边落木」",
        "force" : 185,
        "dodge" : 5,
        "damage" : 63,
        "lvl" : 23,
        "damage_type" : "刺伤"
]),
([      "action":"$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱削",
        "force" : 190,
        "dodge" : 15,
        "damage" : 65,
        "lvl" : 26,
        "damage_type" : "刺伤"
]),
([      "action":"$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的是这十九剑便如一招，手法之快，直是匪夷所思",
        "force" : 195,
        "dodge" : 10,
        "damage" : 68,
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "action":"$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去",
	"force" : 200,
        "dodge" : 10,
        "damage" : 70,
        "lvl" : 33,
        "damage_type" : "割伤"
]),
([      "action":"却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟化「泰山十八盘」为一剑攻向$n",
	"force" : 205,
        "dodge" : 10,
        "damage" : 72,
        "lvl" : 36,
        "damage_type" : "割伤"
]),
([      "action":"$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「天柱云气」及「雁回祝融」衡山五神剑",
	"force" : 212,
        "dodge" : 10,
        "damage" : 75,
        "lvl" : 39,
        "damage_type" : "割伤"
]),
([      "action":"$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山剑势击向$n",
        "force" : 220,
        "dodge" : 10,
        "damage" : 77,
        "lvl" : 42,
        "damage_type" : "割伤"
]),
([      "action":"$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺向$n",
	"force" : 230,
        "dodge" : 15,
        "damage" : 80,
        "lvl" : 47,
        "damage_type" : "刺伤"
]),
([      "action":"$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏摩剑」剑意表露无遗",
	"force" : 240,
        "dodge" : 5,
        "damage" : 82,
        "lvl" : 52,
	"damage_type" : "割伤"
]),
([      "action":"$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽源源不绝地缠向$n",
	"force" : 250,
        "dodge" : 10,
        "damage" : 85,
	"lvl" : 58,
	"damage_type" : "割伤"
]),
([      "action":"$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力却是奇大，$n难以看清剑招来势",
	"force" : 270,
	"dodge" : 15,
	"damage" : 87,
	"lvl" : 64,
	"damage_type" : "刺伤"
]),
([      "action":"$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法",
	"force" : 290,
	"dodge" : 10,
	"damage" : 89,
	"lvl" : 72,
	"damage_type" : "刺伤"
]),
([      "action":"$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，$n不得不守",
	"force" : 320,
	"dodge" : 0,
	"damage" : 91,
	"lvl" : 78,
	"damage_type" : "割伤"
]),
([      "action":"$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的虚实",
	"force" : 350,
	"dodge" : 15,
	"damage" : 93,
	"lvl" : 85,
	"damage_type" : "刺伤"
]),
([      "action":"$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n的$l",
	"force" : 370,
	"dodge" : 5,
	"damage" : 96,
	"lvl" : 90, 
	"damage_type" : "刺伤"
]),
([      "action":"$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好",
	"force" : 420,
	"dodge" : 10,
	"damage" : 100,
	"lvl" : 95,
        "damage_type" : "刺伤"
]),
([      "action":"$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议",
	"force" : 470,
	"dodge" : 5,
	"damage" : 110,
	"lvl" : 98,
	"damage_type" : "刺伤"
]),
([      "action":"$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测",
	"force" : 500,
	"dodge" : 10,
	"damage" : 120,
	"lvl" : 100,
	"damage_type" : "刺伤"
]),
});	                                  

int valid_enable(string usage) 
{ 
	object weapon;

	if (this_player()->query("family/master_id") != "feng qingyang" 
	&& !wizardp(this_player()) )
		return notify_fail("你已叛离风清扬，怎么好意思再用他所传的剑法！\n");
	
        if (objectp(weapon = this_player()->query_temp("weapon"))
        && (string)weapon->query("skill_type") == "sword")
		return usage == "sword" || usage == "parry" || usage == "dodge"; 
	else
		return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((string)me->query("family/master_id") != "feng qingyang" )
                return notify_fail("你不能向其他玩家学习独孤九剑。\n");
        if ((int)me->query_skill("sword", 1) < 50)
        	return notify_fail("你的基本剑法火候太浅。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("taiji-jian", 1) > 0 || (int)me->query_skill("damo-jian", 1) > 0
	|| (int)me->query_skill("fumo-jian", 1) > 0 || (int)me->query_skill("huashan-jianfa", 1) > 0
	|| (int)me->query_skill("emei-jianfa", 1) > 0 )
		return notify_fail("你身具其他剑法，受其拘束，无法领会独孤九剑「无招」的妙旨。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("dugu-jiujian",1);
	
	if ( me->query_str() >= 30 && me->query_int() >= 36 
	&& random(me->query_skill("dugu-jiujian",1)) > 80 
	&& me->query_skill("force") > 150 && me->query("neili") > 400 
	&& (string)weapon->query("id") == "xuantie jian" ) {
	   me->add("neili", -100);
	   return ([
	   "action" : "$N脸色凝重虔诚，缓缓举起玄铁重剑，突然跃起身剑合一，驭剑化为一道黑气向$n冲刺而去",
	   "damage" : 500,
	   "damage_type" : "刺伤"
	   ]);
	}

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
                return notify_fail("你的精力不够练独孤九剑。\n");
        me->receive_damage("jingli", 15, "精力透支过度死了");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"dugu-jiujian/" + action;
}
