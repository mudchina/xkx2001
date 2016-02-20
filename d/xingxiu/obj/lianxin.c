//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int throw_ob(object me, object victim);
void create()
{
   set_name(RED"炼心弹"NOR, ({"lianxin dan", "dan", "lianxin"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "颗");
      set("long", RED"一颗硫磺硝磷所制的火弹，内夹毒药。\n" NOR);
      set("skill", "feixing-shu");
      set("value", 0);
   }
   setup();
}

int throw_ob(object me, object victim)
{
	int ap, dp;

   message_vision(BLU"$N一扬手，衣袖中飞出一点蓝印印的火花，如一只飞萤，向$n扑过去。\n" NOR, me, victim);
   ap = me->query_skill("feixing-shu", 1);
   dp = (int)victim->query_skill("dodge");
   ap *= me->query("combat_exp")/1000;
   dp *= victim->query("combat_exp")/1000;
   
   ap = random(ap);
	
	if (ap > dp/2){
   message_vision(RED"只听见一阵嗤嗤声响，那飞萤已落在$n的肩头，把$n的肩部烧得焦烂。\n" NOR, me, victim);
   me->improve_skill("feixing-shu", 1);
   victim->apply_condition("insect_poison", 12);
   victim->set("poisoner", me);
   victim->receive_wound("qi", 100);
   victim->receive_wound("jing", 50);
   if( !victim->is_killing(me) ) victim->kill_ob(me);
   me->start_busy(1+random(3));
   if( victim->query("combat_exp") > me->query("combat_exp")){
	 me->add("combat_exp", 5 + random(5));
        me->improve_skill("feixing-shu", (int)me->query("int"));
   }
   destruct(this_object());
   return 1;
   }
   else
        {
        message_vision("$n发现不妙，赶紧向後跃开数丈，躲了开去。\n" NOR, me, victim);
	if( !victim->is_killing(me) ) victim->kill_ob(me);
	me->start_busy(1+random(3));
	destruct(this_object());
        }
        return 1;
}    

