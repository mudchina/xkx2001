//Cracked by Roath
// yunu-jian 玉女剑法
// maco 版本  1999/1/17  (不开放，纯测试)

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

int ke_qz(object me, object victim, object weapon, int damage);

mapping *action = ({
([      "action":"$N手中$w自上而下，一招「花前月下」，$w颤动，如鲜花招展风中，来回挥削，只幌得$n眼花撩乱，浑不知剑招将从何处攻来",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "花前月下",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N$w微摆，一招「抚琴按箫」，轻灵跳脱，丰姿绰约，剑法吞吐激扬，宛然名家风范",
        "force" : 180,
        "dodge" : 5,
        "parry" : 5,
        "damage": 25,
        "lvl" : 9,
        "skill_name" : "抚琴按箫",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N一招「扫雪烹茶」，风仪娴雅，姿形端丽，举手投足间飘飘有出尘之想，$w颤动，身随剑起，刺向$n$l",
        "force" : 200,
	"dodge" : 10,
        "parry" : 10,
        "damage": 60,
        "lvl" : 15,
        "skill_name" : "扫雪烹茶",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action": "$N一招「清饮小酌」，提起$w剑柄，剑尖下指，有如提壶斟酒，忽尔挑剑疾刺$n$l，剑法之怪，匪夷所思",
        "force" : 240,
	"dodge" : 15,
        "parry" : 15,
        "damage": 40,
        "lvl" : 25,
        "skill_name" : "清饮小酌",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N脚步微动，向左踏出两步，化做一招「下对弈」，剑法迅捷，灵动变幻，不但剑招凌厉，而且丰神脱俗，姿式娴雅",
        "force" : 280,
	"dodge" : 8,
        "parry" : 8,
        "damage": 70,
        "lvl" : 30,
        "skill_name" : "松下对弈",
	"post_action": (: ke_qz :),	
        "damage_type":  "割伤"
]),
([      "action":"$N纤腰微摆，一招「池边调鹤」，$w急刺$n$l，这一招去势快如星驰电闪，抑且风姿绰约，飘逸无比",
        "force" : 300,
        "dodge" : 10,
        "parry" : 10,
        "damage": 55,
        "lvl" : 35,
        "skill_name" : "池边调鹤",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N$w轻扬，飘身而进，姿态飘飘若仙，剑锋向$n的$l连点数点，却是一招「小园艺菊」",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "小园艺菊",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N进退趋避，一式「西窗夜话」，灵台澄澈，剑路虽越出越急，心中却无半点杂念，将$w使得精妙迅疾，来去无踪",
        "force" : 320,
	"dodge" : 5,
        "parry" : 5,
	"damage": 75,
	"lvl" : 55,
	"skill_name" : "西窗夜话",
	"post_action": (: ke_qz :),	
	"damage_type":  "刺伤"
]),
([      "action":"$N$w抖动，闪出十余点银光，正是一招「冷月窥人」，转瞬间剑尖已将$n上半身尽数笼罩",
        "force" : 330,
        "dodge" : 8,
	"parry" : 8,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "冷月窥人",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N身子一旋，一式「彩笔画眉」，$w微微两颤，横剑斜削$n$l，招数极其奇巧奥妙",
        "force" : 360,
	"dodge" : 10,
        "parry" : 10,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "彩笔画眉",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N轻飘飘的向後略退，一招「琴心暗通」，$w陡地反转倒刺，叮叮叮叮十二下急响，纵是琵琶高手的繁弦轮指也无如此急促",
        "force" : 380,
	"dodge" : 10,
        "parry" : 10,
        "damage": 85,
        "lvl" : 75,
        "skill_name" : "琴心暗通",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N一挥$w，立时寒光闪闪，$w便似银蛇般四下游走，一招「皓腕玉镯」，$n但见剑光从眼前掠过，陡觉$l上一凉",
        "force" : 400,
	"dodge" : 20,
        "parry" : 20,
        "damage": 100,
        "lvl" : 80,
        "skill_name" : "皓腕玉镯",
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry" || usage == "zuoyou-hubo"; }

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
        int i, level;
        object victim;
        level   = (int) me->query_skill("yunu-jian",1);
        if( !victim && me->is_fighting() ) victim = offensive_target(me);
	if (random(level) > 350 && random(me->query("neili")) > 1000 )
return ([      "action":HIW"$N急退急趋，纵上连刺三剑，$w"+HIW"飘忽来去，东刺西击，这一路玉女剑法更见使得英气爽朗，顾盼生姿！"NOR,
        "force" : 450 + me->query_skill("yunu-jian"),
	"dodge" : 10,
        "parry" : 10,
        "damage": 100,
        "lvl" : 75,
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]);
	else if (random(level) > 250 && random(me->query("neili")) > 1000 ){
	if (me->query("gender")== "男性") {
return ([      "action":HIG"$N剑走轻灵，招断意连，绵绵不绝，当真是闲雅潇洒，翰逸神飞，大有晋人乌衣子弟裙屐风流之态！"NOR,
        "force" : 450 + me->query_skill("yunu-jian"),
	"dodge" : 10,
        "parry" : 10,
        "damage": 100,
        "lvl" : 75,
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]);
}
	else {
return ([      "action":HIY"$N满场游走，$w"+HIY"上一招未毕，二招至，剑招初出时人尚在左，剑招抵敌时身已转右，竟似剑是剑，人是人，两者殊不相，$n望之不禁骇然！"NOR,
        "force" : 450 + me->query_skill("yunu-jian"),
	"dodge" : 10,
        "parry" : 10,
        "damage": 100,
        "lvl" : 75,
	"post_action": (: ke_qz :),	
        "damage_type":  "刺伤"
]);
	}
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
                return notify_fail("你的精力不够练玉女剑法。\n");
        me->receive_damage("jingli", 25, "精力透支过度死了。");
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"yunu-jian/" + action;
}

int ke_qz(object me, object victim, object weapon, int damage)
{
        string str;
        int skill,v_parry;
	object weapon2;
	weapon2 = victim->query_temp("weapon");
	skill = me->query_skill("yunu-jian");

        if(skill > 80 ){
	if (damage==RESULT_DODGE
	&& victim->query_skill_mapped("dodge") == "jinyangong" 
	&& (random(skill)/2 + skill/2) > random(victim->query_skill("jinyangong"))) {

	message_vision(HIW"岂知$N深悉金雁功的诸般巧妙变著，左脚勾出，正好算在$n闪躲之处，配合得丝丝入扣，$n被$P一勾，当即仰天摔倒！\n"NOR, me,victim );
	victim->start_busy(8);
	victim->receive_damage("qi", random(skill)+skill);
        str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("( $N"+str+")\n", victim);	
	}
	else if (damage==RESULT_PARRY 
	&& ( objectp(weapon2 = victim->query_temp("weapon")) 
&& (((victim->query_skill_mapped("parry") == "quanzhen-jian" &&(string)weapon2->query("skill_type") == "sword")
|| (victim->query_skill_mapped("parry")== "duanyun-bian" && (string)weapon2->query("skill_type") == "whip")))
&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry")) )) {

	message_vision(HIW"$n突觉自己手中"+weapon2->name()+HIW"不挺自伸，竟被$N手中"+weapon->name()+HIW"黏了过去，一惊之下，急运内力回夺。\n"NOR, me,victim );
	message_vision(HIW"双力互夺，只微一凝持，$N突然放开"+weapon->name()+HIW"，双掌直欺，猛击$n前胸，同时"+weapon->name()+HIW"剑柄反弹上来，双掌一剑，三路齐至，怪异之极！\n"NOR, me,victim );
	if (random(me->query("combat_exp")) > random(victim->query("combat_exp"))){
	message_vision(HIW"$n只得撒下"+weapon2->name()+HIW"，并手横胸，急挡一招！\n"NOR, me,victim );
        weapon2->unequip();
	weapon2->move(environment(me));
	}
        weapon->unequip();
        me->add_temp("apply/speed", skill*10);
        me->add_temp("apply/damage", skill*10);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->add_temp("apply/speed", -skill*10);
        me->add_temp("apply/damage", -skill*10);
        weapon->wield();
        message_vision("\n$N反应快捷，又已抄起"+weapon->name()+"握在手中！\n", me,victim );
        me->add("neili",-40);
}
	else if (damage==RESULT_PARRY 
	&& ( !objectp(weapon2 = victim->query_temp("weapon")) 
&& ((victim->query_skill_mapped("parry") == "quanzhen-jian" )
|| (victim->query_skill_mapped("parry")== "chunyang-quan")
|| (victim->query_skill_mapped("parry")== "sanhua-juding")
|| (victim->query_skill_mapped("parry")== "duanyun-bian"))
&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry")) )) {

	message_vision(HIW"不料$n随即挺剑一刺，回剑既快且准，直削$n手掌，正是全真武功所难以守御之处，$n心下大惊，急忙缩手，守势立破，$N次招又至！\n"NOR, me,victim );
        me->add_temp("apply/speed", skill*10);
        me->add_temp("apply/damage", skill*10);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->add_temp("apply/speed", -skill*10);
        me->add_temp("apply/damage", -skill*10);
	me->add("neili",-40);
		}
	}
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level;
        level  = (int) me->query_skill("yunu-jian",1);

	if( victim->query_temp("sanhua") ) {
	victim->delete_temp("sanhua");
	victim->start_busy(1+random(1));
	victim->add("neili",-200);
	victim->receive_wound("qi", level*3+random(level));
	victim->receive_damage("qi", level*10);

	return HIR"$n突然双目直瞪，砰的一声，翻身摔倒，竟已受了极重的暗伤，先天护体神功已然被破！\n"NOR;
			}
			
}