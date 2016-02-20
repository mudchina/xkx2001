//Cracked by Roath

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage=1;
   if( !living(me) ) {
      message("vision", me->name() +"脸色大变，口中鲜血狂喷，倒在地上。\n", environment(me), ({me}));
   }
   else {
        switch( random(3) )
        {
                case 0:
			tell_object(me, HIR"你只觉肩头云门穴微微一痛，脑中微感眩晕。\n" NOR);
      			message("vision", me->name() +
"脸色一变，有点神不守舍的样子。\n",environment(me), ({me}));
                       break;
                case 1:
			tell_object(me, HIR"你上臂青灵穴忽然觉得麻痒难当，劲力不能凝聚！\n"NOR );
      			message("vision", me->name() +
"身形蹒跚，似乎举步维艰的样子。\n",environment(me), ({me}));
                       break;
                case 2:
			tell_object(me, HIR"你腿上五里穴顿感酸痛，连步子也迈不动了！\n" NOR);
      			message("vision", me->name() +
"脚下一个趔趄，差点一跤摔倒。\n",environment(me), ({me}));
                       break;
        }
   }
	if (duration > 0) damage = duration;
	else damage =1;
      me->receive_wound("qi", damage*2, "七伤拳内伤发作死了");
      me->receive_wound("jing", damage, "七伤拳内伤发作死了");
      me->receive_damage("jingli", damage, "七伤拳内伤发作死了");
	
	if (me->query_condition("qs_damage")>(5+me->query_skill("qishang-quan",1)/10))
		me->apply_condition("qs_damage", 
		duration - 5 - me->query_skill("qishang-quan",1)/10);
	else return 0;

   return 1;
}
