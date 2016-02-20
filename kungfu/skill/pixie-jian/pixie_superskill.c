//Cracked by Roath
//pixie_superskill.c
//wzfeng@xkx 99 9

#include <ansi.h>
#include <combat.h>
int do_prepare_superskill(string superskill_name,object me,object enemy,int ap,int dp);

void remove_poshensha(object target,int dodge_skill);
int set_perform(object me,string use)
{
	string p1,p2,p3,p4;
	
	if(me->query_temp("pixie_use/1"))
		p1=me->query_temp("pixie_use/1");
	else
		p1="none";
	if(me->query_temp("pixie_use/2"))
		p2=me->query_temp("pixie_use/2");
	else
		p2="none";
	if(me->query_temp("pixie_use/3"))
		p3=me->query_temp("pixie_use/3");
	else
		p3="none";
	if(me->query_temp("pixie_use/4"))
		p4=me->query_temp("pixie_use/4");
	else
		p4="none";
	me->set_temp("pixie_use/1",p2);
	me->set_temp("pixie_use/2",p3);
	me->set_temp("pixie_use/3",p4);
	me->set_temp("pixie_use/4",use);
	return 1;
}

void checking_pixieflg(object me,object enemy)
{
	string perform_name;
	perform_name=me->query_temp("pixie_use/4");

	me->set_temp("pixie_noop",1);
	if( wizardp(me) &&me->query("env/pixie_test"))
	{
		printf(HIC"上一个必杀技名称是%s\t",me->query_temp("pixie_use/3"));
		printf(HIC"当前使用的必杀技是%s\n"NOR,me->query_temp("pixie_use/4"));
	}
		if(me->query_skill_mapped("sword") != "pixie-jian"
		||me->query_skill_mapped("dodge") != "pixie-jian"
			||me->query_skill_mapped("parry") != "pixie-jian"
			||!objectp(me->query_temp("weapon")))
	{
		if( wizardp(me) &&me->query("env/pixie_test"))
		printf(HIC"change skills, del all\n");
		   enemy->delete_temp("pixie_times");
		   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");
		   remove_call_out("checking_pixieflg");

       return ;

	}



	if( !living(me) || me->is_ghost()|| !me->is_fighting())
        {
		if( wizardp(me) &&me->query("env/pixie_test"))
		printf(HIC"if( !living(me) || me->is_ghost()|| !me->is_fighting())\n");
			   enemy->delete_temp("pixie_times");
			   me->delete_temp("pixie_noop");
   			   me->delete_temp("pixie_use");
			   me->delete_temp("pixie_superskill");
			   me->delete_temp("pixie_performtime");
			   remove_call_out("checking_pixieflg");
			   return;
 
        }

   	       if( !living(enemy) || enemy->is_ghost()
			   || !enemy->is_fighting())
        {
			   	if( wizardp(me) &&me->query("env/pixie_test"))
			   printf(HIC"if( !living(enemy) || enemy->is_ghost()|| !enemy->is_fighting())\n");
			   enemy->delete_temp("pixie_times");
			   me->delete_temp("pixie_noop");
   			   me->delete_temp("pixie_use");
			   me->delete_temp("pixie_superskill");
			   me->delete_temp("pixie_performtime");
			   remove_call_out("checking_pixieflg");
			   return;
 
        }

		   /////////////////////////////////////////////////////////////////////
	if(me->query_temp("pixie_performtime")>0)
	{
		
	me->add_temp("pixie_performtime",-1);
			switch (perform_name)
		   {
		   case "pixie-cimu":
			   {
				   
				   if(me->query_temp("pixie/guimei"))
				   me->set_temp("pixie_superskill/poshensha",1);
				   me->set_temp("pixie_superskill/duoming",1);
     			   if( wizardp(me) &&me->query("env/pixie_test"))
				   {
				   printf(HIY"Perform cimu 成功，Set 成功 posheshan 1\n"NOR);
				   printf(HIY"Perform cimu 成功，Set 成功 duoming 1\n"NOR);
				   }
		
			   }
			   break;
   		   case "pixie-ciwan":
			   {
				   if((string)me->query_temp("pixie_use/3")=="pixie-cimu"
					&&(string)me->query_temp("pixie_use/4")=="pixie-ciwan"
				   &&(me->query_temp("pixie_superskill/poshensha")>=1))
				   {
				   me->set_temp("pixie_superskill/poshensha",2);
     			   if( wizardp(me) &&me->query("env/pixie_test"))
   				   printf(HIY"ciwan 条件成功，Set posheshan 2\n"NOR);
				   }
				   else
				   {
 				   if((string)me->query_temp("pixie_use/3")=="pixie-cizu"
					  &&(string)me->query_temp("pixie_use/4")=="pixie-ciwan"
				   &&(me->query_temp("pixie_superskill/duoming")>=2))
				   {
				   me->set_temp("pixie_superskill/duoming",3);
     			   if( wizardp(me) &&me->query("env/pixie_test"))
   				   printf(HIY"ciwan 条件成功，Set duoming 3\n"NOR);
				   }
				   else
				   {
					    //me->delete_temp("pixie_noop");
   						me->delete_temp("pixie_use");
					    me->delete_temp("pixie_superskill");
					    me->delete_temp("pixie_performtime");
			 		    if( wizardp(me) &&me->query("env/pixie_test"))
						{
      				   printf(HIM"ciwan 条件失败，Set duoming 0\n"NOR);
      				   printf(HIM"ciwan 条件失败，Set posheshan 0\n"NOR);
						}
				   //////////////////////////////////////////////////////////////
				   }
				   	if( wizardp(me) &&me->query("env/pixie_test"))
					{
					printf(HIC"夺命诡飞魂%d\n"NOR,me->query_temp("pixie_superskill/duoming"));
					printf(HIC"鬼魅破身杀完成%d\n"NOR,me->query_temp("pixie_superskill/poshensha"));
					}
				   }
			   }
			   break;
			case "pixie-cizu":
			   {
				   //////////////////////////////////////////////////////////////
  				   if((string)me->query_temp("pixie_use/3")=="pixie-cimu"
					  &&(string)me->query_temp("pixie_use/4")=="pixie-cizu"
				   &&(me->query_temp("pixie_superskill/duoming")>=1))
				   {
				   me->set_temp("pixie_superskill/duoming",2);
     			   if( wizardp(me) &&me->query("env/pixie_test"))
   				   printf(HIY"cizu 条件成功，Set duoming 2\n"NOR);
				   }
				   else
				   {
   						   me->delete_temp("pixie_use");
						   me->delete_temp("pixie_superskill");
						   me->delete_temp("pixie_performtime");
						   if( wizardp(me) &&me->query("env/pixie_test"))
      				       printf(HIM"cizu 条件失败，Set duoming 0\n"NOR);
				   }

			   }
			   break;
			}
	
	}
	else
	{
			   if( wizardp(me) &&me->query("env/pixie_test"))
			   	printf(HIC"Perform time =0 del all flag\n"NOR);
   			   me->delete_temp("pixie_use");
			   me->delete_temp("pixie_superskill");
			   me->delete_temp("pixie_performtime");
	}
	remove_call_out("checking_pixieflg");
	call_out("checking_pixieflg", 1, me, enemy, perform_name);
	return;
}
//use pixie-superskill
int do_prepare_superskill(string superskill_name,object me,object target,int ap,int dp)
{
	string perpare_msg;
	int dodge_skill,damage,cizu_busy;
	object weapon;
	weapon=me->query_temp("weapon");
	dodge_skill=target->query_skill("dodge");
	if(dodge_skill<=0) dodge_skill=0;
	perpare_msg="";
	if(me->query("dex")>25&&me->query("dex")>target->query("dex"))
			cizu_busy=me->query_dex();
		else
			cizu_busy=me->query_dex()/2;
	switch(superskill_name)
	{
	case "pixie-cizu":
		{
		   if((string)me->query_temp("pixie_use/3")=="pixie-cimu"
			  &&(string)me->query_temp("pixie_use/4")=="pixie-ciwan")
			  
			  if(me->query_temp("pixie_superskill/poshensha")>=2
				&&me->query_temp("pixie_performtime")
				&&me->query("neili")>300&&me->query("jingli")>300
					&&me->query_temp("pixie/guimei"))
				
			
				{

					perpare_msg += HIB "\n$N猛的催动鬼魅邪异般的身影，趁$n视线模糊，双手受创，闪身接近$n。\n"NOR;

					perpare_msg += HIB "$N突然一个矮身，手中"+weapon->query("name")+"连刺$n双足要穴。\n"NOR;

					if(me->query("qi")<me->query("max_qi")/3)
					ap=ap*3/2;
			        if( random(ap+dp) < dp )
					{
						perpare_msg += HIG "$n只听得身旁衣衫飘动声，知是$N袭近身来，当即双足点地，向后急退，躲过这诡异怪招。\n"NOR;
			            me->start_busy(3 + random(3));
					}
					else
					{
    					perpare_msg += HIR "$n知觉身前劲风扑来，知道大事不秒，惊慌中只觉双足一麻，已被$N刺中要穴，接着下身失去知觉。\n"NOR;	
						perpare_msg += HIY "$N眼中精光大盛，这「刺目」「刺腕」「刺足」三招一气呵成。\n"NOR;	
						perpare_msg += HIR "$n顿时全身失去知觉，再也动弹不得。。\n"NOR;	
						perpare_msg += HIB "$N诡异一笑，展开鬼魅般的身法，闪电般回到原处，似乎从未移动。\n"NOR;	
						target->add_temp("apply/dodge",  -dodge_skill);
						target->set_temp("pixie/cizu",1);
						target->set_temp("cannot_move",1);
						target->set_temp("cannot_move_msg","你双足要穴被刺中，哪里还能移动半步。");

						target->add_temp("pixie_times/cizu",1 );
						target->set_temp("pixie_bisha/poshensha",1);
						target->start_busy(me->query_skill("pixie-jian",1)/15);
						target->add("eff_qi",-(random((int)me->query_skill("pixie-jian"))*4/3));
						me->start_call_out( (: call_other, __FILE__, "remove_poshensha",target, dodge_skill :), cizu_busy);
						me->start_busy(1 + random(1));
					}


					me->add("neili", -(100+random(100)));
					me->add("jingli", -(100+random(100)));
					me->delete_temp("pixie_useperform");
					me->delete_temp("pixie_noop");
   				   me->delete_temp("pixie_use");
				   me->delete_temp("pixie_superskill");
				   me->delete_temp("pixie_performtime");
					
					message_vision(perpare_msg, me, target);
					return 1;

				}
		}
		break;
	case "pixie-cixin":
		{

		   if((string)me->query_temp("pixie_use/2")=="pixie-cimu"
			  &&(string)me->query_temp("pixie_use/3")=="pixie-cizu"
			  &&(string)me->query_temp("pixie_use/4")=="pixie-ciwan"
				&&me->query_temp("pixie_superskill/duoming",3)
				&&me->query_temp("pixie_performtime")
				&&me->query("neili")>500&&me->query("jingli")>500
					&&me->query_temp("pixie/guimei"))
				{
					
					perpare_msg += HIB "\n刹那见$N身影变得灵幻异常，趁$n视线模糊，全身受制之际，施展出辟邪剑法「刺心」绝技。\n"NOR;
					perpare_msg += HIB "$N轻摇腰肢，身影飘动，幻化出无数诡异人影。突然一影飞出，袭向$n。\n"NOR;
			        if(random(ap+dp)<dp||(random(7)==0))

					{
						perpare_msg += HIG"$n听得劲风扑面，知道是$N施展凌厉杀着，赶紧收住攻势，一个斜翻，险险的避开这一招。\n" NOR;
						me->start_busy(3 + random(5));
						me->delete_temp("pixie_performtime");
					}
					else
					{
   						
						perpare_msg += HIR "$n知觉身前劲风扑来，便知大事不妙，紧接着心口一疼，已被$N刺中。\n"NOR;	
						perpare_msg += HIY "$N眼中精光大盛，这「刺目」,「刺腕」「刺足」「刺心」四招一气呵成。\n"NOR;	
						perpare_msg += HIR "顿时一道血剑从$n心口标出，洒满当场。\n"NOR;	
						perpare_msg += HIB "$N诡异一笑，展开鬼魅般的身法，随着血剑向后退去，刹那间回到原处。\n"NOR;	
						
						damage=me->query_skill("pixie-jian",1)*(random(5)+5);
						if(me->query_skill("pixie-jian",1)>400)
						damage=damage*2;

						target->add_temp("pixie_times/cixin",1 );
						if(target->query("qi")<target->query("max_qi")/3)
							target->set("eff_qi",0);
							else
						{
						target->add("eff_qi",-damage*(2+random(2)));
						}
						if(target->query("eff_qi")<=0)
							target->unconcious();
						if(target->query("qi")<=0)
							target->unconcious();
						if(target->query("jingli")<=0)
							target->unconcious();
						me->start_busy(2 + random(2));
					}
					me->add("neili", -(100+random(200)));
					me->add("jingli", -(100+random(200)));
					me->delete_temp("pixie_useperform");
					me->delete_temp("pixie_noop");
   				   me->delete_temp("pixie_use");
				   me->delete_temp("pixie_superskill");
				   me->delete_temp("pixie_performtime");
					
					message_vision(perpare_msg, me, target);
					return 1;

				}
		}
		break;

	}
	return 0;

}


void remove_poshensha(object target,int dodge_skill)
{
		        if( !target ) return;
			target->add_temp("apply/dodge",  dodge_skill);
			target->delete_temp("pixie/cizu");
			target->delete_temp("pixie_times/cizu");
			target->delete_temp("pixie-bisha/poshensha");
			target->delete_temp("cannot_move");
			target->delete_temp("cannot_move_msg");

	        if(target->is_fighting() )
				message_vision(HIG"$N终于冲开下身穴道，双足行动恢复正常。\n"NOR, target);
			
			return ;

}




