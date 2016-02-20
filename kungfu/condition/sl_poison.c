//Cracked by Roath
// shenlong_poison

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "面部突然抽搐了一下。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然你觉得全身乏力，你中的化骨绵掌毒发作了！\n" NOR );
      message("vision", me->name() + "的步履突然沉重，走路开始摇摇晃晃了起来。\n",
            environment(me), me);
   }
      me->receive_damage("qi", 25,"化骨绵掌毒散及全身而死了");
      me->receive_wound("jing", 15,"化骨绵掌毒散及全身而死了");
      me->apply_condition("sl_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


