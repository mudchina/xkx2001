// xiaoyao-piaopiao.c 逍遥飘飘步

inherit SKILL;

string *dodge_msg = ({    
"$n使出「一元步法」，随着$N的攻势飘起，从容躲过这一招。\n",    
"$n使出「二仪步法」，猛然纵起丈余，结果$N扑了个空。\n",    
"$n身形一摇，幻出几个人影，一式「三才步」躲过了$N的攻势。\n",    
"$n使出「四象步法」纵身跃起，倏忽已落至$N身后。\n",    
"$n左一摇，右一晃，一招「五行步」已轻松闪过。\n",    
"$n双足一点，斜斜飞起，使出「六合步法」已闪到$N身侧。\n",    
"$n轻身一晃，脚踩七星，一式「七星步法」，轻轻闪过。\n",	    
"$n身形突地变稳，「八卦步法」顿然使出，倏忽已落至$N身后。\n",    
"$n身形猛然变快，一式「九宫步法」，$N顿时迷失了$n的身影。\n",
});

int valid_enable(string usage) 
{     
return (usage == "dodge") ;
}

int valid_learn(object me) 
{
return 1; 
}

string query_dodge_msg(string limb)
{	
return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{        
	if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");	
	if (me->query_skill("xiaoyao-piaopiao", 1) < 30)                
		me->receive_damage("jingli", 20, "精力透支过度死了。");
		else
                me->receive_damage("jingli", 25, "精力透支过度死了。");	
	return 1;
}