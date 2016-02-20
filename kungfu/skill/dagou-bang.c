//Cracked by Roath
// dagou-bang.c
// write by     Xiang
// Ryu added parry msg.
// fear added 3 more zhao (Jan/2000), feng effect (march 2000)

#include <ansi.h>

inherit SKILL;

nomask int parry_available() { return 1; }
string *parry_msg =     ({
                "$p$W扬起，竟不理会$P的招式，用缠字诀一绊一挑，巧妙异常，去势全在旁人万难料到之处，$P轻跃相避，哪知$W猛然翻转，击$P的脚胫。$P一个踉跄，感紧跃开。\n",
                "$p当即横棒掠地，直击不回。这一棒去势古怪，正巧搭上$P$w。$P这一招尚未使足，已知不妙，急忙跃起相避。\n",
                "$p立感不支，当下移动脚步，使个「封」字诀挡住$P$w攻势。\n",
                "但终究还是慢了一步，$p$W回转，忽地刺向$P的右股。这一招後发而先至，$P$w未及$p身体，手腕先得被棒端刺中，$P急忙收$w变招。\n",
                "$p却将内力慢慢传到$W上。$P只觉$p手里这根$W中竟有一股极强吸力，牵引得$P$w歪歪斜斜，$w所向不是偏左，便是偏右。\n",
                "$p眼见危急，挥棒护住身前，棒端即又疾送，使招"+HIG"「按狗低头」"NOR+"，向$P$w捺落。\n",
                "$p这时和$P站得甚近，闪避不及，急忙回转$W，把$P招式一一拨开。\n",
});
string query_parry_msg(object weapon, object victim)
{
                object ob;

                if (!objectp(ob = victim->query_temp("weapon"))
                || ob->query("skill_type") != "stick" || victim->query_skill("dagou-bang", 1) <  100)
                                return SKILL_D("parry")->query_parry_msg(weapon);
                else
                                return replace_string(parry_msg[random(sizeof(parry_msg))],     "$W", ob->name());
}
mapping *action = ({
([              "action": "$N使出一招"+HIG"「棒打双犬」"+NOR"，手中$w化作两道青光砸向$n的$l",
                "force" : 180,
                "dodge":  10,
                "damage": 90,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "挫伤"

]),
([              "action": "$N手中$w左右晃动，一招"+HIG"「拨草寻蛇」"+NOR"向$n的$l攻去",
                "force" : 250,
                "dodge":  20,
                "damage": 60,
                "damage_type": "挫伤"
]),
([              "action": "$N举起$w，居高临下使一招"+HIG"「打草惊蛇」"+NOR"敲向$n的$l",
                "force" : 330,
                "dodge":  30,
                "damage": 90,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "挫伤"
]),
([              "action": "$N施出"+HIG"「拨狗朝天」"+NOR"，$w由下往上向$n撩去",
                "force" : 400,
                "dodge":  20,
                "damage": 60,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "挫伤"
]),
([              "action": "$N手中$w变招横扫，一招"+HIG"「反截狗臀」"+NOR"，棒夹风声，来势迅猛，攻击$n要害",
                "force" : 410,
                "dodge":  20,
                "damage": 100,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "瘀伤"
]),
([              "action": "$N突使一招"+HIG"「斜打狗背」"+NOR"，棒招精妙无比，$w一幌，已击向$n的$l",
                "force" : 420,
                "dodge":  25,
                "damage": 110,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "瘀伤"
]),
([              "action": "$N提起$w，一招"+HIG"「棒打狗头」"+NOR"，往$n$l击去，出手狠辣，正是"+HIG"「打狗棒法」"+NOR"中的高招",
                "force" : 430,
                "dodge":  20,
                "damage": 120,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "瘀伤"
]),
});

int     valid_enable(string     usage) { return usage == "stick" ||     usage == "parry"; }

int     valid_learn(object me)
{
                if ((int)me->query("max_neili") < 100)
                                return notify_fail("你的内力不够。\n");
                return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        object ob, victim;
        string* msghit, msg;
        string* msgxuedao, limb_hurt;
        
        level = (int)me->query_skill("dagou-bang", 1);

        ob = me->select_opponent();
        
        if (random(me->query_skill("stick")) > 100 
        && me->query_skill("force") > 90
        && me->query("neili") > 100 ) {
//        	me->add("neili", -30);
        	return ([
        	"action": "$N眼中射出一道青芒，手中$w使出"+HIG"「天下无狗」"+NOR"，劈天盖地般攻向$n，棒法之精妙，已臻武学中的绝诣",
        	"force" : 480,
        	"dodge" : 30,
        	"damage": 150,
        	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        	"damage_type": "挫伤"]);
        }

        if( objectp(victim = me->query_temp("zhuan")) )
        {
        	if( ob == victim )
        	{
        		if(random(5) < 1)
        		{
        			if(random(me->query("combat_exp")) * me->query_skill("stick") > 
        			random(ob->query("combat_exp"))* ob->query_skill("dodge")/2)
        			{
        		
        				msghit = ({
        					"\n$n一个不慎，被棒端点中",
        					"\n只见棒端噗地戳中$n的"
        				});
        				msgxuedao = ({
        					"强间穴",
        					"风府穴",
        					"大椎穴",
        					"灵台穴",
        					"悬枢穴"
        				});
        				msghit += msgxuedao;
        				ob->receive_damage("qi", level/3, "重伤过度死了");
        				ob->start_busy(1 + random(3));
        				msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
        				message_vision(msg, me, victim);
        			}
        			else
        			{
        				msghit = ({
        					"\n$n大意抢攻，略见疏神，竟被$P在"+limb_hurt+"上戳了一下，虽在未被封闭穴道，却也是疼痛良久。\n",
        					"\n$n被戳了一下，但在危急中急闭穴道，竟未曾受伤。\n"
        				});
        				ob->receive_damage("qi", level, "重伤过度死了");
        				msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
        				message_vision(msg, me, victim);
        			}
        			me->delete_temp("zhuan");
        		}
        		else
        		{ 
        			ob->receive_damage("jing", level/3, "精力透支过度死了");
        			ob->receive_damage("jingli", level/3, "精力透支过度死了");
        		}
        	}
        }

        return action[random(sizeof(action))];
}

int     practice_skill(object me)
{
                object weapon;

                if (!objectp(weapon     = me->query_temp("weapon"))
                //|| (string)weapon->query("skill_type") !=     "staff")
                || (string)weapon->query("skill_type") != "stick")
                                return notify_fail("你使用的武器不对。\n");
                if ((int)me->query("jingli") < 50)
                                return notify_fail("你的精力不够练打狗棒法。\n");
                me->receive_damage("jingli", 40);
                return 1;
}

mixed hit_ob(object me, object victim, int damage)
{
        string msg;
        int ap, dp, zhencost;
        string result;
        object weapon;

        if (!objectp(weapon     = me->query_temp("weapon")))
                return 0;
        
        ap = me->query("combat_exp")/1000;
        ap += me->query_skill("stick");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("dodge");
        ap = (ap + random(ap*2))/2;
        zhencost = sqrt(weapon->weight()/10)+10;
        
        if(victim->query_temp("feng")) {
//        msg = HIG"$N运起打狗棒法中的「封」字诀朝$n击去！\n"NOR;
//        message_vision(msg,me,victim);

        if ( random(ap+dp) > ap ) {
                result = HIG "只听「嗒」的一声，$n手背上被棒端戳了一下，急忙缩手，已感又疼又麻。\n" NOR;
                message_vision(result,me,victim);
//                message_vision((string)weapon->query("weapon_prop/damage") + "\n",me,victim);
                victim->add("qi", -weapon->query("weapon_prop/damage")*2);
                victim->start_busy(1+random(2));
                me->add("neili", -zhencost);
                me->add("jingli", -zhencost);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+dp) > ap ) {
                result = HIG "突然青光闪动，棒招来势神妙无方，"+(string)weapon->query("name")+HIG"击中了$n。\n" NOR;
                message_vision(result,me,victim);
//                message_vision((string)weapon->query("weapon_prop/damage") + "\n",me,victim);
                victim->add("qi", -weapon->query("weapon_prop/damage")*3);
                victim->start_busy(1+random(3));
                me->add("neili", -zhencost);
                me->add("jingli", -zhencost);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = HIG "$N猛地递出一招，这一棒迅捷无伦，直取$n眉心，$p「啊」的一声，连退出数尺！\n" NOR;
                message_vision(result,me,victim);
//                message_vision((string)weapon->query("weapon_prop/damage") + "\n",me,victim);
                victim->add("qi", -weapon->query("weapon_prop/damage")*4);
                victim->start_busy(1+random(4));
                me->add("neili", -zhencost);
                me->add("jingli", -zhencost);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else
        {
                result = weapon->name()+HIG"幌动，霎眼之间竟已转到$n身后，拍的一声，在$p臀上抽了一下。！\n" NOR;
                message_vision(result,me,victim);
//                message_vision((string)weapon->query("weapon_prop/damage") + "\n",me,victim);
                victim->add("qi", -weapon->query("weapon_prop/damage"));
                victim->start_busy(1+random(2));
                me->add("neili", -zhencost);
                me->add("jingli", -zhencost);
                damage = 0;
        
                return ([ "result" : result, "damage" : damage ]);
        }
     }
}

string perform_action_file(string action)
{
                return __DIR__"dagou-bang/"     + action;
}
