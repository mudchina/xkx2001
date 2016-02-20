//Cracked by Roath
// jiujian_qi_damage.c 独孤九剑破气式伤势
// qfy Nov 11, 96.

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int t, level, hm_stat, lj_stat, status, flag;
	string skill;

	t = me->query_condition("jiujian_qi_damage");

	if ( me->query_temp("dugu/force") ) {
	   skill = me->query_skill_mapped("force");

	   if ( skill != 0 ) {
		message_vision("$N突然觉得一阵血气翻涌，丝毫用不上勉强提聚的"+to_chinese(skill)+"！\n", me);
		me->map_skill("force");
	   }
	}

	if ( me->query_temp("dugu/reverse") || me->query_temp("dugu/hamapowerup") ) {
	   if ( me->query_temp("dugu/force") && skill == "" ) {
                level = me->query_skill("force") + me->query_skill("hamagong", 1);
           }
           else {
                level = me->query_skill("force");
           }

	   hm_stat = me->query_temp("dugu/reverse") + me->query_temp("dugu/hamapowerup");

	   if ( !me->query_temp("reverse") ) {
	  	me->add_temp("apply/dodge", level/2);
		me->delete_temp("dugu/reverse");
		status++;
	   }

	   if ( !me->query_temp("powerup") ) {
		me->add_temp("apply/attack", level/4);
                me->add("eff_qi", level*5/2);
                me->add("qi", level);
		me->delete_temp("dugu/hamapowerup");
		status++;
           }
	}
	else if ( me->query_temp("dugu/powerup") && !me->query_temp("powerup") ) {
	   if ( me->query_temp("dugu/force") && skill == "" ) {
                level = me->query_skill("force") + me->query_skill("huntian-qigong", 1);
           }
           else {
                level = me->query_skill("force");
           }

	   me->add_temp("apply/dodge", level/3);
           me->add_temp("apply/attack", level/3);
	   me->delete_temp("dugu/powerup");
	   status++;
	}
	else if ( me->query_temp("dugu/shield") && !me->query_temp("shielded") ) {
	   if ( me->query_temp("dugu/force") && skill == "" ) {
                level = me->query_skill("force") + me->query_skill("longxiang-banruo", 1);
           }
           else {
                level = me->query_skill("force");
           }

           me->add_temp("apply/armor", level/2);
           me->add_temp("apply/defense", level/2);
           me->delete_temp("dugu/shield");
	   status++;
	}
	else if ( me->query_temp("dugu/wuzhuan") && !me->query_temp("wuzhuan") ) {
	   level = me->query_skill("qimen-dunjia",1);
	   me->add_temp("apply/dodge", level/5);
           me->add_temp("apply/dexerity", level/10);
           me->add_temp("apply/speed", level/30);
	   me->delete_temp("dugu/wuzhuan");
	   status++;	
	}
	else if ( me->query_temp("dugu/tiandi") || me->query_temp("dugu/zhixin")
	|| me->query_temp("dugu/fengyun") || me->query_temp("dugu/daxiao") ) {
	   level = me->query_skill("linji-zhuang", 1);
	
	   if ( me->query_temp("dugu/zhixin") ) lj_stat++;
	   if ( me->query_temp("dugu/daxiao") ) lj_stat++;
	   lj_stat += me->query_temp("dugu/tiandi") + me->query_temp("dugu/fengyun");

	   if ( !me->query_temp("linji/tiandi") ) {
		me->add("max_qi", level);
                me->add("max_jing", level);
                me->add("max_jingli", level);
                me->receive_curing("qi", level);
                me->receive_curing("jing", level);
                me->receive_heal("jingli", level);
	 	me->delete_temp("dugu/tiandi");
		status++;
	   }

	   if ( !me->query_temp("linji/zhixin") ) {
                me->add_temp("apply/intelligence", me->query_temp("dugu/zhixin"));
                me->delete_temp("dugu/zhixin");
		status++;
	   }

	   if ( !me->query_temp("linji/fengyun")) {
                me->add_temp("apply/dexerity", level);
                me->add_temp("apply/attack", -level);
                me->delete_temp("dugu/fengyun");
		status++;
	   }

	   if ( !me->query_temp("linji/daxiao") ) {
		me->add("max_qi", me->query_temp("dugu/daxiao"));
        	me->add("max_jing", -me->query_temp("dugu/daxiao"));
        	me->receive_curing("qi", me->query_temp("dugu/daxiao"));
        	if ( (int)me->query("eff_jing") > (int)me->query("max_jing") ) 
                   me->set("eff_jing", (int)me->query("max_jing") );
		me->delete_temp("dugu/daxiao");
		status++;
	   }
	}

	if ( hm_stat > status ) flag = 1;
	else if ( lj_stat > status ) flag = 1;
	else if ( status == 0 ) flag = 1;
	else flag = 0;

	if ( t ) {
	   me->apply_condition("jiujian_qi_damage", duration - 1);
	}
	else if ( flag && !me->query_temp("dugu") ) {
	   me->apply_condition("jiujian_qi_damage", 0 );
	}
	else if ( flag ) {
	   if ( me->query_temp("dugu/force") ) me->delete_temp("dugu/force");
	   me->apply_condition("jiujian_qi_damage", 1 );
	}

   return CND_CONTINUE;
}
