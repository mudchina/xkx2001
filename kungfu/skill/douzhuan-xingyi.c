//Cracked by Roath
// douzhuan-xingyi  斗转星移
// arthurgu 1999.9

#include <ansi.h>;
inherit FORCE;
inherit SKILL;
void interrupt_me(object who);

int valid_enable(string usage) { return usage == "force" ; }

int valid_learn(object me)
{
	
	int i = (int)me->query_skill("douzhuan-xingyi", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10
          ||(int)me->query_skill("force", 1)/2 < i/3 )
                return notify_fail("你的基本内功火候不足，不能学斗转星移神功。\n");         
        if ( me->query("gender") == "无性" )
                return notify_fail("太监不能学斗转星移神功。\n");
        if ( me->query("class") == "bonze" )
                return notify_fail("姑苏慕容不收出家人为弟子.");  
                
         if ((int)me->query_skill("literate", 1) < 220 
         && (int)me->query_skill("literate",1) < ((int)me->query_skill("douzhuan-xingyi",1) - 30)) 
                    return notify_fail("你的读书写字水平不够，无法进一步提高斗转星移神功。\n");
                             
        
        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1)
          || me->query_skill("mahayana",1) || me->query_skill("lamaism", 1))
                return notify_fail("你练了秃驴牛鼻子们的心法，还学斗转星移做什麽！\n");
        if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("linji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("longxiang-banruo", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)    
        || me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1)
        || me->query_skill("bitao-xuangong", 1) || me->query_skill("xiantian-gong",1)  
        || me->query_skill("huagong-dafa",1))  
                return notify_fail("你不先散了别派内功，怎能学斗转星移神功？！\n");
        return 1;
	
}


int practice_skill(object me)
{
  return notify_fail("斗转星移只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
  return __DIR__"douzhuan-xingyi/" + func;
}




 
 
