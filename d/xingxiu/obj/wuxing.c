//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int throw_ob(object me, object victim);
void create()
{
   set_name(HIW"无形散"NOR, ({"wuxing san", "san", "wuxing"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "包");
      set("value", 10);
      set("skill", "feixing-shu");
   }
   setup();
}

int throw_ob(object me, object victim)
{
   int skill, skill2, thr, dod, poi, my_neili, u_neili, myexp, urexp, par;
   mapping myfam, vfam;
   
   
   if ( (!( myfam= me->query("family")) || myfam["family_name"] != "星宿派"))
                  return notify_fail("只有星宿弟子利用本门秘传内功方能使用无形散。\n"); 

   if (me->is_fighting())
   	return notify_fail("你正忙着打架呢，腾不出手来！\n");	

   if( me->query("neili") <= 2500 ){
        write("你的内力不够摧迫无形散毒！\n");
        return 1;
   }

   if (me->query_skill("poison", 1) < 120){
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
   
   message_vision("$N微微一笑，神出小指向$n轻轻一弹，$n觉得眼前一花，似乎有一层白雾向自己飘来。\n"NOR, me, victim);

   if (me->query_skill("poison", 1) < victim->query_skill("poison", 1) + 30){
           victim->apply_condition("insect_poison", 100);
           return 1;
   }

   thr = me->query_skill("feixing-shu", 1);
   poi = me->query_skill("poison",1);
   dod = (int)victim->query_skill("force",1);
      
   my_neili = me->query("neili");
   u_neili = (int)victim->query("neili");
   
   skill = thr + poi + my_neili;
   skill2 = dod + u_neili;
   skill += me->query("combat_exp")/1000;
   skill2 += victim->query("combat_exp")/1000;
   me->add("neili", -150);

   myexp=me->query("combat_exp");
   urexp=victim->query("combat_exp");

   if ( skill > skill2){

        if (urexp>=myexp/2) 
                me->improve_skill("feixing-shu", 1000);
        
        /*
        if(userp(victim) && urexp>=myexp && strsrch(base_name(environment(me)),"/d/bwdh")!=0){
                me->add("combat_exp", 1000);
                me->add_skill("feixing-shu",1);
        }*/
        
        
        if(userp(victim)) me->apply_condition("pker", 250);
                
        //if( !victim->is_killing(me) ) victim->kill_ob(me);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        victim->apply_condition("sanpoison",me->query_skill("poison",1));      
        if( !victim->is_killing(me) ) victim->kill_ob(me);
        destruct(this_object());
      
  	me->start_busy(2);
  	victim->start_busy(2);
        
        return 1;
   } else {
        message_vision(HIR"$n袍袖一拂，一股内劲发出，将那无形散尽数朝$N拂将回去。\n" NOR, me, victim);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        victim->apply_condition("sanpoison",me->query_skill("poison",1));      
        if( !victim->is_killing(me) ) victim->kill_ob(me);
  }
  
  me->start_busy(2);
  victim->start_busy(2);
  
  destruct(this_object());
  return 1;
}    
