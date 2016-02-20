//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name("百草丹", ({"baicao dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "颗");
      set("value", 4000);
      set("long", "这是一颗丐帮的百草丹，功能疗伤保精。\n");
      set("medicine", 1);
   }
   setup();
}

int cure_ob(object me)
{
   message_vision("$N吃下一颗" + name() + "。\n", me);
   
   if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 6 
   || (int)me->query("eff_jing") < (int)me->query("max_jing") / 6) {
	write("你伤势过重，服食丹药仅能略尽人事！\n");
   }
   else if ( (int)me->query("eff_qi")==(int)me->query("max_qi")
   && (int)me->query("eff_jing")==(int)me->query("max_jing") ) {
	me->receive_wound("qi", 50);
	me->receive_wound("jing", 50);
	write( HIR "你没伤胡乱服食丹药，反有大害！\n\n" NOR );
   }
   else {
	if ( (int)me->query("eff_qi") < (int)me->query("max_qi") ) {
		me->receive_curing("qi", 50);
	}
	
	if ( (int)me->query("eff_jing") < (int)me->query("max_jing") ) {
		me->receive_curing("jing", 50);
	}
	
	message_vision(YEL "$N只觉伤势大为好转，可见此丹灵效。\n\n" NOR, me);
   }
		
   destruct(this_object());
   return 1;
}