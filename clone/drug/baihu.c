//Cracked by Roath
// baihu.c 白虎夺命丸
// xQin 04/01

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name(HIW"白虎夺命丸"NOR, ({"baihu wan", "duoming wan", "wan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("no_sell",1);
      set("no_get",1);
      set("no_drop",1);
      set("unit", "颗");
      set("value", 100000);
   }
   setup();
}


int cure_ob(object me)
{
   
	if (me->query_condition("bonze_drug") > 0)
        {
	me->add("max_neili", -1);
	message_vision(HIR"$N吃下一颗" + name() + HIR"，只觉五脏六腑都在翻腾，原来服食药物过多，适得其反。\n"NOR, me);
	destruct(this_object());
        return 1;
        }
        me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
        me->set("neili", (int)me->query("max_neili"));

   
       message_vision(HIW"$N吃下一颗" + name() + HIW"，只觉一股真气从丹田上升，瞬间便已周行全身经脉回归丹田。\n"NOR, me);
       me->apply_condition("bonze_drug", 60);
       destruct(this_object());
       return 1;
}