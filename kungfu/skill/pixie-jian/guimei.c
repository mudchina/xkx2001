//Cracked by Roath
//辟邪剑法之鬼魅
//wzfeng@xkx 99 9

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "pixie_superskill.c"

void checking(object me);

int perform(object me, object target)
{
        
        
        int level;

        if( !target ) target = offensive_target(me);

        if(me->query("canuse_guimei")!=1)
			    return notify_fail("什么？\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「鬼魅」只能在战斗中使用。\n");


		if( (int)me->query_temp("pixie/guimei") )
                return notify_fail("你正在运功中!\n");
        if( me->query("jingli") <=1000  )
                return notify_fail("你的精力不够，不能使用「鬼魅」。\n");
        if( me->query("neili") <=200  )
                return notify_fail("你的内力不够，不能使用「鬼魅」。\n");


        if( (level = (int)me->query_skill("pixie-jian", 1)) < 120 )
                return notify_fail("你的辟邪剑法不够娴熟，不能不能将其溶入身法中。\n");

        if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("你没有将辟邪剑法运在身法上，无法使出「鬼魅」。\n");
        if( (string)me->query_skill_mapped("parry") != "pixie-jian" )
                return notify_fail("你没有将辟邪剑法运在招架上，无法使出「鬼魅」。\n");                

        message_vision(HIB"\n$N嘿嘿嘿一阵尖笑，身影蓦地里骤然加快，飘忽不定，形若鬼魅！\n"NOR, me);
		
        me->add("neili", -50);
        me->set_temp("pixie/guimei",level/5);

		remove_call_out("checking");
		call_out("checking", 1, me);
		
        return 1;
}

void checking(object me)
{

	if(me->query_skill_mapped("sword") != "pixie-jian"
		||me->query_skill_mapped("dodge") != "pixie-jian"
			||me->query_skill_mapped("parry") != "pixie-jian"
			||!objectp(me->query_temp("weapon")))
	{
		tell_object(me,"你使用了其它的武功，鬼魅渐渐失去功效。\n");
        message_vision(HIB"\n$N长长呼了口，身法渐渐慢了下来。\n"NOR, me);
        me->delete_temp("pixie/guimei");
		   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");

       return ;

	}

       if( !living(me) || me->is_ghost() )
        {
                me->delete_temp("pixie/guimei");
			   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");

                return ;
        }
		if( !me->is_fighting() )
        {
		        message_vision(HIB"\n$N长长呼了口，收住那鬼魅诡邪的身形！\n"NOR, me);
                me->delete_temp("pixie/guimei");
						   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");

                return ;
        }
		if( me->query_temp("pixie/guimei") <= 0 )
        {
		        message_vision(HIB"\n$N长长呼了口，身法渐渐慢了下来。\n"NOR, me);
               me->delete_temp("pixie/guimei");
			   		   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");

                return ;
        }
		me->add_temp("pixie/guimei",-1);
		call_out("checking", 1, me);
		return;
}


