//Cracked by Roath
//ruhe.c 岱宗如何 by maco
/*
这一招可算得是泰山派剑法中最高深的绝艺，要旨不在右手剑招，
而在左手的算数。左手不住屈指计算，算的是敌人所处方位、武功
门派、身形长短、兵刃大小，以及日光所照高低等等，计算极为繁
复，一经算准，挺剑击出，无不中的。
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「岱宗如何」只能对战斗中的对手使用。\n");

        if( me->query_temp("ruhe") )
                return notify_fail("你已经在以「岱宗如何」计算如何出招了！\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，即使以「岱宗如何」计算攻守，也无法出击。\n");

        if( me->query_skill("sword") < 100 )
                return notify_fail("你在剑法上的造诣不足以使出「岱宗如何」！\n");

        skill = me->query_skill("sword");

        message_vision(YEL"\n只见$N右手"+weapon->query("name")+YEL"斜指而下，左手五指正在屈指而数，正是「岱宗如何」的要旨。\n" NOR, me, target);
	me->set_temp("ruhe_count", 1);	
        me->add_temp("apply/attack", skill*2);
        me->add_temp("apply/dodge", skill);
        me->add_temp("apply/parry", skill);
        me->set_temp("ruhe", 1);

        call_out("checking", 1, me, target);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill /7);
	
        me->add("neili", -150);
        me->add("jingli", -150);
        return 1;
}


void checking(object me, object target)
{

	object weapon;
        int skill;
	string *msg;
        skill = me->query_skill("sword");
	weapon = me->query_temp("weapon");

	if ( me->query_temp("ruhe_finish")  ) {
		me->set_temp("ruhe_hit",1);
                message_vision(HIW"\n$N左手捏起剑诀，已经结束「岱宗如何」的计算。\n" NOR, me);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
        	me->delete_temp("ruhe");
        	me->delete_temp("ruhe_hit");
        	me->delete_temp("ruhe_count");
        	me->delete_temp("ruhe_finish");
	}
        else if ( me->query_temp("ruhe")  ) {

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n你手中无剑，继续算下去也是枉然，得停止「岱宗如何」的计算。\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }

           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n你的"+weapon->name()+"已毁，继续算下去也是枉然，得停止「岱宗如何」的计算。\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }
           else if ( (int)me->query("jing") < 200  ) {
                tell_object(me, "\n你暗觉精神不继，难以继续以「岱宗如何」计算，好停止计数。\n\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "shiba-pan" ) {
                tell_object(me, "\n你转而施展其他剑法，不能再以「岱宗如何」计算。\n\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n你现在没有和人过招，自然也不用以「岱宗如何」计算了。\n\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }
	   else {
        msg = ({
		"$N左手从一数到五，握而成拳。\n",
		"$N将拇指伸出，次而食指，终至五指全展，跟着又屈拇指而屈食指，再屈中指。\n",
		"$N左手不住屈指计算，右手"+weapon->name()+"轻轻摆动。\n",
		"$N左手五指不住伸屈，似乎在计算数目。\n",
		});
	message_vision(msg[random(sizeof(msg))], me,target);
	me->add_temp("ruhe_count",1);	
        me->add("jing", -20);	
	call_out("checking", 1, me, target);
		}
	}
	   else return;

}  

void remove_effect(object me)
{
        int skill;
        skill = me->query_skill("sword");
        if ( me->query_temp("ruhe") ) {
		me->set_temp("ruhe_hit",1);
                message_vision(HIW"\n$N左手捏起剑诀，已经结束「岱宗如何」的计算。\n" NOR, me);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
        	me->delete_temp("ruhe");
        }
}
