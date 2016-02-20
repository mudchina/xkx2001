//Cracked by Roath
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{int i;
object *ob;	

   if( duration == 1)
	{
	tell_object(me, HIB "忽然全身气血倒流，剧毒攻心，看来已经没救了！\n" NOR );
	message("vision", me->name() +"的身体一震，神色发散，七窍开始向外流血。\n", environment(me), me);
	me->receive_wound("jing", me->query("max_jing")*4, "剧毒攻心死了");
	me->receive_damage("qi",me->query("max_qi")*4,"剧毒攻心死了");
	}
   if( !living(me) && (duration != 1)) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }	
else {
   if( duration > 1 && random(10) > 6) 
{
        switch(random(2)) {
        case(0):       
                tell_object(me, HIB "你体内毒力发作，真气发散，行动不受控制\n" NOR );
                message("vision", me->name() + "的目光散乱，神色异常，可怕地笑了一下。\n",
                environment(me), me);
                ob = all_inventory(environment(me));
                for(i=0; i<sizeof(ob); i++) 
                {
                        if ((string)ob[i]->query("race") == "人类"  && ob[i] != me )
                        {
                                message_vision(HIR "$N发狂似的大吼一声，失魂落魄的攻击起来！\n" NOR, me);
                                me->kill_ob(ob[i]);
                                ob[i]->fight_ob(me);
                         }       
                }
                break;
        case(1):
                tell_object(me, HIB "忽然肺腑一阵剧痛，你体内的毒力发作了！\n" NOR );
                message("vision",  me->name() +"的目光散乱，神色异常，脸上泛出一层黑气。\n", environment(me), me);
                me->receive_damage("qi", 50, "剧毒攻心死了");
                me->receive_wound("jing", 30, "剧毒攻心死了");
                break;
/*        case(2):
                tell_object(me, HIB "忽然头脑一阵剧痛，你体内的毒力发作了！\n" NOR );
                message("vision",  me->name() +"的目光散乱，神色异常，惘然不知所措。\n", environment(me), me);
                command("halt",me);
                command("remove all",me);
                command("drop all",me);
                break;

        case(3):
                tell_object(me, HIB "忽然头脑一阵剧痛，你体内的毒力发作了！\n" NOR );
                message("vision",  me->name() +"的目光散乱，神色异常，惘然不知所措。\n", environment(me), me);
                for(i=0; i<sizeof(ob); i++) 
                {
                        if ((string)ob[i]->query("race") == "人类"  && ob[i] != me && userp(ob[i]))
                        {
                                command("hit" + ob[i]->query("id"),me);
                        }       
                }
                break;*/
                }
}
 
}
   me->apply_condition("huadu_poison", duration - 1);

   if( duration < 1 ) 
		return 0;

   return CND_CONTINUE;
}
