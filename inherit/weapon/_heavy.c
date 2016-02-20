//Cracked by Roath
//heavy.c
#include <weapon.h>
#include <name.h>

#include <dbase.h>
#include <ansi.h>

void hit_weapon(object me, object victim, object weapon, int flag)
{
	int wap, wdp;
	
	//chip enemy weapon if edged
	if (!weapon || !(weapon->query("flag")&EDGED))
		return;
		
	wap = (int)this_object()->weight() / 500
        	+ (int)query("rigidity")
        	+ (int)me->query_str();
        wap = (int)weapon->weight() / 500
        	+ (int)weapon->query("rigidity")
        	+ (int)victim->query_str();
        wap = random(wap);
       // printf("%d, %d", wap, wdp);
                	
        if( wap > wdp / 2 )
        {
        	weapon->add("weapon_prop/damage", -1);
		
		if (weapon->query("weapon_prop/damage") < 1)
                //weapon broken
                {
                	message_vision(HIW "只听见「啪」地一声，$N手中的" + 
				weapon->name() + "已经被沉重的" + name() +
				"震断！\n" NOR, victim );
                	weapon->unequip();
                        weapon->move(environment(victim));
                        weapon->set("name", "断掉的" + weapon->query("name"));
                        weapon->set("value", (int)weapon->query("value") / 10);
                        weapon->set("weapon_prop", 0);
                        victim->reset_action();
                }else
                {
                	message_vision("$N手中的" + weapon->name() + "砸在$n的" +
                		name() + "上，刃被震出了一个缺口。\n", victim, me);
                }
	}
}