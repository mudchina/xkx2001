//Cracked by Roath
// sword.c
#include <ansi.h>
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_sword(int damage, int flag)
{
        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | EDGED);
        set("skill_type", "sword");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
        }
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object ob;
	object weapon = me->query_temp("weapon");
	int j, k; 
	
        if (victim->query_temp("armor/cloth") 
	&& random(weapon->query("weapon_prop/damage")) >= 10){
	ob = victim->query_temp("armor/cloth");
	if (!ob->query("wreckage"))
	ob->set("origina_armor", ob->query("armor_prop/armor"));
	
	if (ob->query("armor_prop/armor") > 0 && ob->query("armor_prop/armor") < 150){
        ob->add("armor_prop/armor", -1);
	ob->add("wreckage", 1);
	victim->add_temp("apply/armor", -1);

	k=ob->query("original_armor");
	j=ob->query("armor_prop/armor");

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
	if (ob->query("material") != "steel" && ob->query("material") != "iron")
        return HIW"只听见「嗤」地一声，$n身上的"+ob->query("name")+HIW+"被划开一道口子。\n"NOR;
        else
        return HIW"只听见「喀」地一声，$n身上的"+ob->query("name")+HIW+"被砍出一道缺口。\n"NOR;
	}
	
    }
}
