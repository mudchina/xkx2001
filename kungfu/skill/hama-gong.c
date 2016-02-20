//Cracked by Roath
// 蛤蟆功 (西元两千年大翻修版本)
// maco 2/1/ 2000

inherit FORCE;
inherit SKILL;
string check() { return "force"; }

#include "/kungfu/skill/force_list.h"
#include <ansi.h>

mapping *action = ({
([      "action": "$N劲由心生，蛤蟆功内劲迸发，一股热气从丹田中直冲上来，双腿一弯，口中阁的一声叫喝，手掌便朝$n推出",
	"dodge": -15,
	"parry": -20,
	"force": 300,
	"lvl" : 0,
	"damage": 20,
	"damage_type": "内伤"
]),
([      "action":"$N猛喝一声，双掌倏向$n$l推出，掌力疾冲而去，劲力十分猛恶，祗隐听得呼呼风响，声音劲急，非同寻常",
	"parry": 15,
	"force": 380,
	"lvl" : 105,
	"damage": 40,
	"damage_type": "内伤"
]),
([      "action":"$N蹲下身子，“咕”的一声大叫，猛地双掌推出。$n突觉一股排山倒海般的力道撞来，猛迅无伦",
	"dodge": 25,
	"force": 400,
	"lvl" : 110,
	"damage": 40,
	"damage_type": "内伤"
]),
([      "action":"$N蹲低身子，发掌向$n击去，左掌右掌，连环邀击，双掌连绵而上，掌法愈厉，乘势不住追击，後著凌厉之极",
	"dodge": -35,
	"force": 420,
	"lvl" : 115,
	"damage": 60,
	"damage_type": "瘀伤"
]),
([      "action":"$N凝立如山，一掌掌缓缓的劈将出去，掌风沉雄凌厉，招数变化精微，奥妙无穷",
	"dodge": 10,
	"force": 420,
	"lvl" : 115,
	"damage": 40,
	"damage_type": "内伤"
]),
([      "action":"$N“阁”的一声大叫，发劲急推，双掌一上一下，一放一收，斗然击出，朝著$n排山倒海般劈将过来",
	"dodge": 20,
	"force": 400,
	"lvl" : 120,
	"damage": 90,
	"damage_type": "瘀伤"
]),
([      "action":"$N身子蹲下，双掌平推而出，口中咯咯大叫，身子一幌一幌。这一推劲力极大，去势却慢，看来平平无奇，内中却是暗藏极大潜力",
	"dodge": 0,
	"force": 500,
	"lvl" : 125,
	"damage": 50,
	"damage_type": "内伤"
]),
([      "action":"$N蹲在地下，咕咕咕的叫了几声，内力崩涌，丹田中一股热气激升而上，身子猛跃而起，双掌推出，一股凌厉之极的掌风随之朝$n压到",
	"dodge": 10,
	"force": 540,
	"lvl" : 130,
	"damage": 100,
	"damage_type": "内伤"
]),
});

mapping *reverse_action = ({
([      "action": "忽听$N大叫三声，三个筋斗翻将出来，大吼一声，恶狠狠的朝$n扑将上来",
	"dodge": -15,
	"parry": -20,
	"force": 280,
	"damage": 50,
	"damage_type": "跌伤"
]),
([      "action":"但见$N疯势更加厉害，口吐白沫，举头朝$n猛撞",
	"parry": 15,
	"force": 290,
	"damage": 60,
	"damage_type": "瘀伤"
]),
([      "action":"$N蓦地张口，白牙一闪，已向$n$l咬落，又快又准",
	"dodge": -5,
	"force": 300,
	"damage": 65,
	"weapon": "牙齿",
	"damage_type": "咬伤"
]),
([      "action":"$N一口唾沫急吐，势挟劲风，竟将痰涎唾沫也当作了攻敌利器",
	"dodge": -45,
	"force": 350,
	"damage": 70,
	"weapon":"唾沫",
	"damage_type": "刺伤"
]),
([      "action":"$N忽然张嘴，一口唾沫往$n脸上吐去，发掌击向$n趋避的方位，同时又是一口浓痰吐将过来",
	"dodge": 30,
	"force": 320,
	"damage": 100,
	"weapon" : "浓痰",
	"damage_type": "刺伤"
]),
([      "action":"此时$N所使的招数更是希奇古怪，诡异绝伦，身子时而倒竖，时而直立，忽然一手撑地，身子横挺，一手出掌打向$n$l",
	"dodge": 10,
	"force": 420,
	"damage": 90,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) {
	if (usage == "force" || usage == "parry" ) return 1;
	if (usage == "strike") {
		if (this_player()->query_skill("hama-gong",1) < 100) {
			write("你的蛤蟆功火候不足，无法运用它到掌法中。\n");
			return 0;
		}
		return 1;
	}
	return 0;
}


/*string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	if(level >= action[i]["lvl"])
		return action[i]["skill_name"];
	return "蛤蟆功";
}*/
mapping query_action(object me, object weapon)
{
	int i, level;
	string *power_msg = 
	({
		HIR"$N蹲下身来，运起蛤蟆功，双手平推，吐气扬眉，阁阁阁三声叫喊。这三推之力带有风疾雷迅的猛劲，实是非同小可"NOR,
		WHT"$N阁阁两声怒吼，蹲下身来，呼的双掌齐出，掌力未到，掌风已将地下尘土激起，一股劲风直扑$n面门，势道雄强无比"NOR,
		HIR"$N脸色阴沉，脸颊上两块肌肉微微牵动，两臂弯曲，阁的一声大叫，双手挺出，一股巨力横冲直撞的朝$n推将过来"NOR,
		WHT"$N蹲低身子，口中咕咕咕的叫了三声，双手推出，以蛤蟆功向$n猛攻。$n身周在$P掌力笼罩之下，只激得灰泥弥漫，尘土飞扬"NOR,
	});
	string *reverse_msg = 
	({
		HIM"但见$N招术奇特，怪异无伦，忽尔伸手在自己脸上猛抓一把，忽尔反足在自己臀上狠踢一脚，每一掌打将出来，中途方向必变，实不知打将何处"NOR,
		HIM"$N忽然反手拍拍拍连打自己三个耳光，大喊一声，双手据地，爬向$n，忽地翻身一滚，骤然间飞身跃起，双足向$n连环猛踢"NOR,
		HIM"突然之间，$N俯身疾攻，上盘全然不守，出招怪异无比，将蛤蟆功逆转运用，上者下之，左者右之，招数难以捉摸"NOR,
		HIM"$N全身经脉忽顺忽逆，手上招数虽然走了错道，但是错有错着，出手怪诞，竟教$n差愕难解"NOR,
	});

	level   = (int) me->query_skill("hama-gong",1);

	if (me->query_skill_mapped("force") == "hama-gong" ) {
		if ( !me->query_temp("reverse") && me->query_temp("powerup") && random(me->query_skill("force")) > 250 && random(me->query_skill("strike")) > 250 && me->query("neili") > 1000 && me->query("jiali") > 100)
			return ([
			"action": power_msg[random(sizeof(power_msg))],
			"dodge": 20,
			"parry": 20,
			"force": 550+random(100),
			"damage": 120+random(20),
			"damage_type": random(2)?"内伤":"瘀伤"
			]);
		else if ( me->query_temp("reverse") && random(me->query_skill("force")) > 400  && random(me->query_skill("strike")) > 300 && me->query("neili") > 1000 )
			return ([
			"action": reverse_msg[random(sizeof(reverse_msg))],
			"dodge": 100,
			"parry": 100,
			"force": 500+random(100),
			"damage": 120,
			"damage_type": "瘀伤",
			]);
	}
	if ( me->query_temp("reverse") )
		return reverse_action[random(sizeof(reverse_action))];
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}


int valid_learn(object me)
{
	mapping skl; 
	string *sname;
	int v, k=0;
	
	int i = (int)me->query_skill("hama-gong", 1);

	skl=this_player()->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );

	if(me->query_skill("hama-gong", 1) > 99){

	for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
		k++;  
		}
		if ( k >=3 )
		return notify_fail("你体内不同内力互相冲撞，难以领会更高深的内功。\n");
	}

	if ((int)me->query_skill("force", 1) < 10
	 || (int)me->query_skill("force", 1)/2 < i/3 )
		return notify_fail("你的基本内功火候不足，不能学蛤蟆功。\n");
	if ( me->query("class")=="bonze" )
	{
		if (me->query("gender")=="女性")
			return notify_fail("小尼姑练蛤蟆功，不怕别人叫你秃头蛤蟆吗？\n");
		if (me->query("gender")=="男性")
			return notify_fail("大师傅练蛤蟆功，不怕别人叫你秃头蛤蟆吗？\n");
	}
	if ( me->query("family/family_name") == "丐帮" )
		return notify_fail("老叫化的徒弟学不了蛤蟆功。\n");
	if ( me->query("family/family_name") == "武当派")
		return notify_fail("老道练蛤蟆功，不怕别人叫你牛鼻子蛤蟆吗？\n");

	return 1;
}

int practice_skill(object me)
{
	if (me->query("family/master_id") != "ouyang feng"
	&& me->query_skill("hamagong", 1) > 99)
		 return notify_fail("蛤蟆功需高人指点才能继续提高。\n");
		 
	if (me->query_temp("weapon"))
		 return notify_fail("蛤蟆从不手持兵刃，所以练蛤蟆功也必须空手。\n");
		 
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练蛤蟆功。\n");
		
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练蛤蟆功。\n");
		  me->add("neili", -30);
		  me->receive_damage("jingli", 30);
	if (me->query_skill("hamagong", 1) > 100){
		me->add("neili", -40);
		  me->receive_damage("jingli", 40);
	}
	if (me->query_skill("hamagong", 1) > 150){
		  me->add("neili", -20);
		  me->receive_damage("jingli", 20);
	}
	if (me->query_skill("hamagong", 1) > 200){
		  me->add("neili", -10);
		  me->receive_damage("jingli", 10);
	}
		  return 1;
}

string perform_action_file(string action)
{
	return __DIR__"hamagong/" + action;
}

string exert_function_file(string func)
{
	return SKILL_D("hamagong/") + func;
}

//Because hamagong inherits both FORCE and SKILL, when it is called
//to return the hit_ob() function, it is confused. So, we have to
//add the hit_ob() here.  Ryu.
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage, myneili, yourneili, my_max, your_max;
	string force_skill;
	mixed foo;
		  string result;


	myneili = (int)me->query("neili");
	yourneili = (int)victim->query("neili");
	my_max = (int)me->query("max_neili")*2;
	your_max = (int)victim->query("max_neili")*2;
	myneili = my_max > myneili ? myneili : my_max;
	yourneili = your_max > yourneili ? yourneili : your_max;
	me->add("neili", - factor );
	damage = myneili/20 + factor - yourneili/25;

	if (force_skill = victim->query_skill_mapped("force") ) {
		foo = SKILL_D(force_skill)->hit_by(me, victim, damage, damage_bonus, factor);
		if (stringp(foo)) return (string)foo;
		else if (intp(foo)) damage = (int)foo;
		else if (mapp(foo)) return foo;
	}

	if ( damage > 0 )
		damage = damage * factor / (int)me->query_skill("force") * 2;

	if( damage < 0 ) {
		if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage;
			me->receive_damage( "qi", damage * 2, victim);
			me->receive_wound( "qi", damage, victim );
			if( damage < 10 ) result = "$N受到$n的内力反震，闷哼一声。\n";
			else if( damage < 20 ) result = "$N被$n以内力反震，「嘿」地一声退了两步。\n";
			else if( damage < 40 ) result = "$N被$n以内力一震，胸口有如受到一记重锤，连退了五六步！\n";
			else result = "$N被$n的内力一震，眼前一黑，身子向后飞出丈许！！\n";
			result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
			damage_bonus = -5000; // just a number negative enough
			return ([ "result" : result, "damage" : damage_bonus ]);
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
	return damage;
}

mapping curing_msg(object me)
{
	return ([
		"unfinish_self"	: "你闭目运气，忽觉内力不继，哇哇两声，喷出几口鲜血，站了起来。\n",
		"unfinish_other": HIW+me->name()+"运功良久，呕出几口黑血，站了起来。\n"NOR,
	]);
}