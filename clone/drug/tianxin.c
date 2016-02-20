//Cracked by Roath
// tianxin.c 天心解毒丹
// xQin 04/01

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name(WHT"天心解毒丹"NOR, ({"tianxin dan", "jiedu dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("no_sell",1);
      set("no_get",1);
      set("no_drop",1);
      set("unit", "颗");
              set("long",
"这是一颗灰白色丹药，由多重药物配置而成，是武当派的解毒良药，\n对解各种浅毒有显著的疗效。\n");

      set("value", 20000);
   }
   setup();
}


int cure_ob(object me)
{
	message_vision("$N吃下一颗" + name() + "。\n", me);
   
	if ((int)me->query_condition("snake_poison") > 10) {
        me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") - 10);
	}
   	if ((int)me->query_condition("xx_poison") > 10) {
      	me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") - 10);
   	}
   
   	if ((int)me->query_condition("insect_poison") > 10) {
      	me->apply_condition("insect_poison", (int)me->query_condition("insect_poison") - 10);
   	}
   
   	if ((int)me->query_condition("insect_poison") > 10) {
      	me->apply_condition("insect_poison", (int)me->query_condition("insect_poison") - 10);
   	}
   
   	if ((int)me->query_condition("sl_poison") > 10) {
      	me->apply_condition("sl_poison", (int)me->query_condition("sl_poison") - 10);
   	}
   
   	if ((int)me->query_condition("hanbing_poison") > 10) {
      	me->apply_condition("hanbing_poison", (int)me->query_condition("hanbing_poison") - 10);
   	}
   
   	if ((int)me->query_condition("bt_poison") > 10) {
      	me->apply_condition("bt_poison", (int)me->query_condition("bt_poison") - 10);
   	}
   
   	if ((int)me->query_condition("huadu_poison") > 10) {
      	me->apply_condition("huadu_poison", (int)me->query_condition("huadu_poison") - 10);
   	}
   
   	if ((int)me->query_condition("qianzhu-poison") > 5) {
      	me->apply_condition("qianzhu-poison", (int)me->query_condition("qianzhu-poison") - 5);
   	}
   
   	tell_object(me, "你感到有一股凉意自丹田涌上心头，呼吸已不及先前的仓促。\n");
   	destruct(this_object());
   	return 1;
	}
