//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int throw_ob(object me, object victim);
void create()
{
   set_name(BLU"逍遥三笑散"NOR, ({"sanxiao san", "san", "sanxiao", "zhuihun"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "包");
      set("value", 10);
      set("skill", "feixing-shu");
   }
   setup();
}

void init()
{
        object me = this_player();
        add_action("throw_ob2","tan"); 
}


int throw_ob(object me, object victim)
{
   int skill, skill2, thr, dod, poi, my_neili, u_neili, myexp, urexp, par;
   mapping myfam, vfam;
   
   
   if ( (!( myfam= me->query("family")) || myfam["family_name"] != "星宿派"))
                  return notify_fail("只有星宿弟子利用本门秘传内功方能使用三笑散。\n"); 

   if (me->is_fighting())
   	return notify_fail("你正忙着打架呢，腾不出手来！\n");	

   if( me->query("neili") <= 5000 ){
        write("你的内力不够摧迫逍遥三笑散毒！\n");
        return 1;
   }

   if (me->query_skill("poison", 1) < 100){
        write("当心毒死你自己！\n");
        return 1;
   }

   if( environment(me)->query("no_fight") ) return notify_fail("不行!\n");
	
   if( me->is_busy() ) return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");
	

   if (victim->query_condition("sxs_poison")){  
        write("此人已中了三笑追魂散，命不久矣！\n");
        return 1;
   }

   if (me->query_condition("pker") > 240 && userp(victim)){
        write("你感到一丝内疚，手突然软了下来。\n");
        return 1;
   }
   
   tell_object(me, BLU"你轻轻一弹指，将逍遥三笑散往"+victim->query("name")+"身上弹去。\n"NOR);
   	

   if (me->query_skill("poison", 1) < 100){
           this_object()->set_temp("used", 1);
           me->apply_condition("sxs_poison",4); 
           tell_object(me, "你毒炼得火侯不够，毒着自己了！\n");
           destruct(this_object());
        return 1;
   }

   if (me->query_skill("poison", 1) < victim->query_skill("poison", 1) + 30){
           victim->apply_condition("insect_poison", 100);
           return 1;
   }

   thr = me->query_skill("feixing-shu", 1);
   poi = me->query_skill("poison",1);
   dod = (int)victim->query_skill("force",1);
   par = (int)victim->query_skill("parry",1);
   
   my_neili = me->query("neili")/3*2;
   u_neili = (int)victim->query("neili")/3*2;
   
   skill = thr + poi + my_neili;
   skill2 = dod + par + u_neili;
   skill += me->query("combat_exp")/10000;
   skill2 += victim->query("combat_exp")/10000;
   me->add("neili", -150);

   myexp=me->query("combat_exp");
   urexp=victim->query("combat_exp"); 

   if (wizardp(me))
   	printf("my skill=%d  ur skill=%d\n",skill, skill2);

   if ( skill > skill2+random(skill2/2) ){

        if (urexp>=myexp && strsrch(base_name(environment(me)),"/d/bwdh")!=0) 
                me->improve_skill("feixing-shu", 1000);
        
        if(userp(victim) && urexp>=myexp && strsrch(base_name(environment(me)),"/d/bwdh")!=0){
                me->add("combat_exp", 1000);
                me->add_skill("feixing-shu",1);
        }
        
        if(userp(victim)) me->apply_condition("pker", 250);
                
        //if( !victim->is_killing(me) ) victim->kill_ob(me);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        victim->apply_condition("sxs_poison",4);      
        destruct(this_object());
        return 1;
   } else if (skill>skill2){
   	message_vision(HIY"$n突然觉得一阵冷风袭来，忙向后一跃，闪了开去。\n"NOR, me, victim);
   	this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        if( !victim->is_killing(me) ) victim->kill_ob(me);
        me->start_busy(random(3)+1);
   } else {
        message_vision(HIR"$n袍袖一拂，一股内劲发出，将那三笑散尽数朝$N拂将回去。\n" NOR, me, victim);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        me->apply_condition("sxs_poison",4);
        me->start_busy(random(3)+1);
        if( !victim->is_killing(me) ) victim->kill_ob(me);
  }
  
  destruct(this_object());
  return 1;
}    
