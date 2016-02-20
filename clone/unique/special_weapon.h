//Cracked by Roath
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object obj;

	if (objectp(obj = victim->query_temp("weapon"))){

	if (obj->query("skill_type") == "hammer" && obj->query("rigidity") >=50)
	return 0;

	if ( this_object()->query("weapon_prop/damage")*3/4 > obj->query("weapon_prop/damage")){
	message_vision(HIW"「铮」地一声轻响，$N手中的$n"+HIW+"已被"+this_object()->query("name")+HIW"削成两截。\n"NOR, victim, obj);
		obj->unequip();
        	obj->move(environment(victim));
        	obj->set("name", "断掉的" + obj->query("name"));
		obj->set("value", 0);
        	obj->set("weapon_prop", 0);
        	victim->reset_action();
		set_heart_beat(1);
	     }
	return;
	}
}

