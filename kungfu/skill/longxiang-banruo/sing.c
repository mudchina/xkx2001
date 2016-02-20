//Cracked by Roath
// fanchang.c 梵唱
// Summer 9/29/96.
// snowbird 9 1999
// 1.1.1.2

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
	object obj, weapon;
	int xf, af, sp, ap, sucess, j;  
	if( !target ) target = offensive_target(me);
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "lubo")
                return notify_fail("你未执法器，不能凝神梵唱。\n");
	if ((!objectp(obj = present("kulou guan", me)) ) ||
               (!obj->query("equipped") )) 
		return notify_fail("你未顶骷髅冠，不能凝神梵唱。\n");
	if ((!objectp(obj = present("rentou lian", me)) ) ||
               (!obj->query("equipped") ))
                return notify_fail("你未戴人头链，不能凝神梵唱。\n");

	if( !objectp(target) || target == me)
		return notify_fail("你想要唱给谁听？\n");

	if( !target->is_character() || target->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

	if( target->query("race") != "人类")
		return notify_fail(target->query("name") + "听不懂你的咒语！\n");

    if ((int)me->query("jingli") < 300)
                return notify_fail("你的精力不够。\n");

	if( (int)me->query("neili") < 600 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("necromancy",1) < 30 )
                return notify_fail("你的降伏法功力不够！\n");

	if( (int)me->query_skill("lamaism", 1) < 30 )
                return notify_fail("你的密宗心法功力不够！\n");

	if( (int)me->query_skill("longxiang-banruo", 1) < 30 )
		return notify_fail("你的龙象般若功功力不够！\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能唱。\n");
	
	// use condition instead to avoid temp variables
    if( target->query_condition("xs_necromancy") > 0 || target->query_temp("block_msg/all", 1) )
/*	if( target->query_temp("cursed", 1) || target->query_temp("block_msg/all", 1)) */
		return notify_fail("此人已被降伏！\n");

	// allow more than one target
/*	if( (int)me->query_temp("curser") )
                return notify_fail("你降伏着另一各人！\n"); */

	me->add("neili", -400 + me->query_skill("necromancy"));
	me->receive_damage("jingli",  50);

	message_vision(
		BLU "$N摇头晃脑，口中背诵大乘佛经，夹杂以密宗六字咒。声音阴阳顿挫，有起有伏，暗含音律。\n" NOR, me);

			tell_object(target,  "你觉得那密咒比鬼哭还难听，脑袋里一团絮乱，眼前一堆鬼影在乱跳，胸气阻塞，四肢无力，混然欲睡。\n");

	// also take my jing level into effect	
	xf = (me->query_skill("necromancy", 1) + me->query_skill("lamaism", 1));
	ap = target->query("jing")/10 + target->query_skill("force") + target->query("con")  + target->query("int") ; 
	sp = me->query_skill("force") + me->query("jing")/20 + xf;
	sp *= me->query("combat_exp")/1000;
    ap *= target->query("combat_exp")/1000;
	sucess = 0;
	// make sing player a lot tougher
	if (userp(target)) {
		if (random(sp) > (ap*2.5))
		  sucess = 1;
    }  
	else {
		if (random(sp) > (ap*1.2))
		  sucess = 1;
    }
	// victim will lose some jing each time trying to resist the sing
	j = target->query("jing");
	j = j - me->query_skill("necromancy",1);
	if (j<0)
	    j=0;
	target->set("jing",j);

	if( sucess && !target->query("no_sing")){
	  tell_object(target, HIR "你只觉得眼前的一切离你慢慢远去，你的魂魄似要出窍，不再由你主宰。\n" NOR);
	  message_vision("你看见" +target->query("name") +"突然开始两眼发直，呆呆地望着前方。\n", me);
	  target->remove_all_killer();
      target->apply_condition("xs_necromancy", (int)(me->query_skill("necromancy", 1)/20));

	  target->set("xueshan/necromancy_singer", me->query("id"));
//	  me->set_temp("curser", 1);
      target->set_temp("block_msg/all", 1);
	  if((int)target->query("combat_exp") > me->query("combat_exp")/2
	  && userp(target)){
		me->improve_skill("necromancy", me->query("int"));
		me->add("combat_exp", 1);
	  }
	  return 1;
	}
	else{
	  me->start_busy(random(7));
	  if( !target->is_killing(me) ) target->kill_ob(me);	
	  return 1;
	}
}

