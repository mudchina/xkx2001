//Cracked by Roath
// auto perform function (dispatched by chat_combat_msg)

int auto_throw()
{
	object me = this_object();
	object target = me->select_opponent();

	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;

	if (present("fei biao", me) || present("jinqian biao", me)){
	command("throw biao at "+target->query("id"));
	return 1;
	}
	if ( present("tougu ding", me)){
	command("throw ding at "+target->query("id"));
        return 1;
	}
}
