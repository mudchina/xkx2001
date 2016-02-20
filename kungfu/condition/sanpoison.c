//Cracked by Roath
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string* xuedao = ({
        "胸口膻中",
        "头顶百会",
        "面庞迎香",
        "足底涌泉",
        "手心劳宫",
        "两鬓太阳",
});


int update_condition(object me, int duration)
{
	int neili, poison;

	if( !living(me) ) {
     		message_vision(me->name() + "身体一阵颤抖，痛苦地哼了一声。\n", environment(me), me);
   	}
   	else {
   		if (me->query("family/family_name")=="星宿派"
                    && me->query_skill("huagong-dafa")) {
                    tell_object(me, HIW"你突然觉得一阵寒气袭来，忙运用化功大法抵御。\n"NOR);
		    message("vision", me->name() + "的身子突然晃了两晃，脸上泛起一阵惨白之色。\n",environment(me), me);	                    		   	
   		    
   		    poison=me->query_skill("poison",1)/2;		
   
   	
   		} else {	 		
      		    poison=10;
      		    tell_object(me, HIW"你突然间觉得"+xuedao[random(sizeof(xuedao))]+"一阵刺痛，眼前一阵黑，一阵明，胸中一阵郁闷。\n" NOR );
      		    message("vision", me->name() + "的身子突然晃了两晃，脸上泛起一阵惨白之色。\n",environment(me), me);	                    		   	
   	        }
   	}
   	
   	neili=me->query("neili")-(me->query_skill("force",1));
   	me->start_busy(random(1)+1);
   	
   	if(neili<me->query_skill("force",1)*4) {
   	     
   	     tell_object(me, HIR"你的内力已经渐渐控制不住体内的毒素，一阵刺痛袭击来，着实难当。\n" NOR );
   	     
   	     me->set("neili",0);		
   	     me->receive_damage("jing", duration*2, "无形散毒攻心死了");
      	     me->receive_wound("qi", duration*3/2, "无形散毒攻心死了");
   		
   	} else me->set("neili",neili);  	
   	
      	me->apply_condition("sanpoison", duration - random(5));
	
	if(me->query("qi")<=0){
		me->set_temp("last_damage_from", "无形散毒攻心死了");
	        me->delete("env/immortal");
		me->die();
	}
	
	if (me->query("id")=="wsky") printf("condition left: %d\n", me->query_contidion("sanpoison",1));
	        
   	if( duration == 1) me->delete("poisoner");

   	if( duration < 1 ) {
   		message_vision(HIG"$N运了运气，发现体内的寒毒已经荡然无存。"NOR,me);	
   		return 0;
   	}
   	
   return CND_CONTINUE;
}
