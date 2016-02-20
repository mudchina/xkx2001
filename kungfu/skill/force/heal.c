//Cracked by Roath
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **\
 * heal.c 内功治疗内伤功能						*
 *									*
 * 内功应该拥有几种共有的功能，像已有的打坐、吐呐、运气、运精、运精力， *
 * 以及开放中的比拼内力。其中运转内息治疗内伤也应该是所有内功都应该有的 *
 * 功能。								*
 * 侠客行现有的伤害系统，在内伤和外伤完全没有区别。内伤外伤是两码子事， *
 * 内功高，内伤自然容易好。外伤却未必，又不是神功一运，立即镇伤生肌，那 *
 * 变成生化人了。所以外伤在大部份情况下只能借助于外界药物的辅助来治疗。	*
 * 基本上普通内伤都可以通过运转内息来治疗，所差者不过於不同内功在於治疗 *
 * 方面效果的好坏，而且如果伤势越重，效果越小，不像以前侠客行一次多少内 *
 * 力、就固定恢复多少。通过内伤的康复，慢慢会加快治愈速度。而外伤的康愈 *
 * 速度，多半则取决于其伤势的程度，所用药物的药性，以及本身的肌肉构造， *
 * 也就是侠客行里面的constitution。					*
 * 至于如何体现出内外伤的不同，而将侠客行的伤害系统做得更合理性，这些是 *
 * 以后所要改变的，这里所要说明的只是以下功能只是以内伤作为前提考虑，所 *
 * 以或许对于现侠客行现有的伤害系统会有少许的不合理性。			*
 *									*
 * Maco && xQin 11/99							*
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

#include <ansi.h>

int curing(object);
int halt_curing(object);
void remove_pending(object);

mapping eff_heal = ([
	"jiuyang-shengong"	: 9,	// 九阳神功在疗伤方面的效果无可置疑。
	"hunyuan-yiqi"		: 8,	// 鉴於易筋经以及九阳神功在疗伤方面的效果。
	"zixia-gong"		: 8,
// 紫霞神功及混元功在自疗方面没有什么提及，但是有鉴於其疗人的效果，以及岳不群曾经想让令狐冲
// 自习紫霞神功来治疗内伤，可见於自疗方面的效果，或许可以与易筋经相媲美。就算是有所不及，考
// 虑到当今紫霞神功没有什么特别的exert，也应当让紫霞神功在治疗方面的效果相对於其他内功更好。
	"taiji-shengong"	: 7,
	"xiantian-gong"		: 7,	// 书中有相当篇幅提到武当九阳功与全真玄门内功的疗伤。
	"kurong-changong"	: 6,	// 大理内功在疗人方面的效果很好，可是在自疗方面却没
					// 有什么特别之处。
	"linji-zhuang"		: 6,	// 峨嵋内功在疗伤方面没有什么特别描述，不过因其是九
					// 阳一系。
	"taixuan-gong"		: 5,
	"bitao-xuangong"	: 5,
	"yunu-xinjing"		: 5,
	"xiaowuxiang"		: 5,
	"huntian-qigong"	: 4,	// 混天功、蛤蟆功、龙象般若功走的都是刚猛一路的内功，
	"hamagong"		: 4,	// 因此在疗伤方面会相对弱些。
	"longxiang-banruo"	: 4,
	"beiming-shengong"	: 3,	// 北冥神功吸人内力，体内真气相冲会影响疗伤时的效果。
	"huagong-dafa"		: 2,	// 化功大法以毒练功，在疗伤方面效果应该最为不好。
	"dulong-dafa"		: 2,
	"hongming-xuangong"	: 1,
	"ding-force"		: 1,	// 以上三种内功书中未有提及，被列为不可考。
]);

int exert(object me)
{
	string force_skill;
	mapping msg;

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if( me->is_busy() || me->query_temp("exit_blocked") )
		return notify_fail("你现在正忙着呢。\n");

	if( me->query_temp("cursed") )
		return notify_fail("什么？\n");

	if( me->query("rided") )
		return notify_fail("在坐骑上运功疗伤，会走火入魔。\n");

	if( !(force_skill = me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

	if( me->query_skill("force", 1) < 50 )
		return notify_fail("你对内功的认识还不够，不知如何搬运内息疗伤。\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力修为太低，尚无法搬运内息疗伤。\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你体内的真气不够。\n");

	if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		return notify_fail("你并未受到内伤。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");

	msg = SKILL_D(force_skill)->curing_msg(me);

	if( !msg || undefinedp(msg["start_self"]) )
		tell_object(me, HIW"你全身放松，坐下来开始运功疗伤。\n"NOR);
	else	tell_object(me, msg["start_self"]);

	if( !msg || undefinedp(msg["start_other"]) )
		message("vision", me->name() +"盘膝坐下，开始运功疗伤。\n"NOR,
			environment(me), me);
	else	message("vision", msg["start_other"], environment(me), me);

	if( !msg || undefinedp(msg["apply_short"]) )
		me->set_temp("apply/short", ({ me->name() +"正坐在地下运功疗伤。"}));
	else	me->set_temp("apply/short", ({ msg["apply_short"] }));

	me->set_temp("pending/curing", 1);
	me->start_busy((: curing :), (: halt_curing :));
	me->set("jiali", 0);
	return 1;
}

int curing(object me)
{
	int effect, lvl, con, max, eff;
	string force_skill;
	mapping msg;
        
	if( !living(me) || me->is_ghost() || !(force_skill = me->query_skill_mapped("force")) )
	{
		remove_pending(me);
		return 0;
	}

	msg = SKILL_D(force_skill)->curing_msg(me);

	if( me->query("jing") < 1 || me->query("jingli") < 1 )
	{
		remove_pending(me);
		me->unconcious();
		return 0;
	}
	else if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
	{
		if( !msg || undefinedp(msg["finish_self"]) )
			tell_object(me, HIY"你运功良久，自觉经脉顺畅，内伤尽去，神元气足地站了起来。\n"NOR);
		else	tell_object(me, msg["finish_self"]);

		if( !msg || undefinedp(msg["finish_other"]) )
			message("vision", me->name() +"运功完毕，站起身来，看上去气色饱满，精神抖擞。\n"NOR,	environment(me), me);
		else	message("vision", msg["finish_other"], environment(me), me);

		remove_pending(me);
        	return 0;
	}
	else if( (int)me->query("neili") < 50 )
	{
		if( !msg || undefinedp(msg["unfinish_self"]) )
			tell_object(me, "你正在运功疗伤，忽觉内息後继乏力，祗得暂缓疗伤，站起身来。\n"NOR);
		else	tell_object(me, msg["unfinish_self"]);

		if( !msg || undefinedp(msg["unfinish_other"]) )
			message("vision", me->name() +"运功完毕，缓缓站了起来，脸色看起来好了许多。\n"NOR,environment(me), me);
		else	message("vision", msg["unfinish_other"], environment(me), me);

		remove_pending(me);
		return 0;
	}

	lvl = me->query_skill("force");	// my enable force level.
	max = me->query("max_neili");	// my max neili.
	con = me->query("con");		// my original constitution.
	eff = eff_heal[force_skill];	// my force's effect on heal.
	if( !eff ) eff = 1;

	effect = lvl * max/10 * eff / (2*lvl + lvl*con*2/30) / 10;

	con = me->query_con();		// use apply constitution instead of original here.
	effect = (effect+random(effect))/2 + (con+random(con))/4;
	effect = effect * ((int)me->query("eff_qi")*100 / (int)me->query("max_qi")) / 100;

	if( wizardp(me) ) tell_object(me, "每次治愈"+chinese_number(effect)+"点内伤。\n");
	me->receive_curing("qi", effect);
        me->receive_heal("qi", effect/2);
	me->add("neili", -50);
	return 1; 
}

int halt_curing(object me)
{
	string force_skill;
	mapping msg;

	force_skill = me->query_skill_mapped("force");
	if( force_skill ) msg = SKILL_D(force_skill)->curing_msg(me);

	me->receive_damage("qi", 50, "内功走火入魔死了");
	me->add("neili", -50);
	if( me->query("neili") < 0 ) me->set("neili", 0);

	if( !msg || undefinedp(msg["halt_self"]) )
		tell_object(me, "你吐气纳息，硬生生地将内息压了下去，缓缓站了起来。\n");
	else	tell_object(me, msg["halt_self"]);

	if( !msg || undefinedp(msg["halt_other"]) )
		message("vision", me->name() +"身子一震，吐出一口瘀血，缓缓站了起来。\n", environment(me), me);
	else	message("vision", msg["halt_other"], environment(me), me);

       	remove_pending(me); 
	me->start_busy(1+random(3));
	return 1;
}

void remove_pending(object me)
{
	me->delete_temp("pending/curing");
	me->delete_temp("apply/short");
}
