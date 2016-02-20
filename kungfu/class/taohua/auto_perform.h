//Cracked by Roath
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");
	object weapon2 = target->query_temp("weapon");

        if( !me->query_temp("wuzhuan") && random(2)==0)
                command("exert wuzhuan");

	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;

	if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "sword" )
		{
		switch( random(3) )
                {
                        case 0:
				return perform_action("sword.jinglei");
                                break;
                        case 1:
                                return perform_action("sword.jianmang");
                                break;
                        case 2:
                        	{me->prepare_skill("kick");
                        	me->prepare_skill("strike");
                        	me->prepare_skill("finger","tanzhi-shentong");
                                return perform_action("sword.jianzhi");}
                                break;

			}
                }
	}
	
	else {
	if(objectp(weapon2) && random(2) == 0) {
	me->prepare_skill("kick");
	me->prepare_skill("strike");
	me->prepare_skill("finger","tanzhi-shentong");
	return perform_action("finger.jinglei");
	}
	else {
	me->prepare_skill("kick","xuanfeng-saoye");
	me->prepare_skill("strike","luoying-shenjian");
	me->prepare_skill("finger");
	return perform_action("strike.kuangfeng");
	}
	}
}
