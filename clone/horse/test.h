//Cracked by Roath
//horse.h for horse fainting when riding.
//RYU

condition_check()
{
        object *ob, me = this_object();
        int my_jingli, my_mj, i, addjing;

        my_jingli  = (int)me->query("jingli");
	my_mj = (int)me->query("max_jingli");
	addjing = (my_mj - my_jingli)/2;

	if(my_jingli <= my_mj/3){
	say(me->name() +"大口大口地喘着粗气。\n");
	return;
	}

        if(my_jingli <=30 && my_jingli > 20){
        say(me->name() +"只在喘气，渐渐地快跑不动了！\n");
	return;
        }

        if(my_jingli <=10){
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if (ob[i]->query("rided") == me);
        ob[i]->delete("rided");
        }
        me->delete("rider");
        me->unconcious();
	return;
        }
}
void init()
{
	object me=this_object();

	int my_jingli, my_mj, i, addjing;
        my_jingli  = (int)me->query("jingli");
        my_mj = (int)me->query("max_jingli");
        addjing = (my_mj - my_jingli)/2;

	if( environment(me)->query("resource/grass") &&
	me->query("food") < (me->max_food_capacity()*2/3)){
	me->set("food", (int)me->max_food_capacity());
	me->add("jingli", addjing);
	say(me->name() +"低下头在草地上吃起草来。\n");
	return;
	}	

	add_action("do_look", "look");
	add_action("do_ting", "ting");
        add_action("do_ting", "stay");
        add_action("do_fang", "fang");
        add_action("do_fang", "release");
	add_action("do_gen", "gen");
        add_action("do_gen", "come");
}
int do_look(string arg)
{
	object *inv;
        int i;

        inv = all_inventory(this_object());

	if (!id(arg)) return 0;

	if (!sizeof(inv)) return 0;
	
	printf(this_object()->query("long") + 
	COMBAT_D->eff_status_msg((int)this_object()->query("eff_qi")* 100 / (int)this_object()->query("max_qi")) + "\n" 
	+ "它身上驮着：\n");
        for (i = 0; i < sizeof(inv); i++)
                printf("%s \n", inv[i]->short());
        return 1;
}
