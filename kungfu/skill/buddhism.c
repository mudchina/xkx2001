//Cracked by Roath
// buddhism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("buddhism", 1);

	if( me->query("class") == "bonze" && (int)me->query("guilty") > 0 )
		return notify_fail("你屡犯僧家数戒，尘俗之心太重，无法修炼禅宗心法。\n");
		
	if( (me->query("class") != "bonze" && me->query("family/family_name") != "大理段家")
	 && lvl > 39 ) 
		return notify_fail("你未入佛门，尘缘不断，没有清净无为的菩提心，无法继续修持禅宗妙法。\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("禅宗心法只能靠学(learn)来提高。\n");
}

void skill_improved(object me)
{
        if( (int)me->query_skill("buddhism", 1) >= 120
        &&  !me->query("sl_gifts/bdh") ) {
                me->set("sl_gifts/bdh", 1);
                me->add("int", 1);
                write("\n你的禅宗心法学有所成，提高了你的智力。\n");
        }
}
