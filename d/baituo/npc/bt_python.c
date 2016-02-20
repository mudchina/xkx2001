//Cracked by Roath
// baituo python 白驼山蛇谷的大蛇、蟒蛇
// by maco 
#include <ansi.h>

inherit NPC;

int auto_perform_duwu();
int auto_perform_chan();

void create()
{
	int s, poison;

	s = random(40);
	poison = random(3);

	switch( poison )
	{
	case 0:
		set_name("巨蟒", ({ "ju mang", "she", "mang", "python" }) );
		set("long", "一条碗口粗细的三角头巨蟒，有两丈多长。\n");
		set("chat_msg_combat", ({
			(: auto_perform_chan :),
		}));
		break;
	case 1:
		set_name("大蛇", ({ "da she", "she", "snake", "dashe" }) );
		set("long", "一条身长两丈，粗如人臂的大蛇，全身斑斓五色，一颗头作三角形，比人的拳头还大。\n"
		"寻常大蛇无毒，此蛇如此巨大，却是毒蛇，实在罕见。\n");
		set("snake_poison", 340 +random(61));
		set("chat_msg_combat", ({
			(: auto_perform_duwu :),
		}));
		break;
	case 2:
		set_name("毒蟒", ({ "du mang", "she", "mang", "snake", "python"}) );
		set("long", "一条白身黑章的大蟒蛇，蟒头作三角形，头顶上高高生了一个\n"
		"凹凹凸凸的肉瘤，身长二丈，粗逾手臂。\n"
		"蟒蛇本来无毒，这条大蟒却生的如此异状，又具剧毒，实是希罕。\n");
		set("snake_poison", 380 +random(61));
		set("chat_msg_combat", ({
			(: auto_perform_chan :),
			(: auto_perform_duwu :),
		}));
		break;
	}
	set("race", "蛇类");
	set("age", 100);
	set("attitude", "peaceful");

	set("str", 30 + poison );
	set("con", 40 + poison );
	set("int", 10);
	set("dex", 30 + poison );
	
	set("max_jing", 4000);
	set("max_qi", 4000);
	set("max_jingli", 2000);

	set("combat_exp", poison*100000 + 500000);
	set("chat_chance_combat", 30);

	set_temp("apply/attack", 300 + s);
	set_temp("apply/damage", 200 + s);
	set_temp("apply/armor", 400 + s);
	set_temp("apply/parry", 300 + s);
	set_temp("apply/dodge", 260 + s);
	set("bt_snake", 1);

	setup();
}

void init()
{
	object me;
	::init();
	me = this_object();
	add_action("convert","bian");
	add_action("do_struggle","struggle");
	add_action("do_struggle","zhengza");

	if (!me->is_fighting() && living(me) && !me->is_busy()
	&& !environment(me)->query("no_fight") ) {
		remove_call_out("hunting");
		call_out("hunting", 1, me, this_player());
	}
}

void hunting(object me, object ob)
{
	if(random(4) != 0 && !me->is_fighting() && living(me) && !me->is_busy() 
	&& !environment(me)->query("no_fight")) 
		set_temp("hunting", ob->query("id"));

	if (present(ob, environment(me))) {
		if (!ob->is_character() && ob->query("my_killer") != me->query("id")) {
			message_vision("$N在$n旁边绕了几圈，嘶地一吐信，慢慢蜿蜒游开，似乎不感兴趣。\n", me, ob);
			return;
		}
		else if( query_temp("hunting") && !me->is_fighting() && living(me) 
		&& !me->is_busy() && !environment(me)->query("no_fight") ){

			if(random(2) == 0) {
			message("vision", HIR"你忽然闻得一阵腥风，猛见"+me->name()+"张开大口，露出獠牙，疾向"+ob->name()+"咬去！\n"NOR, environment(ob), ob);
			tell_object(ob,HIR"你耳中忽闻嘶嘶声响，一迟疑间，蓦地腥臭迎面，"+me->name()+"猛然向你张口扑来！\n"NOR);
			COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
			kill_ob(ob);
			delete_temp("hunting");
			}
			else {
			remove_call_out("hunting");
			call_out("hunting", 2, me, ob); 
			}
			return;
		}

		else message_vision("$N听到$n过来的声息，立时盘曲成团，昂起了头，伸出血红的舌头，嘶嘶作声。\n", me, ob);
	}
	return;
}


void chaning(object me, object ob)
{
	int ap, dp, pp, jingli, damage;

	string *chan_msg = ({
		HIR"\n$n暗运劲力，想将缠在身上的$N崩断。但$N身子可伸可缩，只略加延伸，并不会断。\n"NOR,
		HIR"\n$N猛力缠紧，只箍得$n腰骨几欲折断。\n"NOR,
		HIR"\n$N身子一卷到$n，越收越紧，再也不放，$n渐渐给$N缠得喘不过气来。\n"NOR,
		HIR"\n$n被$N缠住，除了呻吟怒骂，再无反抗的能为。\n"NOR,
	});
	string *chan_beast_msg = ({
		HIR"\n$N猛力缠紧，不让$n有机会逃脱。\n"NOR,
		HIR"\n$N身子一卷到$n，越收越紧，再也不放，$n渐渐给$N缠得喘不过气来。\n"NOR,
		HIR"\n$n被$N缠住，慢慢失了抗拒之力，气息越来越是微弱。\n"NOR,
	});

	string *chan_snake_msg = ({
		HIR"\n$N猛力缠紧，牢牢箍住$n的七寸。\n"NOR,
		HIR"\n$N身子一卷到$n，越收越紧，再也不放，$n渐渐给$N缠得喘不过气来。\n"NOR,
		HIR"\n$N将$n紧紧缠住，慢慢施力，$n虽然不断扭动蛇身，却也无法脱困。\n"NOR,
	});
	string *chan_bird_msg = ({
		HIR"\n$N猛力缠紧，只箍得$n双翅几欲折断。\n"NOR,
		HIR"\n$n被$N缠住，吱吱乱叫，翅膀不停扑打。\n"NOR,
		HIR"\n$N愈盘愈紧，$n毛羽贲张，竭力相抗，眼见不支。\n"NOR,
	});

	string chan;
	switch (ob->query("race")) {
	case "人类" :	chan = chan_msg[random(sizeof(chan_msg))];	break;
	case "飞禽" :	chan = chan_bird_msg[random(sizeof(chan_bird_msg))];	break;
	case "蛇类" :	chan = chan_snake_msg[random(sizeof(chan_snake_msg))];	break;
	case "野兽" :
	case "家畜" :	chan = chan_beast_msg[random(sizeof(chan_beast_msg))];	break;
	default:	return 0;
	}
	
	
	jingli = me->query("jingli");
	ap = jingli + random(jingli);
	pp = ob->query("jiali") + ob->query_str()*random(10) + (int)ob->query_skill("force");
	damage = (ap - pp)/3;
	
	if(damage > 1000 ) damage = 1000;
	if(damage < 100 ) damage = 100;
	
	if(wizardp(ob)) 
	tell_object(ob,sprintf("ap：%d ,pp：%d ,damage：%d \n" ,ap,pp,damage));

	if(!ob) {
		me->delete_temp("chaning");
		return;
	}
	if (present(ob, environment(me))) {
	
		if( !me->query_temp("chaning") || !ob->query_temp("snake_chan") ) {
		me->delete_temp("chaning");
		ob->delete_temp("snake_chan");
		return;
	}

		if (!living(ob) ) {  //猎物昏了就咬死
			if(ob->query("race") == "人类") 
				message_vision(HIR"这时$n已给$N缠得奄奄一息，$N张开大口，咬住了$n，腿脚先入蛇口，慢慢的给吞至腰间，又吞至胸口。\n"NOR, me, ob);
			else message_vision(HIR"这时$n已给$N缠得奄奄一息，$N张开大口，一口便将$n咬死。\n"NOR, me, ob);
			ob->receive_wound("qi", (ob->query("qi")+100), "被"+me->name()+"咬死了");
			ob->receive_damage("qi", (ob->query("qi")+100), "被"+me->name()+"咬死了");
			ob->delete_temp("snake_chan");
			me->delete_temp("chaning");

			return;
		}

		else if (!ob->is_character() ) {  //猎物死了就放开
			message_vision("$N松开身子，放开了$n，四下蜿蜒游走。\n", me, ob);
			ob->delete_temp("snake_chan");
			me->delete_temp("chaning");
			return;
		}
		else {

			if(ap < random(pp) || jingli < 500 ) {
			message_vision("$N似乎敌不过$n的劲力，慢慢松开身子，放开了$n，四下蜿蜒游走。\n", me, ob);
			ob->delete_temp("snake_chan");
			me->delete_temp("chaning");
			}
			else {
			message_vision(chan , me, ob);
			ob->start_busy(3);
			me->start_busy(2);
			me->add("jingli", -(pp/20));

			ob->add("jingli", -damage/4);
			ob->receive_wound("qi", random(damage/10), "被"+me->name()+"缠死了");
			ob->receive_damage("qi", damage/2, "被"+me->name()+"缠死了");

			remove_call_out("chaning");
			call_out("chaning", 1, me, ob); 
			}
			return;
		}
	}

	return;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( me->query("snake_poison") > 0 && !victim->query("snake_poison")) 
	victim->apply_condition("snake_poison", 20 + me->query("snake_poison")/5 +
		victim->query_condition("snake_poison") );

	if(me->query_temp("try_chan")) {
	me->set_temp("chaning", victim->query("id"));
	victim->set_temp("snake_chan",1);
	victim->start_busy(3);
	me->start_busy(2);
	remove_call_out("chaning");
	call_out("chaning", 1, me, victim); 
	
	if(victim->query("race") == "人类") return HIR"$n一个疏神，腰间已被$N缠住。$N随即在$n身上绕了数匝，连手臂也绕在其中，令$p再也没法抗拒。\n"NOR;
	else return HIR"这一下$n没有躲开，$N立刻在$p身上绕了几匝，$n顿时动弹不得。\n"NOR;
	}

}

int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="snake" && arg!="she") return 0;
	if (me->query("family/family_name") != "白驼山") 
		return notify_fail("你不能化蛇为杖。\n");

	return notify_fail(this_object()->name()+"身子太过粗大，无法化为蛇杖。\n");
}

int do_struggle(string arg)
{
	object me, snake;
	int ap, jingli, jiali;

	me = this_player();
	snake = this_object();

	if( snake->query_temp("chaning") != me->query("id"))
		return 0;
	if( !me->query_temp("snake_chan") || !me->is_busy() )
		return 0;

	jingli = snake->query("jingli");
	jiali = me->query("jiali");
	ap = jingli + random(jingli);

	if(me->query_temp("struggle_snake") > 4) {
		message_vision(HIW"\n$N用力挣了一挣，想摆脱缠住身子的$n.....\n"NOR, me, snake);
		message_vision(HIR"\n不料$N身子动得太厉害，激怒了缠住了$P的$n，一口便咬住$P的咽喉！\n"NOR, me, snake);
		me->receive_wound("qi", random(ap/2), "被"+me->name()+"咬死了");
		me->receive_damage("qi", ap/2, "被"+me->name()+"咬死了");
		me->unconcious();
	}
	else {
		message_vision(HIW"\n$N用力挣了一挣，想摆脱缠住身子的$n.....\n"NOR, me, snake);
		me->add("neili", -jiali);
		snake->add("jingli", -jiali*2 );
		me->add_temp("struggle_snake", 1);
		remove_call_out("remove_effect");
		call_out("remove_effect", 1, me);
	}

	return 1;
}

void remove_effect(object me)
{
	me->delete_temp("struggle_snake");
}

#include "snake_perform.h"
