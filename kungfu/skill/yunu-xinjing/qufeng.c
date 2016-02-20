//Cracked by Kafei
// qufeng.c
// Xuanyuan 7/2001

#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;
int exert(object me, object target)
{
        object obj;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || target == me 
	|| target->query("id") == "mu ren" 
	|| target->query("id") == "shangshan" 
	|| target->query("id") == "mengzhu" 
	|| target->query("id") == "fae" )
		return notify_fail("你要驱赶玉蜂攻击谁？\n");

	if (!objectp(obj=present("fengjiang ping", me)))
            return notify_fail("你身上没有蜂浆瓶，不能驱赶玉蜂攻敌。\n");

	if ((int)me->query_skill("yunu-xinjing", 1) < 100 )
		return notify_fail("你的玉女心经火候太低，不能驱赶玉蜂攻敌。\n");

        if ( me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("你没有激发玉女心经到内功上！不能驱赶玉蜂攻敌。\n"); 

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够。\n");

        if(target == me)
                return notify_fail("玉蜂不能攻击你。\n");

        message_vision(HIY "\n$N拔开玉瓶塞，手捂玉瓶潜运内力，使得瓶中的香气远远飘了开去，\n"
                   "突然嗡嗡之声大作，不知道从哪里飞来一大群玉蜂，向$n围了过去。\n" NOR,
                   me, target);

	obj=new("/clone/beast/yufeng");
	obj->move(environment(target));
	obj->set_leader(target);

	me->add("neili", -50);
        me -> receive_damage ("jing" , 50 ) ;

        if( userp(target) )
        {       target -> fight_ob(me) ;
                me->fight_ob(target);
        }
        else
        {       target->kill_ob(me);
                me->fight_ob(target);
        }
	if (  random ( (int)me->query_skill("yunu-xinjing", 1) ) < (int)target->query_skill("yunu-xinjing", 1) *2 / 3 )
                message_vision(YEL "\n但$n撮唇一啸，玉蜂似乎听懂了号令，远远避了开去。\n" NOR, me, target);
        else
        {
	tell_object (target , HIR "\n你周围刹那间尽是玉蜂围绕，一只只玉蜂悍不畏死地向你\n"
               "蜇了过来，你只觉得背心微微一痛，已被玉蜂蜇中！\n" NOR  ) ;
	obj->kill_ob(target);
	target -> start_busy (3) ;
	}
	return 1;
}