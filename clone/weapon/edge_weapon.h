//Cracked by Roath
mixed hit_ob(object me, object victim, object weapon, int damage_bonus, int factor)
{
        object ob;
	int j, k; 

        if (victim->query_temp("armor/cloth") 
	&& random(this_player()->query_str()) > 20){
	ob = victim->query_temp("armor/cloth");
	if (!ob->query("wreckage"))
	ob->set("origina_armor", ob->query("armor_prop/armor"));
	
	if (ob->query("armor_prop/armor") > 0 && ob->query("armor_prop/armor") < 150){
        ob->add("armor_prop/armor", -1);
	ob->add("wreckage", 1);
	victim->add_temp("apply/armor", -1);

	k=ob->query("original_armor");
	j=ob->query("armor_prop/armor");

	if (ob->query("material") != "steel" && ob->query("material") != "iron"){
	message_vision(HIW"只听见「嗤」地一声，$N身上的$n"+HIW+"被划开一道口子。\n"NOR, victim, ob);
	}
	else{
	message_vision(HIW"只听见「喀」地一声，$N身上的$n"+HIW+"被砍出一道缺口。\n"NOR,victim, ob);
	}

	if ( j < k/4 || j < 1){
        ob->set("long", "一件残破不堪的"+ob->query("name")+"\n");
        if (!ob->query("wreck")){
        ob->set("name", "破" + ob->query("name"));
        ob->set("value", 0);
        ob->add("wreck", 1);
                }
        }
        if ( j < k/2 && j > k/4){
        ob->set("long", "一件被划开了几道大缝的"+ob->query("name")+"\n");
        ob->set("value", ob->query("value")/3);
        }
        if ( j < k && j > k/2){
        ob->set("long", "一件裂了几道口的"+ob->query("name")+"\n");
	ob->set("value", ob->query("value")/2);
	     }
	}
    }
}
