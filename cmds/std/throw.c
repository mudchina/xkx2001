//Cracked by Roath
// throwing.c
// Ryu

#include <ansi.h>;
inherit F_CLEAN_UP;
inherit F_COMMAND;
inherit F_DBASE;

int do_throw(object me, object ob, object victim);
int fushi_du(object me, object victim, object ob);
private int throw_result(object me, object victim, object ob);

int main(object me, string arg)
{
	string str, what, who, skill; 
	object ob, victim;
	int time;
        time = ((me->query("mud_age"))-(me->query("pktime")));

	seteuid(geteuid(me));

	if( !arg
	||      sscanf(arg, "%s at %s", what, who)!=2)
		return notify_fail("命令格式: throw <物品> at <某人>。\n");

	ob = present(what, me);
	if( !ob ) return notify_fail("你要扔什么？\n");

	if (ob->query("no_drop"))
		return notify_fail("这个东西不能离开你。\n");

	if (!(victim = present(who, environment(me))))
		return notify_fail("这里没有你的目标。\n");

	if (!victim)
		return notify_fail("这里并无此人！\n");

	if (!living(victim))
		return notify_fail("这不是活物！\n");

	if (victim->query("winner"))
		return notify_fail("不可对"+victim->short()+"放肆！\n");

	if (me->is_busy() )
		return notify_fail("你前一个动作还没有做完。\n");

	if (victim == me) 
		return notify_fail("何必多此一举？\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");
		
        if( (time < 3600) && userp(victim))
                return notify_fail("你自觉杀心太重，手软了下来！\n");
                
	if( strsrch(file_name(environment(me)), "/d/xiakedao/") >= 0 && userp(victim))
                return notify_fail("龙岛主有令：不得在岛上使暗器伤人！\n");

	if( ob->query("id") == "corpse" && me->query_skill("chousui-zhang", 1) >= 120 
	&& me->query_skill("poison", 1) >= 120 ) 
		return fushi_du(me, victim, ob);
	
	if ( stringp(skill = ob->query("skill")) && me->query_skill(skill, 1) > 0)
		return ob->throw_ob(me, victim);

	return do_throw(me, ob, victim);
}

int do_throw(object me, object ob, object victim)
{
	object ob2, swap;
	string *limbs, str, dodge_skill, limb, result;
	int ap, dp, damage;

	message_vision("\n$N手一扬，将"+ob->name()+"对准$n掷去。\n", me, victim);

	me->start_busy(1);

	if ( victim->query_skill_mapped("sword")=="dugu-jiujian" 
	&& victim->query_temp("weapon")->query("skill_type")=="sword" 
	&& victim->query("combat_exp") > me->query("combat_exp")/2 ) {
		message_vision(CYN"$N挥剑点向"+ob->name()+"，使出独孤九剑的「破箭式」，将"+ob->name()+"挑射回去。\n"NOR, victim);			
		throw_result(victim, me, ob);
	}
	else {
		throw_result(me, victim, ob);
	}

	return 1;
}

private int throw_result(object me, object victim, object ob)
{
	object ob2;
	string *limbs, str, dodge_skill, limb, result;
	int ap, dp, damage, bili;

	// Modified by Chu: right now people can perform leidong/jingang
	// to gain 3* bili and then throw ding, which will almost guarantee
	// success and also make damage as high as 2K qi.  By removing the
 	// perform effect, this should be fixed.    2/26/99

 	bili = me->query_str();
	if (me->query_temp("apply/strength") > 0)
	    bili -= me->query_temp("apply/strength");

	ap = bili - ob->query_weight()/300;
	dp = victim->query_dex();
	ap *= me->query("combat_exp")/1000;
	dp *= victim->query("combat_exp")/1000;
	ap = random(ap);

	victim->add_temp("offenders/"+me->query("id"), 1);

	if ( ap > dp){
	    limbs = victim->query("limbs");
	    victim->receive_wound("qi", bili, me);
	    victim->receive_damage("qi", ob->query_weight()/100, me);
		
		if(ob->query("armor_type") == "embed" && !victim->query_temp("armor/embed")){
		message_vision(CYN"结果$N一声惨叫，$n"+CYN+"已然插在$N的"+limbs[random(sizeof(limbs))]
			  +"上。\n"NOR, victim, ob);
				 ob2=new(base_name(ob));
				 ob2->set_amount(1);
				 ob2->set("embedded", 1);
				 ob2->move(victim);
				 ob2->do_embed();
				 victim->receive_wound("qi", bili*ob->query("damage"), me);
				 victim->kill_ob(me);
		}
		else {  
		message_vision(CYN"$N猝不及防，$n"+CYN+"砸在了$N的"+limbs[random(sizeof(limbs))]
			  +"上。\n"NOR, victim, ob);
		if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
                        victim->kill_ob(me);
		else{
		victim->fight_ob(me);
		call_out("do_respond", 1, victim, me);
			}
		}
		me->start_busy(random(3));
		if (ob->query_amount() > 0) ob->add_amount(-1);
		else ob->move(environment(me));

	result = COMBAT_D->eff_status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
	message_vision("($N"+result+")\n", victim);
	}

	else if ( ap < dp/7 && ob->query_weight() < 7000 
		&& victim->query("race") == "人类"){
		message_vision(CYN"不料$N眼明手快，身子一侧，把$n"+CYN+"轻轻地接在手里。\n\n"NOR, victim, ob);
		me->start_busy(random(3));
		if (ob->query_amount() > 0){
				 ob->add_amount(-1);
				 ob2=new(base_name(ob));
				 ob2->set_amount(1);
				 ob2->move(victim);
		}
		else ob->move(victim);
		if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
			victim->kill_ob(me);
		else
		call_out("e_mote", 1, victim, me);      
	}

	else {

	dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
		message_vision(str, me, victim);
		
		me->start_busy(random(3));
		if (ob->query_amount() > 0){
				 ob->add_amount(-1);
				 ob2=new(base_name(ob));
				 ob2->set_amount(1);
				 ob2->move(environment(me));
		}
		else ob->move(environment(me));
		if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
                        victim->kill_ob(me);
		else
		call_out("do_respond", 1, victim, me);
	}

	return 1;
}

int fushi_du(object me, object victim, object ob)
{
	int ap, dp, damage;
	string dodge_skill, str, *limbs, limb, result, type = "瘀伤";
	
	if(userp(victim) && userp(me) && (me->query_condition("pker") > 240
           || victim->query("mud_age") < 18000) )
                return notify_fail("你感到一丝内疚，手突然软了下来！\n");

	message_vision(HIB"$N伸出冒着黑气的手掌抓起"+ob->name()+"朝$n掷去。\n"NOR, me, victim);
	
	ap = me->query_skill("strike"); 
	dp = victim->query_skill("dodge");
	ap *= me->query("combat_exp")/1000;
	dp *= victim->query("combat_exp")/1000;

	if (random(ap) > dp){
		limbs = victim->query("limbs");
		limb = limbs[random(sizeof(limbs))];
		damage = ob->query("combat_exp")/500;
		str = COMBAT_D->damage_msg(damage, type);
		str = replace_string( str, "$l", limb); 

		victim->receive_damage("qi", damage, me);
		result = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
		message_vision(str, me, victim);
		message_vision("($N"+result+")\n", victim);

		victim->apply_condition("xx_poison", me->query_skill("poison", 1)
			+victim->query_condition("xx_poison"));
		victim->receive_damage("qi", damage, me);
		victim->start_busy(1+random(3));
		victim->kill_ob(me);
		me->start_busy(random(3));	
	}
	
	else {
	dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		str = SKILL_D(dodge_skill)->query_dodge_msg();
		message_vision(str, me, victim);
		victim->kill_ob(me);
		me->start_busy(2);
	}
	ob->move(environment(me));
	return 1;
}

void e_mote(object victim, object me)
{
	int i;
	string *emote = ({
	"sneer", "callname", "consider", "killair", 
	"nonsense", "walkby" });

	if (!me || environment(me) != environment(victim))
	return;

	i = random(sizeof(emote));

	EMOTE_D->do_emote(victim, emote[i], me->query("id"));
}
	
void do_respond(object victim, object me)
{
	string att; 

	if (!me || !victim || environment(me) != environment(victim))
	return;

	att = victim->query("attitude");

	if (victim->query("shen") < 0)
		return victim->kill_ob(me);

	if (att == "friendly" && victim->query("race") == "人类")
		return e_mote(victim, me);
	
	if (att == "heroism" || att == "aggressive")
		return victim->kill_ob(me);     

	if (att == "peaceful" && random(5)== 1) 
		return victim->kill_ob(me);

	else if(victim->query("race") == "人类")
	EMOTE_D->do_emote(victim, "brag", me->query("id"));

	return victim->fight_ob(me);    
}
