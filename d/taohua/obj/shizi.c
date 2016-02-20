//Cracked by Roath
//kane
//maco changed 
#include <ansi.h>
#include <combat.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit F_COMMAND;

int bash_weapon(object me, object victim);

void create()
{
	set_name(YEL"小石子"NOR, ({"xiao shizi", "shizi"}));
	if (clonep())
	set_default_object(__FILE__);
	else {
	set("unit", "堆");
	set("base_unit","粒");
	set("long", "这是随处可见的小石子。\n");
	set("value", 0);
	}
	set_amount(1+random(5));
//	init_throwing(5);
	setup();
}

int init()
{
	add_action("do_tanzhi", "tan");      
}

int do_tanzhi(string arg)
{
	int skill, skill2, thr, dod, tz, parr, diff, jiali, exp, exp2;
	string str, dodge_skill, result, *limbs, limb;
	object me = this_player();
	object victim,weapon;

	if (!arg)    
		return notify_fail("你要干什么？\n");

	if (!(victim = present(arg,environment(me))))
		return notify_fail("这里并无此人！\n");

	if (!victim)
		return notify_fail("这里并无此人！\n");

	if (!living(victim))
		return notify_fail("这不是活物！\n");

	if( me->is_busy() )
		return notify_fail("你前一个动作还没有做完。\n");

	if (victim == me) return notify_fail("何必多此一举？\n");

//	if (!wizardp(me) && wizardp(victim))
//		return notify_fail("大胆！竟想谋害巫师！\n");
        
	if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

	if (me->query_skill("tanzhi-shentong", 1) < 120)
		return notify_fail("学小孩弹石子，不害臊吗？\n");

	tz = me->query_skill("tanzhi-shentong", 1);
	dod = (int)victim->query_skill("dodge");
	parr = (int)victim->query_skill("parry");
	skill = tz/10+random(tz)/2;
	skill2 = (dod + parr)/10;
	diff = skill-skill2;
	jiali = me->query("jiali");
	limbs = victim->query("limbs");
	exp = me->query("combat_exp");
	exp2 = victim->query("combat_exp");
	me->add("neili",- jiali/2);
	limb = limbs[random(sizeof(limbs))];

	message_vision(HIW"$N信手拈起一粒小石子，扣在拇指食指之间，“哧”的一声急响，小石子向$n激射而去......\n" NOR, me, victim);

//	if( exp/3+random(exp/2) > exp2 /2 && skill > skill2){
	if(skill > skill2){

	weapon = victim->query_temp("weapon");

	if( !victim->query_temp("weapon") ) {

		if(jiali >= 240) message_vision(HIY"$n刚听到一点声息，小石子转瞬间划过长空，已击中$n"+limb+"，先声夺人，威不可当！\n" NOR, me, victim);

		else if(jiali >= 200) message_vision(HIY"但听小石子破空之声响亮异常，来势比铁胎弹弓所发还要急劲，转瞬间已击中$n"+limb+"！\n" NOR, me, victim);
		else message_vision(HIY"$n被打个措手不及，虎口登时鲜血长流，手臂再也抬不起来。\n" NOR, me, victim);

	victim->receive_wound("qi", random(jiali) +random(10));
	victim->receive_damage("qi", jiali + random(jiali) + random(10), me);
	}
	else message_vision(HIY"小石子破空飞至，撞在$N手中的" + weapon->name() + HIY"上。\n"NOR,victim);
   
	bash_weapon(me,victim);
	victim->start_busy(1+random(2));

	victim->receive_wound("qi", random(jiali/5) + 10);
	victim->receive_damage("qi", jiali/2 + random(10), me);
	result = COMBAT_D->eff_status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
	message_vision("( $N"+result+" )\n", victim);
		if(victim->query("eff_qi") < 0 && victim->query("qi") < 0 && jiali >200 
		&& victim->query("race") == "人类")
		message_vision(HIR"\n$n身子一仰，向後便摔，喷出一口鲜血。\n" NOR, me, victim);



	if( !victim->is_killing(me) ) victim->kill_ob(me);
	me->start_busy(1+random(2));
	if( victim->query("combat_exp") > me->query("combat_exp"))
	me->add("combat_exp", 1);
	add_amount(-1);      

	return 1;
	}
	
	else {
        dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
                message_vision(str, me, victim);

//	message_vision("$n发现不妙，赶紧向後跃开数丈，躲了开去。\n" NOR, me, victim);
		if( !victim->is_killing(me) ) victim->kill_ob(me);
	me->start_busy(random(2));
		if (query_amount() >1) add_amount(-1);
                else destruct(this_object());
	}
	return 1;
}    

int bash_weapon(object me, object victim)
{
        object ob;
        int wap, wdp, jiali;
	jiali = me->query("jiali");

        if( (me->query("neili") > 100)
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)me->query("neili")
                        + (int)me->query_str()
                        + (int)me->query_skill("tanzhi-shentong",1);
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str()
                        + (int)victim->query_skill("parry")/2;
                wap = random(wap);
                if( wap > 2 * wdp 
                && ob->query("weapon_prop/damage") < 90 ) {
			if(jiali < 200) message_vision(HIW "只听见「啪」地一声，$N手中的" + ob->name() + HIW"已经断为两截！\n" NOR, victim );
			else message_vision(HIW"小石子一撞之下，登时火星四溅，石子碎片八方乱射，「啪」地一声，"+ob->name()+HIW"断为两截！\n"NOR, victim);
			
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->name());
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else if( wap > wdp ) {
                
                        if(jiali < 200) message_vision(HIW"$N只觉得手中" + ob->name() + HIW"把持不定，脱手飞出！\n"NOR, victim);
			else message_vision(HIW"小石子一撞之下，炸得粉碎，震得$N虎口疼痛，"+ ob->name() + HIW"摔在地下！\n"NOR, victim);
	
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp / 2 ) {
			message_vision("$N只觉得手中" + ob->name() + "一震，险些脱手！\n",
                                victim);
                } else {
                        message_vision("$N射出的小石子和$n的"+ob->name()+"相击，冒出点点的火星。\n", me, victim);
                }
        }
}

