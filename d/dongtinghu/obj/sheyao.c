//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name("蛇药", ({"she yao", "yao"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "包");
      set("value", 2000);
   }
   setup();
}


int cure_ob(object me)
{
   message_vision("$N吃下一包" + name() + "。\n", me);
   if ((int)me->query_condition("snake_poison") > 7) {
      me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") - 5);
   }

   destruct(this_object());
   return 1;
}
