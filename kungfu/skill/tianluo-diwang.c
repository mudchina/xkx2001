//Cracked by Kafei
//tianluo-diwang.c 天罗地网势 by maco 1999/1/17

#include <combat.h>
#include <ansi.h>
inherit SKILL;

int ke_qz(object me, object victim, object weapon, int damage);

mapping *dodge_action = ({
([      "action" : "$n腰肢轻摆，就如一朵菊花在风中微微一颤，斜身移步，早已避开。\n",
        "dodge"  : 10
]),
([      "action" : "$n展开轻功提纵术，犹如疾风掠地，忽来忽往，瞬息之间进退数次，於丈许方圆之内腾挪奔跃，令$N无从进招！\n",
        "dodge"  : 20
]),
([      "action" : "$n顺著$N攻势避过，身形一幌，竟然在$N身边一掠而过，趋退若神，步子微挫，早已让开。\n",
        "dodge"  : 30
]),
([      "action" : "$n脚步轻盈，身手迅捷，轻功施展得圆转如意，身法之快，异乎寻常，矫夭腾挪，轻轻巧巧地避过$N这一招。\n",
        "dodge"  : 40
]),
([      "action" : "却见$n潇洒自如，足下微尘不起，轻飘飘的似是缓步而行，不疾不徐地避了开去，的是飘逸无伦，变化万方！\n",
        "dodge"  : 50
]),
([      "action" : "$n展开古墓派轻功，奔驰来去，斜窜急转，纵横飘忽，令$N难以确定出手的方位！\n",
        "dodge"  : 60
]),
([      "action" : "$n衣襟当风，飘飘然如欲乘风而去，越奔越是轻捷，飞舞来去，脚下全不着力，$N不禁暗感难以捉摸！\n",
        "dodge"  : 70
]),
([      "action" : "$n双足一登，身子腾空而起，犹似燕子穿林一般，离地尺许，平平掠过，相形之下，$N的招数似乎倒来迟一步！\n",
        "dodge"  : 80
]),
([      "action" : "$n展开古墓派轻功，身随意走，一起脚，急奔如电，$N竟然跟随不上，心下暗暗惊佩！\n",
        "dodge"  : 90
]),
([      "action" : "$n身子向前一挺，飞也似的滑了开去，但见$n东滑西闪，左转右折，实无瞬息之间停留，$N的诸般招式一一落空！\n",
        "dodge"  : 100
]),
});

mapping *action = ({
([      "action" :"$N发掌奇快，但一招一式，清清楚楚，自成段落，忽地手腕微翻，举掌往$n$l击落",
        "force" : 160,
        "dodge" : 0, 
        "parry" : -10, 
        "damage": 15,
	"post_action": (: ke_qz :),	
        "damage_type" : "瘀伤"
]),
([      "action" :"$N招数手法处处出以阴柔，掌法向$n绵绵无尽展了开来，变幻多端，人所莫测",
        "force" : 220,
        "dodge" : 10, 
        "parry" : -5, 
        "damage": 20,
	"post_action": (: ke_qz :),	
        "damage_type" : "瘀伤"
]),
([      "action" :"$N双手挥出，东边一收，西边一拍，将$n的周身去路全数挡住，双掌这边挡，那边拍，$n竟是难以脱出掌影笼罩三尺之外",
        "force" : 260,
        "dodge" : 25, 
        "parry" : -5, 
        "damage": 25,
	"post_action": (: ke_qz :),	
        "damage_type" : "内伤"
]),
([      "action" :"$N双臂飞舞，两只手掌宛似化成了千手千掌，任$n如何腾挪身形，始终被困在$N掌势围成的圈子中",
        "force" : 280,
        "dodge" : 20, 
        "parry" : -15, 
        "damage": 30,
	"post_action": (: ke_qz :),	
        "damage_type" : "内伤",
]),

([      "action" :"$N双掌一并，凭虚击去，这路「天罗地网势」的掌法使将出来，绵密无比，掌力虽不沉雄，但手法迅疾，东发一招、西劈一掌，飘忽灵动之极",
        "force" : 320,
        "dodge" : 20, 
        "parry" : -15, 
        "damage": 30,
	"post_action": (: ke_qz :),	
        "damage_type" : "内伤",
]),
([      "action" :"$N出手快捷无比，而手掌之来又是变幻无方，抓打撕劈、擒拿勾击，在小擒拿手中夹以「天罗地网势」的掌法，著著抢攻",
        "force" : 350,
        "dodge" : 15, 
        "parry" : -5, 
        "damage": 35,
	"post_action": (: ke_qz :),	
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" || usage=="dodge";}

int valid_combine(string combo) { return combo=="meinu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练天罗地网势必须空手。\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
          return notify_fail("你的玉女心经火候不够，无法学天罗地网势。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("tianluo-diwang",1);
        return action[random(sizeof(action))];
}

mapping query_dodge_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(dodge_action);
        level   = (int) me->query_skill("tianluo-diwang");

        if (level < 80 )
                zhaoshu--;

        if (level < 60 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return dodge_action[random(zhaoshu)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力太低了。\n");
        me->receive_damage("jingli", 25, "精力透支过度死了。");
        me->add("neili", -10);
       
       return 1;
}

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_dodge_action(me, ob);

        return action["action"];
}


string perform_action_file(string action)
{
       return __DIR__"tianluo-diwang/" + action;
}


int ke_qz(object me, object victim, object weapon, int damage)
{
        string str;
        int skill,v_parry;
	skill = me->query_skill("tianluo-diwang");

        if(skill > 80 ){

	if (damage==RESULT_DODGE
	&& victim->query_skill_mapped("dodge") == "jinyangong" 
	&& (random(skill)/2 + skill/2) > random(victim->query_skill("jinyangong"))) {

	message_vision(HIW"岂知$N深悉金雁功的诸般巧妙变著，左脚勾出，正好算在$n闪躲之处，配合得丝丝入扣，$n被$P一勾，当即仰天摔倒！\n"NOR, me,victim );

	victim->receive_damage("qi", random(skill)+skill*2);
	victim->start_busy(8);

        str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("( $N"+str+")\n", victim);	
	}
	else if (damage==RESULT_PARRY 
	&& (victim->query_skill_mapped("parry") == "chunyang-quan" || victim->query_skill_mapped("parry")== "sanhua-juding" ||victim->query_skill_mapped("parry") == "quanzhen-jian" || victim->query_skill_mapped("parry")== "duanyun-bian" ) 
	&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry"))) {

	message_vision(HIW"不料$N对全真派武功招招熟悉，手掌一翻，已抓住$p手腕，先拉後送，将$p摔了出去！\n"NOR, me,victim );
	victim->start_busy(8);
	victim->receive_damage("qi", random(skill)+skill*2);
	victim->start_busy(random(1));
        str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("( $N"+str+")\n", victim);	
		}
	}
}
