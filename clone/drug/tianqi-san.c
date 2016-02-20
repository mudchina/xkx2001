//Cracked by Roath
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "田七鲨胆散" NOR, ({"tianqi san", "san"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "：这是一包田七鲨胆散，可解剧毒。\n");
                set("value", 10000);
		set("medicine", 1);
        }

        setup();
}

int cure_ob(object me)
{


// This is a serious waring!!!!!!!!!!!!!!!!
// Never use clear_condition()!!!!!!!!!!!!!
// Because it clears all conditions on a player!!!!!!!!!!!!!!!
   if (me->query_condition("cool_drug") > 0){        

	message_vision(HIR "$N吃下一包"+name()+"，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
        destruct(this_object());
        return 1;
   }

   message_vision("$N吃下一包" + name() + "。\n", me);


   if ((int)me->query_condition("xx_poison") < 30) {
      me->apply_condition("xx_poison", 0);
   } else if ((int)me->query_condition("xx_poison") >= 30)
	      me->apply_condition("xx_poison", (int)me->query_condition("xx_poison")-5);
   
   if ((int)me->query_condition("snake_poison") > 0) {
      me->apply_condition("snake_poison", 0);
   } 

   if ((int)me->query_condition("insect_poison") > 0) {
      me->apply_condition("insect_poison", 0);
   }

   if ((int)me->query_condition("sl_poison") < 100) {
      me->apply_condition("sl_poison", 0);
   } else if ((int)me->query_condition("sl_poison") >= 100)
              me->apply_condition("sl_poison",(int)me->query_condition("sl_poison")-80);
        
   if ((int)me->query_condition("hsf_poison") < 50) {
      me->apply_condition("hsf_poison", 0);
   } else if ((int)me->query_condition("hsf_poison") >= 50)
              me->apply_condition("hsf_poison",(int)me->query_condition("hsf_poison")-40);

   me->apply_condition("cool_drug", 10);
   destruct(this_object());
   return 1;
}

