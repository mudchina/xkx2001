//Cracked by Roath
// bandaged.c

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	mapping drug_app;
	string *type;
	int i;

	if( mapp(drug_app = me->query_temp("medication")) )
		type = keys(drug_app);

	if( sizeof(type) )
		for( i=0; i < sizeof(type); i++ )
		{
			switch( type[i] )
			{
			case "vulnerary":
				if( (int)me->query("eff_qi") < (int)me->query("max_qi") )
					me->receive_curing("qi", drug_app[type[i]]);
				if( wizardp(me) ) tell_object(me, "治愈："+drug_app[type[i]]+"\n");
				if( drug_app[type[i]] == 10 )
					tell_object(me, "绷带上的伤药渐渐失去了药性．．\n");
				break;
			}
			drug_app[type[i]] -= 1;
			if( drug_app[type[i]] > 0 )
				me->set_temp("medication/"+type[i], drug_app[type[i]]);
			else me->delete_temp("medication/"+type[i]);
		}
	else if( (int)me->query("eff_qi") < (int)me->query("max_qi") )
		me->receive_curing("qi", 3+random(5));

	me->apply_condition("bandaged", duration - 1);
	if( !duration ) return 0;

	return CND_CONTINUE;
}
