//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int throw_ob(object me, object victim);
void create()
{
   set_name(BLU"逍遥三笑散"NOR, ({"sanxiao san", "san", "sanxiao", "zhuihun"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "包");
      set("value", 10);
      set("skill", "feixing-shu");
   }
   setup();
}

int throw_ob(object me, object victim)
{
   int skill, skill2, thr, dod, poi, my_neili, u_neili;

   if( me->query("neili") <= 600 ){
	write("你的内力不够摧迫逍遥三笑散毒！\n");
	return 1;
	}

   if (me->query_skill("poison", 1) < 100){
	write("当心毒死你自己！\n");
	return 1;
	}
   if (victim->query_temp("sanxiao")){
	write("此人已中了三笑追魂散，命不久矣！\n");
	return 1;
	}
   if (me->query_condition("pker") > 240 && userp(victim)){
	write("你感到一丝内疚，手突然软了下来。\n");
	return 1;
	}
   message_vision(BLU"$N轻轻一弹指，将逍遥三笑散往$n身上弹去。\n" NOR, me, victim);
   if (me->query_skill("poison", 1) < 100){
   me->set_temp("sanxiao", 1);
   this_object()->set_temp("used", 1);
   this_object()->move("/u/ryu/workroom");
   call_out("smile", 20, me);
        tell_object(me, "你毒炼得火侯不够，毒着自己了！\n");
	return 1;
   }
   if (me->query_skill("poison", 1) < victim->query_skill("poison", 1) + 30){
   victim->apply_condition("insect_poison", 100);
   return 1;
   }
   thr = me->query_skill("feixing-shu", 1);
   poi = me->query_skill("poison");
   dod = (int)victim->query_skill("force");
   my_neili = me->query("neili")/10;
   u_neili = (int)victim->query("neili")/10;
   skill = thr + poi + my_neili;
   skill2 = dod + u_neili;
   skill *= me->query("combat_exp")/1000;
   skill2 *= victim->query("combat_exp")/1000;
   me->add("neili", -150);

   if ( skill > skill2){
   victim->set_temp("sanxiao", 1);
   me->improve_skill("feixing-shu", 1);

	if(userp(victim)) me->apply_condition("pker", 250);

   if( !victim->is_killing(me) ) victim->kill_ob(me);
   this_object()->set_temp("used", 1);
   this_object()->set("value", 10);
   this_object()->move("/u/ryu/workroom");
   call_out("smile", 10, victim, me);
   return 1;
   }
   else
        {
        message_vision(HIR"$n袍袖一拂，一股内劲发出，将那三笑散尽数朝$N拂将回去。\n" NOR, me, victim);
	me->set_temp("sanxiao", 1);
        this_object()->set_temp("used", 1);
	this_object()->set("value", 10);
	this_object()->move("/u/ryu/workroom");
        call_out("smile", 10, me);
	if( !victim->is_killing(me) ) victim->kill_ob(me);
        }
        return 1;
}    

int smile(object victim, object me)
{
   message("vision",victim->name()+"突然向你诡异地一笑。\n", environment(victim),({victim}) );
   victim->add_temp("smile", 1);
   if ( victim->query_temp("sanxiao")){
   if ( victim->query_temp("smile") >= 3 ) {
	remove_call_out("smile");
        tell_object(victim,"你突然全身僵硬，呼吸异常困难，原来在不知不觉中中了别人的毒手！\n");
	victim->receive_wound("jing", victim->query("max_jing")*2, me);
        victim->delete_temp("sanxiao");
	victim->delete_temp("smile");
	destruct(this_object());
   }
   else call_out("smile", 10, victim, me);
   return 1;  
	}
	else destruct(this_object());
}	
