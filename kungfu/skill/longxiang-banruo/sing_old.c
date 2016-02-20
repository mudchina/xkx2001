//Cracked by Roath
// fanchang.c 梵唱
// Summer 9/29/96.

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;


int exert(object me, object target)
{
	object obj, weapon;
	int xf, af, sp, ap;  
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
	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("necromancy",1) < 30 )
                return notify_fail("你的降伏法功力不够！\n");

	if( (int)me->query_skill("lamaism", 1) < 30 )
                return notify_fail("你的密宗心法功力不够！\n");

	if( (int)me->query_skill("longxiang-banruo", 1) < 30 )
		return notify_fail("你的龙象般若功功力不够！\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能唱。\n");
	
	if( target->query_temp("cursed", 1) || target->query_temp("block_msg/all", 1))
		return notify_fail("此人已被降伏！\n");

	if( (int)me->query_temp("curser") )
                return notify_fail("你降伏着另一各人！\n");

	me->add("neili", - 150 + me->query_skill("necromancy"));
	me->receive_damage("jingli",  100 - me->query_skill("necromancy"));

	message_vision(
		BLU "$N摇头晃脑，口中背诵大乘佛经，夹杂以密宗六字咒。声音阴阳顿挫，有起有伏，暗含音律。\n" NOR, me);

			tell_object(target,  "你觉得那密咒比鬼哭还难听，脑袋里一团絮乱，眼前一堆鬼影在乱跳，胸气阻塞，四肢无力，混然欲睡。\n");
		
	xf = (me->query_skill("necromancy", 1) + me->query_skill("lamaism", 1));
	ap = target->query("jing") + target->query_skill("force") + 
	target->query("con")  + target->query("int") ; 
	sp = me->query_skill("force") + xf * 2;
	sp *= me->query("combat_exp")/1000;
        ap *= target->query("combat_exp")/1000;
	if( random(sp) > ap/2 && !target->query("no_sing")){
	tell_object(target, HIR "你只觉得眼前的一切离你慢慢远去，你的魂魄似要出窍，不再由你主宰。\n" NOR);
	message_vision("你看见" +target->query("name") +"突然开始两眼发直，呆呆地望着前方。\n", me);
	target->remove_all_killer();
	target->set_temp("cursed", 1);
	target->set_temp("block_msg/all", 1);
	me->set_temp("curser", 1);
	if((int)target->query("combat_exp") > me->query("combat_exp")/2
	&& userp(target)){
		me->improve_skill("necromancy", me->query("int"));
		me->add("combat_exp", 1);
	}

	call_out("del_sung", me->query_skill("necromancy", 1)/2, me, target);
	return 1;
	}
	else{
	me->start_busy(random(7));
	if( !target->is_killing(me) ) target->kill_ob(me);	
	return 1;
	}
}
void del_sung(object me, object target)
{
	object link_ob;

        if ( me->query_temp("curser") )
        me->delete_temp("curser");
	if (!target) return;
	if (target->query_temp("cursed", 1))
	target->set_temp("cursed", 0);
	if (target->query_temp("block_msg/all", 1))
	target->set_temp("block_msg/all", 0);
	if (target->query_leader() ) 
        target->set_leader(0);	
	message_vision("$N慢慢地清醒过来，魂魄又回到了自己身体上。\n", target);

/*	link_ob = target->query_temp("link_ob");

        if( link_ob ) {
                if( link_ob->is_character() ) {
                        message_vision("$N的魂魄回到" + link_ob->name(1) + "的身上。\n", me, target);
                        exec(link_ob, target);
                        target->delete_temp("link_ob");
			link_ob->setup();
                        return;
                }

                link_ob->set("last_on", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
                destruct(link_ob);
        }
*/
}

