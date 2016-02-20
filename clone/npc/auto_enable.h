//Cracked by Roath
// Xuy 12/25/96

// used an insertion sort to avoid sorting overhead in sort_array
// a stupid auto enable, better than not
void auto_enable()
{
	object me = this_object();
	string *sorted_skills, *mapped_types = ({});
	string temp, pre1, pre2;
	mapping skill_status;
	int i, j;
	string *unarmed_types = ({
        "finger",
        "hand",
        "cuff",
        "claw",
        "strike",
        "kick",
	});
	string *weapon_types = ({
        "sword",
        "blade",
        "stick",
        "staff",
        "club" ,
        "hook",
        "halberd",
        "throwing",
        "force",
        "parry",
        "dodge",
        "magic",
        "whip",
        "hammer",
	});

	skill_status = me->query_skills();
	sorted_skills = keys(skill_status) - unarmed_types - weapon_types;

	for (i=1; i<sizeof(sorted_skills); i++) {
		j = i;
		temp = sorted_skills[j];
		while( j>0 &&
		       skill_status[temp] > skill_status[sorted_skills[j-1]] ) {
			sorted_skills[j] = sorted_skills[j-1];
			j--;
		}
		sorted_skills[j] = temp;
	}

	for (i=0; i<sizeof(unarmed_types); i++)
	    me->prepare_skill(unarmed_types[i]);

	for (i=0; i< sizeof(sorted_skills); i++) {
	    for (j=0; j<sizeof(weapon_types); j++) 
		if (SKILL_D(sorted_skills[i])->valid_enable(weapon_types[j])) {
		    me->map_skill(weapon_types[j], sorted_skills[i]);
		    mapped_types += ({weapon_types[j]});
		}
	    weapon_types -= mapped_types;
	    for (j=0; j<sizeof(unarmed_types); j++) 
		if (SKILL_D(sorted_skills[i])->valid_enable(unarmed_types[j])) {
	 	    me->map_skill(unarmed_types[j], sorted_skills[i]);
		    mapped_types += ({unarmed_types[j]});
		    if (sizeof(me->query_skill_prepare())==0) {
			pre1 = sorted_skills[i];
		    	me->prepare_skill(unarmed_types[j], pre1);
		    }
		    else if(sizeof(me->query_skill_prepare())==1
			 && SKILL_D(pre1)->valid_combine(sorted_skills[i])) {
			pre2 = sorted_skills[i];
			me->prepare_skill(unarmed_types[j], pre2);
		    }
		}
	    unarmed_types -= mapped_types;
	}
	me->set("jiali", me->query_skill("force")/2);
	me->reset_action();

}
//well, some unresolved mysterious bug, so abandon the following way:)
//overload kill_ob in /feature/attack.c added by xuy.
/*void kill_ob(object ob)
{
	auto_enable();

        ::kill_ob(ob);
}*/

//overload fight_ob
/*void fight_ob(object ob)
{
	auto_enable();

	::fight_ob(ob);
}*/
