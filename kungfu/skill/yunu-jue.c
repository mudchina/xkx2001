//Cracked by Kafei
// yunu-jue.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("yunu-jue", 1);
	
	if(me->query("gender") == "无性" && lvl > 39)
		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阴柔之气，无法领会里面的阴阳变化之道。\n");
		
	if(me->query("class") == "bonze")
		return notify_fail("哈哈！"+RANK_D->query_respect(me)
			+"即入佛门，怎么却来学道家心法？\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("玉女二十四诀讲究阴阳调合，有违佛家六根清净之意，"
                        +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("玉女二十四诀只能靠学习来提高。\n");
}
