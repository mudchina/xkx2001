//Cracked by Roath
// medicine: xuelian.c
// Jay 3/18/96
// Ryu, 12/5/96

inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
{
        set_name("雪莲", ({"xuelian", "lian", "lotus"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支只有在寒冷的地方才能生长的雪莲。\n");
                set("value", 10000);
		set("medicine", 1);
        }
        setup();
}

int cure_ob(object me)
{
   message_vision("$N吃下一支" + name() + "。\n", me);
   if ((int)me->query_condition("snake_poison") > 0) {
      me->apply_condition("snake_poison", 0);
   }
   if ((int)me->query_condition("insect_poison") > 0) {
      me->apply_condition("insect_poison", 0);
   }
   if ((int)me->query_condition("sl_poison") > 0) {
	me->apply_condition("sl_poison", 0);
   }
   if ((int)me->query_condition("xx_poison") > 10 
   && (int)me->query_condition("xx_poison") < 50) {
      me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") - 10);
   }
   if ((int)me->query_condition("xx_poison") > 50)
   tell_object(me, "你中的星宿掌毒太深，现在服此物没什么效。\n");
   destruct(this_object());
   return 1;
}

