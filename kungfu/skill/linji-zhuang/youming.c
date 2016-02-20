//Cracked by Roath
// youming.c
// Chu 1/27/99
// Haowen /9/09/00
// Haowen /9/11/00
#include <ansi.h>

#define TRAVERSER "/clone/obj/traverser"

//#define DEBUG printf
#define DEBUG 

void make_youmin_effect(object me, int range);

int exert(object me, object target)
{
	int level = me->query_skill("linji-zhuang", 1);
        int range ;

	if (level < 180) return notify_fail("你的临济十二庄修为还不够。\n");

	if( (int)me->query("max_neili") < 15*level ) 
		return notify_fail("你的内力还不够强。\n");

	if( (int)me->query("neili") < 15*level ) 
		return notify_fail("你的真气不够。\n");

//	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
//		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	
	write(HIY "你凝聚幽冥二气，口宣佛号: 阿弥陀佛！一股极细密极悠长的内力从心而发, 直上云霄！\n" NOR); 
	message("vision",
		HIY + "只见" + me->name() + "凝聚幽冥二气，低眉垂首, 口宣佛号: 阿弥陀佛! 语音虽低却憾人心肺!\n", 
		environment(me), me);

	me->add("neili", -15*level);
	me->add("max_neili", -5);

   	// decide how far this perform can affect:
	range = 1+(level-180)/4;
	log_file("skill_usage", 
	    sprintf("%s: %s(%s) exerted youmin: lvl=%d, range=%d\n",
		ctime(time()), me->name(), geteuid(me), level, range));
 	make_youmin_effect(me, range);
	return 1;
}

void hitself(object me, object *bad_guys, int degree) 
{
    int i,a0,a1,b0,b1;
    object killer,room;
    
    for (i=0; i<sizeof(bad_guys); i++) {
	killer = bad_guys[i];
 	if (killer == 0) continue;
        a0=killer->query("PKS");
        a1=killer->querry("death_times");
        b0=me->query("PKS");
        b1=me->querry("death_times");
        if (a1==0) a1=1;
        if (b0==0) b0=1;
        if (b1==0) b1=1;
//	shen1=me->query("shen");
//	shen2=killer->query("shen");
//	if(shen2<0)
//      shen2=-1*shen2;

	if(random(a0/a1)>random(b0/b1))
	{/*success to let this player hit-self*/
	switch (degree) {
	case 1:   // lightest
	    message_vision("$n想起自己所做的种种恶行, 羞惭得两腮发红, 提手便照自己打去。\n", 
		killer, killer);
  	    killer->add_temp("apply/defense", -200);
  	    killer->add_temp("apply/dodge", -200);
  	    killer->add_temp("apply/parry", -200);
	    break;
	case 2:   // medium
	    message_vision("$n想起自己过去杀人如麻, 心中一凛, 不禁双手打颤, 缓缓向自己灵台打下。\n", 
		killer, killer);
  	    killer->add_temp("apply/defense", -200);
  	    killer->add_temp("apply/dodge", -200);
  	    killer->add_temp("apply/parry", -200);
  	    killer->add_temp("apply/attack", 100);
  	    killer->add_temp("apply/damage", 50);
	    COMBAT_D->do_attack(killer, killer, killer->query_temp("weapon"));
	    break;
	case 3:   // hardest
	    message_vision("$n仰天叹道: 便似我这等孽障, 活在人间作甚！当下回手往自己死穴猛击！\n", 
		killer, killer);
  	    killer->add_temp("apply/defense", -200);
  	    killer->add_temp("apply/dodge", -200);
  	    killer->add_temp("apply/parry", -200);
  	    killer->add_temp("apply/damage", 100);
  	    killer->add_temp("apply/attack", 200);
//  	    killer->set("jiali", killer->query("max_neili")/15);
	    COMBAT_D->do_attack(killer, killer, killer->query_temp("weapon"));
	    COMBAT_D->do_attack(killer, killer, killer->query_temp("weapon"));
	    break;
 	}
	COMBAT_D->do_attack(killer, killer, killer->query_temp("weapon"));
        killer->start_busy(3);
	switch (degree) {
	case 1:   // light
  	    killer->add_temp("apply/defense", 200);
  	    killer->add_temp("apply/dodge", 200);
  	    killer->add_temp("apply/parry", 200);
	    break;
	case 2:   // medium
  	    killer->add_temp("apply/defense", 200);
  	    killer->add_temp("apply/dodge", 200);
  	    killer->add_temp("apply/parry", 200);
  	    killer->add_temp("apply/attack", -100);
  	    killer->add_temp("apply/damage", -50);
	    break;
	case 3:   // hardest
  	    killer->add_temp("apply/defense", 200);
  	    killer->add_temp("apply/dodge", 200);
  	    killer->add_temp("apply/parry", 200);
  	    killer->add_temp("apply/damage", -200);
  	    killer->add_temp("apply/attack", -100);
//  	    killer->set("jiali", 0);
	    break;
 	}
	}
	else/*fail to effect this player*/ 
	{
//	room=environment(me);
//	if( (environment(killer)->query("id"))!= (room->query("id")))
//		/*not in same room*/
//		killer->move(room);
        if (present(me,environment(killer))) {
message_vision(HIR"$N冲着$n破口大骂：就凭你这样的货色也敢在我面前指手划脚，还不给我滚得远远的！\n"NOR,killer,me);
//	tell_object(me,HIR"你的正气不够压制对方,反而激怒对手!"NOR);
	me->start_busy(1+random(1));
//	if( !killer->is_killing(me) ) killer->kill_ob(me);
	COMBAT_D->do_attack(killer, me, killer->query_temp("weapon"));
	}
        }
    }
}

object *find_bad_guys(object me, object room)
{
    int i, n;
    object killer, *inv, *ret;

    inv = all_inventory(room);
    n=0;
    for (i=0; i<sizeof(inv); i++) {
	killer = inv[i];
	if (killer == me) continue;
	if (userp(killer) && living(killer) &&
	    killer->query("PKS") > 10 &&
	    killer->query("PKS") > killer->query("death_times")*2 &&
            killer->is_killing(me->query("id")))
	    n++;
    }
    if (n == 0) return 0;
    ret = allocate(n);
    n=0;
    for (i=0; i<sizeof(inv); i++) {
	killer = inv[i];
	if (killer == me) continue;
	if (userp(killer) && living(killer) &&
	    killer->query("PKS") > 10 &&
	    killer->query("PKS") > killer->query("death_times")*2 &&
            killer->is_killing(me->query("id"))) {
	    ret[n] = killer;
            if (me->query("id")=="yasuko") tell_object(me,"Bad guy is "+killer->query("id")+". \n");
	    n++;
  	}
    }
    return ret;
}

void stop_fighting(object me, object room)
{
    int i;
    object killer, *inv;

    inv = all_inventory(room);
    for (i=0; i<sizeof(inv); i++) {
	killer = inv[i];
	if (killer->is_fighting()) {
	    killer->remove_all_killer();
	    killer->start_busy(5);
	}
    }
}


// 
// We traverse the map within range to make youmin effects, we try to stop
// everybody who fights and if a guy kills too many players (bad guy), he
// will be very upset and may try to hurt himself.
//
// There are 4 cases:
// distance < range/7: bad guys try to hurt self real hard
// distance < range/5: bad guys try to hit self hard
// distance < range/3: bad guys try to hit self
// distance < range: everybody stop fighting
//
// range = (ljz-180)/2, so a 200 lvl player can make it range 10

int visit_room(string room_path, mapping t_info, mapping r_info, mapping data) 
{
	int dist, range;
	object me, room, *bad_guys;
	string dist_msg, dist_msg2;

	dist = t_info["dist"];
	if (dist >= 15) return -1; // don't affect more than 15 steps

	room = find_object(room_path);
	if (! objectp(room))  return (dist>=range)?1:0;
	if (room->query("no_fight"))  return (dist>=range)?1:0;
	
 	me = data["user"];
	range=data["range"];
        bad_guys = find_bad_guys(me, room);
        stop_fighting(me,room);
	if (dist < range) {
	    dist_msg = "";
	    dist_msg2 = "";
	    if (dist > 10) {
		dist_msg="极遥远处";
		dist_msg2="虽然声音极远极轻, 却令";
	    }else if (dist > 5) {
		dist_msg="远处";
		dist_msg2="虽然声音不大, 却令";
	    }
	    message("vision",
		HIY+"只听"+dist_msg+me->name()+"口中佛号不绝传来, 其意大慈大悲, 通幽冥, 越生死, 浑不似人间所有。\n"+
		dist_msg2+"众人听的都呆住了, 不自觉地停手罢斗。\n"+NOR,
		room, me);
	    if (bad_guys) {
		if (dist < range/7) {
		    hitself(me, bad_guys, 3);
		}else if (dist < range/5) {
		    hitself(me, bad_guys, 2);
		}else  if (dist < range/3) {
		    hitself(me, bad_guys, 1);
		}
   	    }
	    return 0;
	}
	return 1;
}

void make_youmin_effect(object me, int range)
{
	object traverser;
	mapping data;

        DEBUG("making youmin effect: range=%d\n", range);

	seteuid(getuid());
	traverser = new (TRAVERSER);

 	if (! objectp(traverser)) {
  	    write("youming.c: tell wiz traverser not found!\n");
	    return;
	}
	
	data = ([ "user":me ]);
	data["range"]=range;
	traverser->traverse(base_name(environment(me)), (: visit_room :), data);
	destruct(traverser);
}
