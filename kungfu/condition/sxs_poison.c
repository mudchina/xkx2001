//Cracked by Roath
//BY haowen May 10th 1999

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{   if( duration == 1)
        {

tell_object(me,HIR"你突然全身僵硬，呼吸异常困难，原来在不知不觉中中了别人的毒手！\n"NOR);
	me->set_temp("last_damage_from", "中了三笑散死了");
	me->delete("env/immortal");
	me->die();
	
        }
   
   else {
	message("vision",me->name()+"突然向你诡异地一笑。\n",environment(me),({me}) );
	}
   me->apply_condition("sxs_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
