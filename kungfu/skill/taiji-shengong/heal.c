//Cracked by Roath
// heal.c 太极神功
// Modified by xQin 11/98

#include <ansi.h>

int exert(object me, object target)
{
	string name, *sname;
	object deadman, *list;
	mapping skill_status, learned_status;
	int i, j, tao_level, tjsg_level, new_exp, neili_drop, sneili_drop, skill_amount;

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

/*
 * the following code is making 鹤嘴劲点龙跃窍 for 白虎夺命丹
 * still under construction. xQin.
 */
	if( !target || target == me ) return 0;
	
	if (target->id("corpse")) 
	{
	if (!wizardp(me))
		return notify_fail("你无法将疗伤运用於起死回生。\n");

        if ((tao_level = me->query_skill("taoism", 1)) < 120 )
                return notify_fail("你的道学心法修为还不够！\n");
                        
        if ((tjsg_level = me->query_skill("taiji-shengong", 1)) < 120 )
                return notify_fail("你的太极神功修为还不够！\n");
                        
        if ( target->id("corpse") && !target->is_character() ) 
                return notify_fail("你要救的人已经死太久了！\n");
                
        neili_drop = 150 - tjsg_level/2; 
        sneili_drop = 300 - tjsg_level;
        if (neili_drop <= 20) neili_drop = 20;

        name = target->query("victim_name"); 
                
        list = users();
        for ( i = 0; i < sizeof(list); i++)
        if ( name == list[i]->name(1) ) break;
        
        if (i == sizeof(list)) 
                return notify_fail(name+"的鬼魂不在。\n");
                        
        deadman = list[i];      
        if ( !deadman->is_ghost() )
                return notify_fail(name+"早已生死轮，何必多此一举？\n");
                        
        message_vision(
                HIW "$N双手食指和拇指虚拿，成“鹤嘴劲”势，\n"
                "以食指指尖点在"+name+"耳尖上三分处的“龙跃窍”，运起内力，微微摆动……\n\n"NOR, me);

        if ( me->query("neili") < 1000 || random(tao_level+tjsg_level) < 24 )     
        {
                me->set("neili", 0);
                me->add("max_neili", -10); 
                        
                message_vision( HIY"$N突然停顿下来，显然内力受到极大损伤！\n"NOR, me);
                return notify_fail( HIY"可惜你内力不济，无法坚持下去了！\n"NOR );
        } 
                
        me->add("neili", -1000); 
        me->add("max_neili", - neili_drop ); 
        me->receive_damage("qi", 3*neili_drop, "内力输出过度而死了。"); 
        me->receive_wound("qi", 2*neili_drop, "内力输出过度而死了。"); 

        message_vision( HIY"直摆到二十下，$N双手捏成剑诀，掌心向下，两手双取"+ name +"“颊车穴”。\n"
		"$N阴手点过，立即掌心向上，翻成阳手，一阴一阳，交互变换。\n"
		+ "翻到第十二次时，" + name +"终於张开了口，缓缓将丹药吞入喉中。"NOR, me);

        tell_object(deadman, HIY "一道天罡阳气击中你，痛得你几乎晕死过去！\n" NOR);

        message("vision",  
		HIY"一道天罡阳气划过，"+name+"消失了！\n"NOR, environment(deadman), deadman );

	deadman->reincarnate();
	learned_status = deadman->query_learned();

	if ( mapp(skill_status = deadman->query_skills()) )
	{
		sname = keys(skill_status);
		for(i=0; i<sizeof(skill_status); i++) {
			skill_amount = (skill_status[sname[i]]+1) * (skill_status[sname[i]]+1) / 2;

			if( !mapp(learned_status) ) learned_status = ([ sname[i] : skill_amount ]);
			else {
				if( learned_status[sname[i]]  < skill_amount )
					learned_status[sname[i]] += skill_amount;
				else {
					learned_status[sname[i]] -= skill_amount;                                                                    - (skill_status[sname[i]]) * (skill_status[sname[i]]);
					deadman->set_skill(sname[i], skill_status[sname[i]]+1);
				}
			}
		}
	}


	new_exp = (int)deadman->query("combat_exp") / 99;
	new_exp = new_exp > 5000 ? 5000 : new_exp;
	deadman->add("combat_exp", new_exp);
	deadman->set("qi",1); 
	deadman->set("eff_qi",1); 
	deadman->set("jing",1); 
	deadman->set("eff_jing",1); 
	deadman->set("jingli",1); 

	deadman->move(environment(me));
	destruct(target);
	deadman->unconcious();

        return 1;       
        } else

	if ((!target) || (target == me))
	{

	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功修为还不够！\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	write( HIW "你盘膝坐下调息，只觉丹田中暖烘烘地、活泼泼地，真气流动，顷刻间便遍于四肢百骸。\n" NOR);
	message("vision",
		HIW"只见" + me->name() + "闭目坐下，片刻之间，头顶升出丝丝白气。猛地里口一张，吐出几口淤血。\n" NOR,
		environment(me), me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);

	return 1;
        }
        
	if ((int)me->query_skill("taiji-shengong", 1) < 50)
		return notify_fail("你的太极神功修为还不够。\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

        if( !living(target) )
                return notify_fail("此人已然昏死，无从救起！\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"已经受伤过重，经受不起你的真气震荡！\n");

	message_vision(
		HIC "$N当下吸一口气，收摄心神，一股暖气从丹田中升上，劲贯双臂，按住$n的“灵台穴”。\n"
		HIW "过了一会，$P头顶笼罩氤氲白气，显是出尽了全力，汗气上蒸。\n"
		HIC "忽听得“波”的一声，一缕黑血从$p伤口中激射而出，黑血渐渐转红。\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -150);
	me->set("jiali", 0);

	return 1;

}
