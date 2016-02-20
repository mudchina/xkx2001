//Cracked by Roath
// sleep.c
// littlefish
// last updated Marz (07/05/96)
// last updated Ryu (11/10/97)

void wakeup(object, object);
//void del_sleeped();

int main(object me, string arg)
{
	string event;
	mapping fam;
	object where = environment(me);


        seteuid(getuid());

	if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("这里不是你能睡的地方！\n");
   
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能睡觉！\n");
        
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("店小二从门外对$N大叫: 把这里当避难所啊! 先到一楼付钱后再来睡!\n",me);
		return 1;
	}
 
/*
	if (me->query_temp("sleeped"))
		return notify_fail("你刚在三分钟内睡过一觉, 多睡对身体有害无益! \n");
*/

	if (where->query("night_room")){
	event = NATURE_D->outdoor_room_event();
	if (event != "event_night" && event != "event_midnight" && event != "event_dawn")
                return notify_fail("天没黑，睡什么觉？\n");
	}

	if (where->query("sleep_room"))
	{
		write("你往床上一躺，开始睡觉。\n");
		write("不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me);
	}
	else { 
		write("你往地下角落一躺，开始睡觉。\n");
		write("不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n",me);
	}

	/*where->set("no_fight", 1);*/
	where->add_temp("sleeping_person", 1);

	//me->set("no_get", 1);	
	//me->set("no_get_from", 1);	
	
	if (!(where->query("hotel"))) 
		me->set_temp("sleeped",1);
	else
		me->delete_temp("rent_paid");

	me->disable_player("<睡梦中>");

	call_out("wakeup",random(60 - me->query("con")), me, where);
        
	return 1;
	
}

void wakeup(object me,object where)
{
	int sp, new_hp;

	sp = 10 - (int)me->query_condition("sleep");

//	me->add("qi", (((me->query("eff_qi")) - me->query("qi"))*sp)/10 + 3);
	new_hp = (int)me->query("qi");
	new_hp += ((int)me->query("eff_qi") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_qi") ) new_hp = me->query("eff_qi");
	me->set("qi", new_hp);
	
//	me->add("jing", (((me->query("eff_jing")) - me->query("jing"))*sp)/10 + 3);
	new_hp = (int)me->query("jing");
	new_hp += ((int)me->query("eff_jing") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_jing") ) new_hp = me->query("eff_jing");
	me->set("jing", new_hp);

//	me->add("jingli", ((me->query("max_jingli") - me->query("jingli"))*sp)/20 + 5);
	new_hp = (int)me->query("jingli");
	new_hp += ((int)me->query("max_jingli") - new_hp)*sp/5;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_jingli") ) new_hp = me->query("max_jingli");
	me->set("jingli", new_hp);

//	me->add("neili", ((me->query("max_neili") - me->query("neili"))*sp)/20 + 5);
	new_hp = (int)me->query("neili");
	new_hp += ((int)me->query("max_neili") - new_hp)*sp/20;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_neili") ) new_hp = me->query("max_neili");
	me->set("neili", new_hp);
	
	if (living(me)) return;

	me->enable_player();
        while( environment(me)->is_character() )
        	me->move(environment(environment(me)));
	me->apply_condition("sleep", 8 + random(5));
  
	/*call_out("del_sleeped", 179, me);*/

	message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
	me->set_temp("block_msg/all", 0);
	write("你一觉醒来，只觉精力充沛。该活动一下了。\n");

	//if (!where->query("sleep_room") && !where->query("hotel"))
		//where->delete("no_fight");
     
	where->add_temp("sleeping_person", -1);
	//me->delete("no_get");	
	//me->delete("no_get_from");	
 
}

/*
void del_sleeped(object me)
{
	if (objectp(me) &&  me->query_temp("sleeped"))
		me->delete_temp("sleeped");
}
*/
