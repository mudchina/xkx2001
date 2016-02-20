//Cracked by Roath
// /kungfu/skill/chousui-zhang/sandu  pfm 散毒
// Summer, 12/28/96.
// modified by sdong 7/16/1999. Let ppl can sandu on NPC with exp 1/3 higher than self
// modified by wsky, let ppl can sandu, san some poison out to npc or player if they are
// poisoned. and after sandu will be able to maxsuck for a certain time. desigened this
// so there is no wangding conflit btw xx ppl  4/3/00

//wzfeng cut sandu npc add exp 2000 11
                
#include <ansi.h>
//#include <string.h>

inherit F_SSERVER;

#include "/kungfu/skill/chousui-zhang/poison_list.h" //blush

int perform(object me, object target)
{
        object room, mengzhu;
        
        string poi_name, poison, poi_color, col_ansi;
        int i, poi_lvl,poi_amount, cure_amount, cure, hgdf;
	mapping myfam;
	
        if( !target ) target = offensive_target(me);
	
	if( strsrch(base_name(environment(me)),"/d/bwdh")==0)
		return notify_fail("比武大会中不可以散毒。\n");

	//message_vision(base_name(environment(me)),me);

	if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("你不在战斗中。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if(!(room=find_object("/d/taishan/fengchan")))
                room=load_object("/d/taishan/fengchan");

        if( target->query("id") == room->query("winner") )
                return notify_fail("大胆！竟敢对盟主散毒，想与全武林为敌吗？\n");

        if( (int)me->query_skill("chousui-zhang", 1) < 30 )
                return notify_fail("你的抽髓掌修为不够。\n");

        if( (int)me->query_skill("poison", 1) < 50 )
                return notify_fail("你的基本毒技修为不够。\n");

        if ( me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("你没有运化功大法！\n");

        if( me->query("neili") <= 100 )
                return notify_fail("你的内力不够！\n");

        if( target->query_condition("poisoned") > 0 || ( me->query("last_sandu") == target->query("id") && userp(target) ) )
                return notify_fail("此人已身中剧毒或中过毒不久，在此人身上散毒会使你反受其害。\n");


        for( i=0; i < sizeof(poison_list); i++ )
             if( me->query_condition(poison_list[i]["poison"]) > 0 )
             {
                poison = poison_list[i]["poison"];
                poi_name = poison_list[i]["name"];
                poi_color = poison_list[i]["color"];
                col_ansi = poison_list[i]["ansi"];
                poi_lvl = poison_list[i]["lvl"];
                break;
              }

        hgdf = (int)me->query_skill("huagong-dafa",1);  

        poi_lvl = (int)me->query_condition(poison, 1);


        message_vision(MAG "$N把左掌缓缓抬起，掌心颜色由青变紫，冒出一缕缕寒气，随着大吼一声，手掌向$n猛拍过去。\n\n" NOR, me,target);
        me->add("neili", -150);

        if( !userp(target) ) target->kill_ob(me);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*5/12){
    
	      	  if(((int)target->query("combat_exp")>me->query("combat_exp")/2 && userp(target)) ||
                    ((int)target->query("combat_exp")>me->query("combat_exp")/3*4 && !userp(target))){
        	  	if( me->query_skill("poison", 1) < target->query_skill("poison", 1) * 2){
        	  		tell_object(me, BLU "你一掌拍在" +target->query("name") +"胸口，不料此人体内聚毒不低，你不能把毒散出，反受其害。\n"NOR);
        	  		tell_object(target, BLU "你只觉一股寒气袭面，闷哼一声，胸口中掌。\n" NOR);
                  		me->add("max_neili", - 1);
                 		me->apply_condition("xx_poison", 50+me->query_condition("xx_poison"));
                  		target->add("qi", - me->query_skill("chousui-zhang"));
                  		target->apply_condition("xx_poison", 10+target->query_condition("xx_poison"));
                  		return 1;
       			} else {
        	  	        tell_object(me, BLU "你一掌拍在" +target->query("name") +"胸口，待其运内力抵抗，顺势把周身毒气尽数逼进" +target->query("name") +"体内。\n"NOR);
        	   		tell_object(target, BLU "你只觉一股寒气袭面，感紧运内力抵抗，不料" +me->name() +"带剧毒的一掌一下拍在你胸口上。\n"NOR);
                   		          
	                        me->add("max_neili", - 1 - (int)me->query_skill("huagong-dafa", 1)/15);
                                if (me->query_skill("poison", 1) < 101)
                   		me->set("body_poison",me->query_skill("poison", 1)/10+1);
                   		if (me->query_skill("poison", 1) > 100)
                   		me->set("body_poison", me->query_skill("poison", 1));

                   		target->add("qi",-(random((int)me->query_skill("chousui-zhang"))));
                   		target->receive_wound("jing", (int)me->query_skill("chousui-zhang"));
                   		target->apply_condition("xx_poison", me->query_skill("poison", 1)*2);
                   		target->apply_condition("poisoned", me->query_skill("poison", 1)*3);

		                if( strsrch(base_name(environment(me)),"/d/bwdh")!=0){
                 	        	if (userp(target)){
                         	    	     me->add("combat_exp", me->query_skill("poison", 1) * 5);
                         	    	     me->add_skill("poison",1);
                         	    	     target->apply_condition("xx_poison",1000);
                         	    	}
                        		//else me->add("combat_exp", me->query_skill("poison", 1) * 6/4);
                   		}

                   		if(me->query("maxsuck")<400) me->set("maxsuck",400);
                 		me->set("last_sandu", target->query("id"));
        			log_file("POISON", sprintf("%s(%s) 散毒 on %s.\n", me->query("name"), getuid(me), target->query("name")));
		        	return 1;
               		}
       		} 
              
	        tell_object(me, BLU "你一掌拍在" +target->query("name") +"胸口，不料" +target->query("name") +"内力太弱，你反不能把毒气逼出去，功力受损。\n"NOR);
        	tell_object(target, BLU "你只觉一股寒气袭面，闷哼一声，胸口中掌。\n" NOR);
                target->add("qi",-(random((int)me->query_skill("chousui-zhang"))));
                target->receive_wound("jing", (int)me->query_skill("chousui-zhang"));
                target->apply_condition("xx_poison", 5 + target->query_condition("xx_poison"));
                target->start_busy(1+random(3));

		myfam=me->query("family");
		
		if (poi_lvl!=0 && myfam["family_name"] == "星宿派") {
                	tell_object(me, HIG "你跟着猛摧内劲，将体内所中的"+col_ansi+poi_name+HIG"逼入对手体内。\n"NOR);
                   	tell_object(target, HIR "你跟着胸口一疼，发现中的不只是星宿毒。\n"NOR);                     
	                poi_amount = (int)me->query_condition(poison, 1); // how deep I have got poisoned.
                        me->apply_condition(poison, 0);
                        target->apply_condition(poison, poi_amount);     
		}
 
       } else message_vision(HIY "$p赶紧向後跃开数丈，躲开$P的攻击。\n" NOR, me, target);
    


        me->start_busy(1+random(5));
        return 1;
		}