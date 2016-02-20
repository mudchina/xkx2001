//Cracked by Roath
// huxindan.c 天王护心丹
// xQin 04/01

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name(RED"天王护心丹"NOR, ({"huxin dan", "tianwang dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("no_sell",1);
      set("no_get",1);
      set("no_drop",1);
      set("unit", "颗");
      set("value", 20000);
   }
   setup();
}


int cure_ob(object me)
{
   
   if (me->query_condition("hot_drug") > 0)
   {
   me->add("max_neili", -1);
   message_vision(HIR"$N吃下一颗" + name() + HIR"，只觉五脏六腑都在绞痛，原来服食药物过多，适得其反。\n"NOR, me);
   destruct(this_object());
   return 1;
   }
   me->set("eff_jing", (int)me->query("max_jing"));
   me->set("jing", (int)me->query("max_jing"));
   me->set("eff_qi", (int)me->query("max_qi"));
   me->set("qi", (int)me->query("max_qi"));

   
   message_vision(HIG"$N吃下一颗" + name() + HIG"，只觉全身舒泰，伤势已大有好转。\n"NOR, me);
   me->apply_condition("hot_drug", 20);
   destruct(this_object());
   return 1;
}