//Cracked by Roath
// medicine: xuelian.c
// Jay 3/18/96
// Ryu, 12/5/96
#include <ansi.h>;
inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
{
        set_name(HIM"雪莲"NOR, ({"xuelian", "lian", "lotus"}));
	set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "碗口大的一朵雪莲，很象湖中莲花，花盘冰雪般晶莹洁白，大瓣层叠，中间长着细丝状的紫红\n"
			    "色和橙色花蕊。\n");
                set("value", 20000);
		set("medicine", 1);
        }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0){
        me->add("max_jingli", -1);
	me->add("eff_jingli", -1);
        message_vision(HIR "$N吃下一枚雪莲，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
        destruct(this_object());
        return 1;
        }
   message_vision(HIM"$N吃下一支雪莲，一股秋菊似的幽香沁入心肺，顿觉神清气爽。\n"NOR, me);
	me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
	me->apply_condition("cool_drug", 30);

        if (random(2)==1){ 
	me->add("max_jingli", 1);
	me->add("eff_jingli", 1);
	}

        me->set("neili", (int)me->query("max_neili"));

        if ((int)me->query_condition("snake_poison") > 0) 
        me->apply_condition("snake_poison", 0);
  
        if ((int)me->query_condition("insect_poison") > 0) 
        me->apply_condition("insect_poison", 0);
 
        if ((int)me->query_condition("sl_poison") > 0) 
	me->apply_condition("sl_poison", 0);
   
        if ((int)me->query_condition("xx_poison") > 10 
        && (int)me->query_condition("xx_poison") < 50) 
        me->apply_condition("xx_poison", 0);
  
   destruct(this_object());
   return 1;
}

