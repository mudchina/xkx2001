//Cracked by Roath
private int qi_damage_300(object me, object target)
{
	string msg1, skill = target->query_skill_mapped("force");
	int time;

	if ( skill == "" ) return 1;

	target->map_skill("force");
	target->set_temp("dugu/force", 1);
	time = (int)me->query_skill("sword") / 30;
	msg1 = RED "$p只觉混身如遭电击，真气劲力紊乱难控，已然不能施展"+to_chinese(skill)+"！\n" NOR;
	target->apply_condition("jiujian_qi_damage", time);
	message_vision(msg1, me, target);

	return 1;
}

private int qi_damage_220(object me, object target)
{
	int level, level1;
	string msg1, skill = target->query_skill_mapped("force");

	switch ( skill ) {
	   case "hunyuan-yiqi":
		if ( target->query_temp("jinzhongzhao") ) {
		   target->delete_temp("jinzhongzhao");
        	   msg1 = RED "$p丹田被刺，脸色突转苍白，金刚不坏体神通已然瓦解！\n" NOR;
		}
		
		break;

	   case "hamagong":
		level = target->query_skill("force");
		msg1 = RED "$p被刺中天庭，";

		if ( target->query_temp("reverse") ) {
		   target->add_temp("apply/dodge", -level/2);
		   target->set_temp("dugu/reverse", 1);
		   msg1 += "$p内力散乱，已不能再施展经脉倒转，只好翻身直立起来！\n";
		}

		if ( target->query_temp("powerup") ) {
		   target->add_temp("apply/attack", -level/4);
		   target->add("eff_qi", -level*5/2);
		   target->add("qi", -level);
		   target->set_temp("dugu/hamapowerup", 1);
		   if ( target->query_temp("reverse") ) msg1 += "同时";

		   msg1 += "$p真气无法凝聚，双臂发麻，再也使不出蛤蟆功来！\n" ;
		}

		msg1 += NOR;

		break;

	   case "huntian-qigong":
		level = target->query_skill("force");
                msg1 = RED "$p被刺中气海，";

		if ( target->query_temp("powerup") ) {
		   target->add_temp("apply/dodge", -level/3);
		   target->add_temp("apply/attack", -level/3);
                   target->set_temp("dugu/powerup", 1);
                   msg1 += "$p胸口真力四窜，难以控制，无法再运使混天气功加力！\n"; 
                }

		if ( target->query_temp("shengang") ) {
		   target->set_temp("shengang", level/8);

		   if ( target->query_temp("powerup") ) msg1 += "同时";
		   msg1 += "$p内力突感滞泄，力不从心，唯有开始收束起混天神罡！\n";
		}

		msg1 += NOR;

		break;

	   case "longxiang-banruo":
		level = target->query_skill("force");

		if ( target->query_temp("shielded") ) {
                   target->add_temp("apply/armor", -level/2);
                   target->add_temp("apply/defense", -level/2);
                   target->set_temp("dugu/shield", 1);
		   msg1 = RED "$p百汇被刺，全身真气突泄，护体神功一散，鼓涨的衣衫也平覆下来！\n" NOR;
                }

		break;

	   case "bitao-xuangong":
		level = target->query_skill("qimen-dunjia",1);
		
		if ( target->query_temp("wuzhuan") ) {
		   target->add_temp("apply/dodge", -level/5);
		   target->add_temp("apply/dexerity", -level/10);
		   target->add_temp("apply/speed", -level/30);
		   target->set_temp("dugu/wuzhuan", 1);
		   msg1 = RED "$p膻中被刺，真气运转呆滞，脚步颟憨，奇门五转顿然破去！\n" NOR;
		}

		break;

	   case "linji-zhuang":
		level = target->query_skill("linji-zhuang", 1);
		msg1 = RED "$p被刺中命门，" ;

		if ( target->query_temp("linji/tiandi") ) {
		   target->add("max_qi", -level);
		   target->add("max_jing", -level);
		   target->add("max_jingli", -level);
		   target->receive_damage("qi", level, "强运天地庄逆抗破气式，体力透支过度死了");
		   target->receive_damage("jing", level, "强运天地庄逆抗破气式，精力透支过度死了");
		   target->receive_damage("jingli", level, "强运天地庄逆抗破气式，精力透支过度死了");
		   if ((int)target->query("eff_qi") > (int)target->query("max_qi") )
			target->set("eff_qi", (int)target->query("max_qi") );
		   if ((int)target->query("eff_jing") > (int)target->query("max_jing") )
			target->set("eff_jing", (int)target->query("max_jing") );
		   target->set_temp("dugu/tiandi", 1);

		   msg1 += "$p只觉混身血气蒸腾，难以驾驭，无法再运用天地庄！\n" ;
		}

		if ( target->query_temp("linji/zhixin") ) {
		   level1 = target->query_int() - target->query("int") - target->query_skill("literate", 1);
		   target->add_temp("apply/intelligence", -level1);
		   target->set_temp("dugu/zhixin", level1);
		   msg1 += "$p心神难定，思维杂乱无章，之心庄亦无法运作！\n" ;
		}
	
		if ( target->query_temp("linji/fengyun") ) {
		   target->add_temp("apply/dexerity", -level);
		   target->add_temp("apply/attack", level);
		   target->set_temp("dugu/fengyun", 1);
		   msg1 += "同时$p身法逐渐缓慢下来，可见风云庄已被破解！\n" ;

		}

		if ( target->query_temp("linji/daxiao") ) {
		   level1 = target->query("max_qi") - target->query("max_jing");
		   if ( level1 < 0 ) level1 = 0;
		   level1 = level1 * level/400 ;
		   target->add("max_qi", -level1);
		   target->add("max_jing", level1);
		   target->receive_curing("jing", level1);
		   if ( (int)target->query("eff_qi") > (int)target->query("max_qi") ) 
                	target->set("eff_qi", (int)target->query("max_qi") );
		   target->set_temp("dugu/daxiao", level1);
		   msg1 += "最后$p体现疲态，似乎力气不继，大小庄也不能施展了！\n" ;
		}

		msg1 += NOR;

		break;

	   default:
	  	msg1 = "";
	
		break; 
	}

	message_vision(msg1, me, target);
	if ( target->query_temp("dugu") && !target->query_condition("jiujian_qi_damage") ) { 
		target->apply_condition("jiujian_qi_damage", 1);
	}

	return 1;
}

private int qi_damage_150(object me, object target)
{
	string msg1;

	msg1 = RED "结果$p退避不及，中剑因而导至内力受损。\n" NOR;

	if ( random(2) == 1 ) {
	   target->add("max_neili", -(random(4)+2));
	}
	else {
	   target->add("neili",-(random((int)me->query_skill("dugu-jiujian"))*2));
	}

	message_vision(msg1, me, target);

	return 1;
}
