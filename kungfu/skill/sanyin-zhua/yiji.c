//Cracked by Roath
//  /k/kungfu/sanyin-zhua/sanyin.c 三阴化功
// wsky 7/3/00

/*
    “丁春秋挥右拳挡住他拳头，跟着左拳猛力拍出。玄难中毒后转身不灵，难以
闪避，只得挺右手相抵。到此地步，已是高后比拼真力，玄难心下暗惊：“我决不
能跟他比拼内力！”但若拳上上不使内力，对方内力震来，立时便是脏腑碎裂，明
知已着了道儿，却不得不运内力抵挡。这一运劲，但觉内力源源不绝的向外飞散，
再也凝聚不起。
*/



#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myexp, targexp, damage, skill, merand, targrand, targneili,time,i;
	string str,*limb,type;
	mapping myfam;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("一击只能对战斗中的对手使用。\n");

	if ( (!( myfam= me->query("family")) || myfam["family_name"] != "星宿派") && me->query("id")!="wsky")
	          return notify_fail("只有星宿弟子利用本门秘传内功方能使用三阴一击。\n");

        if( !target->query_temp("huagong") && me->query("id")!="wsky" )
                return notify_fail("对手内力没有被化去，不要轻举妄动！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("空手才能施展三阴一击！\n");

        if( me->query_skill_mapped("claw") != "sanyin-zhua" )
                return notify_fail("你所用的并非三阴蜈蚣爪，不能施展三阴一击！\n");

        if( me->query_skill_prepared("claw") != "sanyin-zhua" )
                return notify_fail("你所备的并非三阴蜈蚣爪，不能施展三阴一击！\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("你所用的并非三阴蜈蚣爪，施展不出三阴一击！\n");

        if( (int)me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("你化功大法修为太差，不能运用三阴一击！\n");

        if( me->query_skill("sanyin-zhua",1) < 120 )
                return notify_fail("你三阴蜈蚣爪修为太差，不能运用三阴一击！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够使用三阴一击！\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够使用三阴一击！\n");     
        if( me->query("jing") <= 200 )
                return notify_fail("你的精不够使用三阴一击！\n");

        message_vision(HIR"\n$N脸色一沉，趁$n内力被化之机，五指陡张，大喝一声：“中！”\n"NOR,me,target);		

	skill=me->query_skill("sanyin-zhua",1);

	skill=random(skill+random(200))*2;
	
	if (skill>400) skill=400;
	
	if (skill<120) skill=120;
	
	//please at least test it before updating, the skill is at maximum 500
	//therefore applied damage is quite small by dividing a factor over 10
	//apply attack increase the chance of hit not damage. and, please notify
	//me for the change. thanks

	if( me->query_skill_prepared("strike") == "chousui-zhang" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("strike");
        }
	
	
	me->add_temp("apply/attack", skill);         
                               
        me->add("jiali", (skill/10)*2);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add("neili", -250);
        me->add("jingli", -150);
        
        me->add("jiali", -((skill/10)*2));
        
        me->add_temp("apply/attack", -(skill));

        if( me->query_temp("restore") ) me->prepare_skill("strike", "chousui-zhang");
	        	
	message_vision(HIY"\n$N一击之后，身行一晃，似乎略有疲惫。\n"NOR,me,target);		

	me->start_busy(1+random(2));

	return 1;
}        