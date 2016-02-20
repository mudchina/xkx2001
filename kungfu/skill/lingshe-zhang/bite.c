//Cracked by Roath
// bite (纵蛇咬人)

#include <ansi.h>
#define SNAKE_STAFF this_player()->query_temp("weapon")

inherit F_SSERVER;
inherit F_DBASE;

//void remove_bite(object);

int perform(object me, object target)
{
	string type, snake_path;
	object weapon, snake;
	int t, lv, poison, poi_amount, train_lv, snake_lv;
	
	t = (int)me->query_temp("baituo/bite");
	lv = (int)me->query_skill("lingshe-zhang", 1);
	poison = (int)me->query_skill("poison", 1);
	train_lv = (int)me->query_skill("training", 1);

	poi_amount = lv + poison;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("你只能纵蛇偷袭战斗中的对手。\n");
		
	if (lv < 200 )
		return notify_fail("你的灵蛇杖法不够娴熟，无法在使杖攻敌之余纵蛇伤人。\n");

	if (poison < 200 )
		return notify_fail("你对使毒的法门所知有限。\n");

	if (!objectp(weapon = me->query_temp("weapon")))
		 return notify_fail("你手上没有盘蛇的兵器。\n");

	type = weapon->query("snake_type");

	if ( !type && weapon->query("id") != "shezhang")
		return notify_fail("你的"+weapon->name()+"上并没有蛇。\n");

	if( t && (time() - t) < 10 )
		return notify_fail("你刚刚已经纵蛇伤人，这麽快就故技重施，祗怕难以奏效。\n");

	if( me->query_skill("training",1) < 100 )
	       return notify_fail("你的驭兽术无法顺利驱使毒蛇伤人。\n");

	if( me->query("neili") < poi_amount)
		return notify_fail("你的内力不够，难以在纵蛇袭击时稳控"+weapon->name()+"。\n");

	if( me->query("jingli") < 300)
		return notify_fail("你的精力不够，难以在纵蛇袭击时稳控"+weapon->name()+"。\n");

	if( me->query_skill_mapped("force") != "hamagong")
		return notify_fail("你所用的内功与「灵蛇杖法」气路相悖！\n");

	me->add("neili", -(poi_amount/2 +50));
	me->add("jingli", -200);

	switch (type) {
	case "怪蛇" :
	snake_path = "/d/xingxiu/npc/guaishe";
	break;
	case "灵蛇" :
	snake_path = "/d/xingxiu/npc/lingshe";
	break;
	default:
	snake_path = "/d/xingxiu/npc/snake";
	type = "毒蛇";
	}
	
	seteuid(getuid());

	snake = new(snake_path);

	snake_lv = (train_lv + lv)*2/3;

	snake->set("bite_busy",1);
	snake->set("env/invisibility", 10);
	snake->set("owner",me);
	snake->move(environment(me));
	snake->set("default_actions", (: call_other, __FILE__, "query_action" :));
	snake->set("combat_exp",me->query("combat_exp"));

	snake->add_temp("apply/speed", 2);
	snake->add_temp("apply/attack", snake_lv);
	snake->add_temp("apply/damage", snake_lv/4 );
	snake->set("neili",me->query("neili"));
	snake->set("jingli",me->query("max_jingli")*2);
	snake->set("mex_jingli",me->query("mex_jingli"));
	snake->set("snake_poison", poi_amount*3 );
	snake->kill_ob(target);

	message_vision(HIB"\n$N将"+weapon->name()+HIB"一抖，杖上金环当啷啷一阵乱响，一条"+type+HIB"从杖底直盘上来。\n"NOR,me);

	me->start_busy(1);

	COMBAT_D->do_attack(snake, target, snake->query_temp("weapon"));

	if(weapon->query("snake") == 2) {
	snake->set("second_attack",1);
	COMBAT_D->do_attack(snake, target, snake->query_temp("weapon"));
	}

	destruct(snake);

	target->kill_ob(me);
	me->set_temp("baituo/bite",time());

	call_out("remove_bite", 10, me, type);

	return 1;
}

void remove_bite(object me, string type)
{
	me->delete_temp("baituo/bite");
	tell_object(me, type+"昂起了头，嘶地一吐舌头。\n");
}

mapping query_action(object me)
{
	string msg1, msg2;
	msg1 = HIR"祗见"+SNAKE_STAFF->name()+HIR"从$n眼前掠过，缠杖盘旋的一条$N吞吐伸缩，猛然张口咬向$n$l，狰狞诡异之极！"NOR;
	msg2 = HIW BLK"一条$N才刚窜出，冷不防"+SNAKE_STAFF->name()+HIW BLK"上另一条$N也已悄没声息地昂首而起，一口向$n$l咬去！"NOR;
	return ([
	"action": me->query("second_attack") ? msg2 : msg1,
	"force" : 400,
	"dodge" : 0,
	"parry" : 0,
	"damage" : 400,
	"weapon" :"毒牙",
	"damage_type":"咬伤"]);
}
