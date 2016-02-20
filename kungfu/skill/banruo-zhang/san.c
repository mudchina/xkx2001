//Cracked by Roath
// san.c 一拍两散
/*
玄寂适才所出那一掌，实是毕生功力之所聚，叫作“一拍两散”，
所谓“两散”，是指拍在石上，石屑四“散”、拍在人身，魂飞
魄“散”。这路掌法就只这么一招，只因掌力太过雄浑，临敌时
用不着使第二招，敌人便已毙命，而这一掌以如此排山倒海般的
内力为根基，要想变招换式，亦非人力之所能。
*/

inherit F_SSERVER;

int perform(object me, object target)
{
        int org_enfor, enfor;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("一拍两散只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") )
                return notify_fail("你只能在空手时使用一拍两散！\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
                return notify_fail("你所用的并非混元一气功，无法施展一拍两散！\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 180)
                return notify_fail("你的混元一气功火候未到，无法施展一拍两散！\n");

        if( me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("你的般若掌火候未到，无法施展一拍两散！\n");

        if( me->query_skill("buddhism", 1) < 180 )
                return notify_fail("你的佛学修为不够，无法施展一拍两散！\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("你的内力修为不足，劲力不能运发，无法施展一拍两散！\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("jingli") < 500  )
                return notify_fail("你的精力不够。\n");
        
        org_enfor = me->query("jiali");

        // I tried the original code with no restriction, a 4Kneili player
        // can make 15K damage in this 1 hit.  With the limit, a 4K
        // neili player can still make 4K damage sometimes. -Chu

	enfor = me->query("max_neili")/10;
	enfor = org_enfor + enfor/2;
	enfor = enfor/2+random(enfor);

        me->set("jiali", enfor);

	if( wizardp(me) ) tell_object(me, "enforce : " + enfor);

	me->set_temp("sl_perform/san", 1);
	if( me->query_skill_prepared("finger") == "yizhi-chan" )
	{
		me->set_temp("restore_yzc", 1);
		me->prepare_skill("finger");
	}
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->delete_temp("sl_perform/san");
	if( me->query_temp("restore_yzc") )
	{
		me->prepare_skill("finger", "yizhi-chan");
		me->delete_temp("restore_yzc");
	}

        me->add("neili",-(500+enfor*2));
        me->add("jingli",-(300+enfor));
	if( me->query("neili") < 0 ) me->set("neili", 0);
	if( me->query("jingli") <= 0 ) me->set("jingli", 1);
        me->set("jiali", org_enfor);
        me->start_busy(4+random(3));
        return 1;
}
