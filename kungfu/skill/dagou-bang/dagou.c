//Cracked by Roath
// dagou.c 打狗阵法
// By lichen@xkx.us
// For trying to make a dagou zhen. When perform dagou, increase temp damage.
// Suggestion: Zhenfa can be created in multiple rooms. Maybe we can use
// OOD to do it. I believe it will be more fun than making zhenfa as perform
// or skill.

#include <ansi.h>

// Define requirement is 4 dai gbdizi
// maximum number of people in 打狗阵 is 6 people
// minimum number of people in 打狗阵 is 2 people

#define REQUIRE 4
#define MAX_INARRAY 6
#define MIN_INARRAY 2

inherit F_DBASE;
inherit F_SSERVER;

string *ran_msg = ({
	"高叫：“老爷、太太、施舍口冷饭！”",
	"叫道：“老爷太太行行好，赏赐乞儿一文钱。”",
	"唱道：“天堂有路你不走哪！”",
	"唱道：“地狱无门你闯进来！”",
	"唱道：“施舍化子一碗饭哪！”",
});

string *ran_color = ({ HIC, HIG, HIY, HIR, HIM });

private string location(string direct);
void check_fight(object leader);
private void reset_effect(object *inarray, int partner, int ori_effect, int skill);
private void remove_effect(object inarray, int skill);
void random_msg(object leader);

int perform(object me)
{
    int skill, ori_effect;
    int partner, num;
    int user_num;
    object victim, weapon;
    object leader, *obj, *inarray, env;
    object *user_list;
    string id;
    
    leader = 0;
    inarray = ({0, 0 , 0, 0, 0, 0, 0});
    
    if( me->query("family/family_name") != "丐帮" )
		return notify_fail("你不是丐帮弟子，使用不了打狗阵。\n");
		
    if( (int)me->query_temp("dagou") ) 
        return notify_fail("你已经在参与打狗阵法了。\n");

	if( me->query("rank") < REQUIRE ) 
		return notify_fail("你的等级太低，不能使用打狗阵法！\n");
								
    if( !victim ) victim = offensive_target(me);

    if( !victim || !victim->is_character() || !me->is_fighting(victim) )
        return notify_fail("打狗阵法只能对战斗中的对手使用。\n");

	if( victim->query("family/family_name") == "丐帮" )
		return notify_fail("你怎么可以对同门使用打狗阵？\n");
	
	if( me->query_skill_mapped("stick") != "dagou-bang" 
	    || !objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "stick" ) 
        return notify_fail("你必须使用打狗棒法才能加入打狗阵。\n");
   
   	env = environment(me);
 	obj = all_inventory(env);
	num = sizeof(obj);
	partner = 0;
	
	// check how many users are in 打狗阵. If there are someone in the 打狗阵,
	// then get leader and victim.
	
	for( int i = 0; i < num; i++ ) {
	    if( obj[i]->query_temp("dagou") ) {
	        if( !leader ) {
	        	if( obj[i]->query_temp("dagou/is_leader") == -1 )
	            	leader = obj[i]->query_temp("dagou/data");
	            else
	            	leader = obj[i];
	            victim = leader->query_temp("dagou/data")[0][MAX_INARRAY];
	        }
	        partner++;
	    }
	}
	
	// If in the room there is no one take part in 打狗阵, then set this user
	// as leader. If any other 4dai or above gb dizi here are fighting the same 
	// victim, then these gb dizi set_temp("dagou", pointer to the leader ). the 
	// leader set_temp("dagou") 4 variables. First one is "leader"(indicate he is 
	// the leader of the array, second one is a pointer point to all people in 
	// array(打狗阵), third one is total stick skill of all people who join the 
	// arraym, the forth is the number of people who join the array.
	
	if( partner == 0 ) {
		inarray[0] = me;
		inarray[MAX_INARRAY] = victim;
			   
	    message_vision( HIR"$N忽然高声叫道：各位丐帮兄弟，结打狗阵！帮我对付$n！\n" NOR, me, victim);
		
		user_list = users();
		user_num = sizeof(user_list);

		// Let all 4 dai(or above) gb dizi who are in the same area know that someone is using 打狗阵.
		// It is to increase the interaction between gb dizi.
		// 正所谓：一方有难，百方支援。
		
		while( user_num-- ) {
			if( !environment(user_list[user_num]) ) continue;
			if( user_list[user_num]->query("family/family_name") != "丐帮" 
				|| user_list[user_num]->query("rank") < REQUIRE ) continue;
			if( environment(user_list[user_num]) == env ) continue;
			if( !living(user_list[user_num]) ) continue;
			if( location(file_name(env)) == location(file_name(environment(user_list[user_num]))) )
			    tell_object( user_list[user_num], HIG"你隐隐约约地听到在远处" + me->query("name")
				    + "好象在发动打狗阵对付" + victim->query("name") + "。"
				    + "\n听方向好象是" + env->query("short") + "。\n\n"NOR );
		    else 
   			    tell_object( user_list[user_num], HIG"你隐隐约约地听到在远处杀声震天，好象有丐帮弟子在发动打狗阵！\n\n"NOR );
		} 
			
		partner = 1;
		skill = me->query_skill("stick");
		
	    for( int i=0; i < num; i++) {
            if( obj[i] == me ) continue;
            if( !living(obj[i]) ) continue;
	    	if( !obj[i]->is_character() || obj[i]->is_corpse() ) continue;
	    	if( !obj[i]->is_fighting(victim) ) continue;
	    	if( obj[i]->query_skill_mapped("stick") != "dagou-bang" ) continue;
	    	if( !objectp(weapon = obj[i]->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "stick" )
                continue;
	 	    if( obj[i]->query("rank") < REQUIRE ) continue;
			if( !obj[i]->is_fighting(victim) ) continue;					         
		    if( (int)obj[i]->query_temp("dagou") ) continue;              
		        
            inarray[partner] = obj[i];
            message_vision( 
			    HIR "$N一边长声唱道：“各路的弟兄来讨饭哟，啊哟哎唷哟……”" + 
			    "一边包围着$n。\n" NOR, inarray[partner], victim );
            skill += inarray[partner]->query_skill("stick");
            partner++;
            if( partner == MAX_INARRAY ) break;
		}
		

		me->set_temp("dagou/is_leader", 1);
		me->set_temp("dagou/data", ({ inarray, skill, partner }) );
		
		skill = (int)(skill / (partner*3));
		if( partner > 1 ) {
			for( int i = 0; i < partner; i++ ) {
		        inarray[i]->add_temp("apply/dodge",  skill );
		        if( i > 0 ) {
	    			inarray[i]->set_temp("dagou/is_leader", -1);
    				inarray[i]->set_temp("dagou/data",  me );
    			}
			}
		}
       	
   	    call_out("random_msg", 5, me);
      	
		me->start_call_out( (: call_other, __FILE__, "check_fight", me :), 1);

	}
	
	else if( partner >= MAX_INARRAY ) 
		return notify_fail("打狗阵法只能由二人至六人参与。\n");

    else {
    	inarray = leader->query_temp("dagou/data")[0];
	    skill = leader->query_temp("dagou/data")[1];
	    ori_effect = (int)(skill / (partner*3));
	    if(partner == 1) 
	    	leader->add_temp("apply/dodge", ori_effect );
	    me->add_temp("apply/dodge", ori_effect );
    	inarray[partner] = me;
    	partner += 1;
    	skill += me->query_skill("stick");
    	leader->set_temp("dagou/data", ({ inarray, skill, partner }) );
    	reset_effect(inarray, partner, ori_effect, skill);	
        me->fight_ob(victim);
		victim->fight_ob(me);
		me->set_temp("dagou/is_leader", -1);
		me->set_temp("dagou/data", leader);
		message_vision( 
	    HIR "$N一边长声唱道：“老爷太太行行好，赏赐乞儿一文钱。”" +
	    "一边加入打狗阵，包围$n。\n" NOR, me, victim );
	    for( int i = 0; i < partner-1; i++ )
	    	tell_object(inarray[i], HIG"\n你看见有人加入打狗阵，不由得精神为之一振。\n"NOR);
	}

    return 1;
}

private string location(string direct)
{
	int start, end, count, next;

	while (count != 3) {
		if( direct[next] == '/' ) count++;
		if (count == 2 && start == 0) 
			start = next+1;
		next++;
	}
	end = next-2;
	direct = direct[start..end];
	return direct;
}

void check_fight(object leader)
{
    object weapon, *inarray;
    int partner, skill, ori_effect, ori_partner;
	
	if( !leader->query_temp("dagou") ) return;
	
	inarray = leader->query_temp("dagou/data")[0];
	skill = leader->query_temp("dagou/data")[1];
	partner = leader->query_temp("dagou/data")[2];
	ori_effect = (int)(skill / (partner*3));
	ori_partner = partner;
	
	// If the victim is dead or run away or the qi less than 50, then
	// the 打狗阵 is done.
	// If the leader is not fighting with the victim or the leader is not
	// using dagou-bang skill, then the 打狗阵 is finish too. 
    
    if( !living(inarray[MAX_INARRAY]) 
        || !present(inarray[MAX_INARRAY]->query("id"), environment(leader)) 
        || inarray[MAX_INARRAY]->query("qi") <= 50 
        || !leader->is_fighting(inarray[MAX_INARRAY]) 
        || leader->query_skill_mapped("stick") != "dagou-bang"
        || !objectp(weapon = leader->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "stick" )  
    {
		if ( partner != 1 ) {
	    	for ( int i = 0; i < partner; i++ )
		    	remove_effect(inarray[i], ori_effect);
		    if (living( leader ))
		    	message_vision(HIM"$N大喊一声：“收阵！”。众人口唱“莲花阵”，各自收招。\n\n"NOR, leader);
		    else
		    	message_vision(HIM"众人失去了$N，群龙无首，于是一哄而散。\n\n"NOR, leader);
		}
		else {
			leader->delete_temp("dagou");
			if ( living(leader) )
	    	    message_vision(HIM"$N看见没有人加入打狗阵，脚底抹油，一声不吭地溜了。\n\n"NOR, leader);
    	}
        return;
    }

	// Else, if the leader is still in the 打狗阵，check all the people who are in
	// the array. If someone is not fighting with the victim or is not using dagou-bang
	// skill, then this guy quit the 打狗阵。After that, reset the effect.
	
    else {
    	for ( int i = 1; i < ori_partner; i++ ) {
    		if ( inarray[i] == 0 ) break;
    		if ( !inarray[i]->is_fighting(inarray[MAX_INARRAY]) 
	    		 || inarray[i]->query_skill_mapped("stick") != "dagou-bang"
    		     || !objectp(weapon = inarray[i]->query_temp("weapon")) 
          	     || (string)weapon->query("skill_type") != "stick" ) 
          	{
          		message_vision( 
			    HIG "$N一边长声唱道：“这路的弟兄讨完饭哟，啊哟哎唷哟……”，"
			    + "一边退出了打狗阵。\n"NOR, inarray[i]);
          		remove_effect(inarray[i], ori_effect);
          		skill -= inarray[i]->query_skill("stick");
          		partner -= 1;
	       	    if( i != partner ) {		      
	       	    	inarray[i] = inarray[partner];
	       	    	inarray[partner] = 0;	       	    	
	       	    	i--;
	       	    }
	       	    
	       	    else inarray[i] = 0;
	       	}
	    }
	    
	    if( ori_partner != partner ) {
		    leader->set_temp("dagou/data", ({inarray, skill, partner}));
	        reset_effect(inarray, partner, ori_effect, skill);	        
	    }
	}
    
    call_out("check_fight", 1, leader);
}

private void reset_effect(object *inarray, int partner, int ori_effect, int skill)
{
	skill = (int)(skill/(partner*3));
	
	if(partner == 1) 
	{
		inarray[0]->add_temp("apply/dodge", -ori_effect );
		return;
	}
	
	else {
		for( int i = 0; i < partner; i++ )
		{
			if(inarray[i] == 0 ) break;
			inarray[i]->add_temp("apply/dodge", -ori_effect );
			inarray[i]->add_temp("apply/dodge", skill );
		}
	}
}

private void remove_effect(object inarray, int skill)
{
    inarray->add_temp("apply/dodge", -skill );
    inarray->delete_temp("dagou");
}

void random_msg(object leader)
{
	int partner;
	int ran;
	int ran_usr, ran_usr1;
	object obj, obj1, victim, weapon;
	
	if( partner = leader->query_temp("dagou/data")[2] ) {
		if(random(5) < 2) {
			if( partner > 1 ) {
				ran_usr = random(partner);
				obj = leader->query_temp("dagou/data")[0][ran_usr];
				ran = random(5);
				message_vision( ran_color[ran] + "$N在打狗阵内" + ran_msg[ran] + "\n" NOR, obj);
				victim = leader->query_temp("dagou/data")[0][MAX_INARRAY];
				
				// This is for 棒掌结合 and 双棒结合.
				
				// this is 棒掌结合。
				if ( random(2) == 1 ) {						
					if( obj->query_skill_prepare()["strike"] == "xianglong-zhang" ) {
					    message_vision(ran_color[ran] + "$N突然冒险进击，单手持棒，攻向$n。\n"NOR, obj, victim);
					    weapon = obj->query_temp("weapon");
					    COMBAT_D->do_attack(obj, victim, weapon, 1);
			    		obj->delete_temp("weapon");
				    	obj->set_temp("action_flag",1);
					    COMBAT_D->do_attack(obj, victim);
					    obj->set_temp("weapon", weapon);
					    obj->set_temp("action_flag",0);
					    if ( obj->query("neili") >= 150 ) obj->add("neili", -10);
					}
				}
				// this is 双棒结合。
				else {	
					do {
						ran_usr1 = random(partner);
					} while ( ran_usr1 == ran_usr);
					
					obj1 = leader->query_temp("dagou/data")[0][ran_usr1];
					message_vision(ran_color[ran] + "$N和$n突然冒险进击，双棒结合，舞成一团棒影，共同进攻。\n"NOR, obj, obj1);
					COMBAT_D->do_attack(obj, victim, obj->query_temp("weapon"), 1);
					obj1->set_temp("action_flag", 1);
					COMBAT_D->do_attack(obj1, victim, obj1->query_temp("weapon"), 1);
					obj1->set_temp("action_flag", 0);
					if ( obj->query("neili") >= 150 ) obj->add("neili", -5);
					if ( obj1->query("neili") >= 150 ) obj1->add("neili", -5);
				}
			}
			else
				message_vision( ran_color[ran] + "$N孤军作战，" + ran_msg[ran] + "并尽量拖延时间，等待群丐加入。\n"NOR, leader);
		}
			
		call_out("random_msg", 6, leader);
	}
}
