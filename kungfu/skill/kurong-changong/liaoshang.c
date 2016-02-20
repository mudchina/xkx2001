//Cracked by Roath
// liaoshang.c 运气疗伤
// mantian may/11/2001
// only can liaoshang in sleep room or hotel 

inherit F_SSERVER;
inherit F_DBASE;
#include <ansi.h>
#include <combat.h>
#include "poison_list.h"

int exert(object me, object target)
{
	int i;
	string poison, tempLook;
	object where = environment(me);

	me = this_player();
	if( !target || target==me || !target->is_character() || target->query("race") != "人类" ) return notify_fail(HIW"你要为谁疗伤？\n"NOR);
	if (me->is_fighting() || target->is_fighting()) return notify_fail(HIW"战斗中运功疗伤？找死吗？\n"NOR);
	if (me->query__temp("liaoshang")) return notify_fail(HIW"你已经在为"+me->query__temp("liao/targetname")+"("+me->query__temp("liao/target")+")疗伤了。\n"NOR);
	if ((int)me->query_skill("kurong-changong", 1) < 120) return notify_fail(HIW"你的枯荣禅功修为还不够为他人运功疗伤。\n"NOR);
	if ((int)me->query_skill("yiyang-zhi", 1) < 150) return notify_fail(HIW"你的一阳指修为还不够为他人疗伤。\n"NOR);
	if (!(where->query("sleep_room")) && !(where->query("hotel"))) return notify_fail(HIW"这里太吵了，你无法静下心来替人疗伤！\n"NOR);

	for( i=0; i < sizeof(poison_list); i++ )
		if (me->query_condition(poison_list[i]["poison"]) > 0) return notify_fail(HIW"你身受"+poison_list[i]["name"]+poison_list[i]["type"]+"，无法为他人疗伤。\n"NOR);
	for( i=0; i < sizeof(poison_list); i++ )
		if( target->query_condition(poison_list[i]["poison"]) > 0 )
		{
			poison = poison_list[i]["poison"];
			break;
		}
		if (poison == 0) return notify_fail(HIW+target->name() + "身体并无异样。\n"NOR);
	if( (int)me->query("neili") < 2000 ) return notify_fail(HIW"你的真气不够为他人疗伤所需。\n"NOR);
	target->start_busy(30);
	target->set_temp("liao/healer", me->query("id"));
	me->start_busy(30);
	me->set_temp("liaoshang", 1);
	me->set_temp("liao/target", target->query("id"));
	me->set_temp("liao/targetname", target->query("name"));
	tempLook = me->short();
	tempLook += CYN" <诊视中>"NOR;
	if (me->query_temp("apply/short")) me->set_temp("liao/short", me->query_temp("apply/short"));
	me->set_temp("apply/short", ({tempLook}));
	message_vision(CYN"$N说道：先看看你的脉象吧。\n\n\n\n\n\n"NOR HIB"说着$N便提起$n的手把了一会脉。\n"NOR, me,target );
	call_out("checking_poison", 15, me, target);
	return 1;
}

void checking_poison(object me, object target)
{
	int neili_drop, poi_amount, finger_drop, i;
	string poison, poi_name, poi_type, msg, tempLook;

	for( i=0; i < sizeof(poison_list); i++ )
		if( target->query_condition(poison_list[i]["poison"]) > 0 )
		{
			poison = poison_list[i]["poison"];
			poi_name = poison_list[i]["name"];
			poi_type = poison_list[i]["type"];
			finger_drop = poison_list[i]["level"];
			neili_drop = poison_list[i]["neili"];
			break;
		}
	poi_amount = (int)target->query_condition(poison, 1);
	if (poi_amount < 4)	msg = "并无异样";
	else if (poi_amount < 50) msg = "并无大碍";
	else if (poi_amount < 70)
	{
		msg = "稍具危险";
		finger_drop = finger_drop+random(finger_drop/2);
		neili_drop = neili_drop+random(neili_drop/2);
	}
	else if (poi_amount < 100)
	{
		msg = "侵入筋脉";
		finger_drop = finger_drop+random(finger_drop*2/3);
		neili_drop = neili_drop+random(neili_drop*2/3);
	}
	else if (poi_amount < 130)
	{
		msg = "深入筋脉";
		finger_drop = finger_drop+random(finger_drop*4/5);
		neili_drop = neili_drop+random(neili_drop*4/5);
	}
	else if (poi_amount < 160)
	{
		msg = "侵入心脉";
		finger_drop = finger_drop+random(finger_drop);
		neili_drop = neili_drop+random(neili_drop);
	}
	else
	{
		msg = "深入心脉";
		finger_drop = finger_drop+random(finger_drop*2);
		neili_drop = neili_drop+random(neili_drop*2);
	}
	if (poison == "sxs_poison")
	{
		if (poi_amount = 3)
		{
			msg = "深入筋脉";
			finger_drop = finger_drop+random(finger_drop*4/5);
			neili_drop = neili_drop+random(neili_drop*4/5);
		}
		else if (poi_amount = 2)
		{
			msg = "侵入心脉";
			finger_drop = finger_drop+random(finger_drop);
			neili_drop = neili_drop+random(neili_drop);
		}
		else if (poi_amount = 1)
		{
			msg = "深入心脉";
			finger_drop = finger_drop+random(finger_drop*2);
			neili_drop = neili_drop+random(neili_drop*2);
		}
	}
	if (poi_amount < 4 && poison != "sxs_poison")
	{
		message_vision(CYN"$N沉思了一会说道：阁下所中的"+poi_name+poi_type+"已"+msg+"，实在无从治起。\n\n"NOR, me,target );
		target->delete_temp("liao/healer");
		target->start_busy(1);
		me->delete_temp("apply/short");
		if (me->query_temp("liao/short")) me->set_temp("apply/short", me->query_temp("liao/short"));
		me->delete_temp("liao");
		me->delete_temp("liaoshang");
		me->start_busy(1);
		return 0;
	}
	message_vision(CYN"$N沉思了一会说道：阁下所中的"+poi_name+poi_type+"已"+msg+"，请容在下为您医治。\n\n\n\n\n\n"NOR, me,target );
	if ((int)target->query_condition("xbiao") > 0) target->set_temp("liao/xbiao", (int)target->query_condition("xbiao", 1));
	if ((int)target->query_condition("biao") > 0) target->set_temp("liao/biao", (int)target->query_condition("biao", 1));
	if ((int)target->query_condition("bonze_drug") > 0) target->set_temp("liao/bonze_drug", (int)target->query_condition("bonze_drug", 1));
	if ((int)target->query_condition("hot_drug") > 0) target->set_temp("liao/hot_drug", (int)target->query_condition("hot_drug", 1));
	if ((int)target->query_condition("cool_drug") > 0) target->set_temp("liao/cool_drug", (int)target->query_condition("cool_drug", 1));
	if ((int)target->query_condition("mang_shedan") > 0) target->set_temp("liao/mang_shedan", (int)target->query_condition("mang_shedan", 1));
	me->delete_temp("apply/short");
	tempLook = me->short();
	tempLook += BLU" <入定中>"NOR;
	me->set_temp("apply/short", ({tempLook}));
	message_vision(YEL"$N当即闭目垂眉，入定运起枯荣禅功。\n\n\n\n\n\n"NOR, me,target );
	me->set_temp("liao/finger_drop", finger_drop);
	me->set_temp("liao/neili_drop", neili_drop);
	me->start_busy(30);
	target->start_busy(30);
	call_out("start_heal", 15, me, target);
}

void start_heal(object me, object target)
{
	string tempLook;

	me->delete_temp("apply/short");
	tempLook = me->short();
	tempLook += HIW" <医治中>"NOR;
	me->set_temp("apply/short", ({tempLook}));
	message_vision(MAG"$N忽然的跃起，左掌捂胸，右手伸出食指，缓缓的向$n头顶百会穴点去。\n"
		"$n身不由几的微微一跳，只觉的一股热气从顶门直透下来。\n\n\n\n\n\n"NOR, me,target );
	target->start_busy(30);
	me->start_busy(30);
	call_out("healing", 15, me, target);
}

void healing(object me, object target)
{
	message_vision(MAG"$N一指点过，立即缩回，第二指已点向$n的百会穴后一寸五分处的后顶穴，\n"
		               "接着强间，脑户，风府，大锥，陶道，身柱，神道，灵台一路点将下来。\n"
					   "一支香燃了一半，已将$n督脉的三十大穴顺次点到。\n\n\n\n\n\n"NOR, me,target );
	target->start_busy(30);
	me->start_busy(30);
	call_out("end_heal", 15, me, target);
}
void end_heal(object me, object target)
{
	int a;

	a = me->query_skill("yiyang-zhi",1);
	message_vision(RED"$n突然觉得一股暖流自顶而入，口中吐出几口黑血，眼前一黑就什么也看不见了！\n\n\n"NOR, me,target );
	target->clear_condition();
	target->start_busy(1);
	target->unconcious();
	if (target->query_temp("liao/xbiao")) target->apply_condition( "xbiao", (int)target->query_temp("liao/xbiao"));
	if (target->query_temp("liao/biao")) target->apply_condition( "biao", (int)target->query_temp("liao/biao"));
	if (target->query_temp("liao/bonze_drug")) target->apply_condition( "bonze_drug", (int)target->query_temp("liao/bonze_drug"));
	if (target->query_temp("liao/hot_drug")) target->apply_condition( "hot_drug", (int)target->query_temp("liao/hot_drug"));
	if (target->query_temp("liao/cool_drug")) target->apply_condition( "cool_drug", (int)target->query_temp("liao/cool_drug"));
	if (target->query_temp("liao/mang_shedan")) target->apply_condition( "mang_shedan", (int)target->query_temp("liao/mang_shedan"));
	me->add("shen", 1000+(int)(target->query("combat_exp")/100));
	me->add("max_neili",-(1+random(me->query_temp("liao/neili_drop"))));
	me->set_skill("yiyang-zhi",(a-(1+random(me->query_temp("liao/finger_drop")))));
	me->add("neili", -1000);
	target->delete_temp("liao/healer");
	me->delete_temp("apply/short");
	if (me->query_temp("liao/short")) me->set_temp("apply/short", me->query_temp("liao/short"));
	me->delete_temp("liao");
	me->delete_temp("liaoshang");
	me->start_busy(1);
}
