//Cracked by Roath
// feed.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest;
	int time;
        time = ((me->query("mud_age"))-(me->query("pktime")));

	if(!arg) return notify_fail("你要喂什么东西给谁？\n");

	if( sscanf(arg, "%s to %s", item, target)!=2 )
		return notify_fail("你要喂谁什么东西？\n");

	if( !objectp(dest = present(target, environment(me))) )
		return notify_fail("这里没有这样东西。\n");

	if( !dest->is_character() )
		return notify_fail("这样东西不是活物。\n");

	if( dest->query("race") == "人类" )
		return notify_fail("你不能用这东西喂人！\n");

	if( !(obj = present(item, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( userp(me) && userp(obj) && me->query_condition("pker") > 240)
		return notify_fail("你感到一丝内疚，手突然软了下来。\n");
			
        if( (time < 3600) && userp(obj))
                return notify_fail("你自觉杀心太重，手软了下来！\n");	
	
	if (!living(obj) && obj->is_character() &&
	!obj->query("food_supply") && dest->query("race")=="野兽" ) 
	{
                if (obj->query("disable_type") == "<睡梦中>"
                && random(obj->query_con()) > 3 
		&& dest->query("name") != "老虎" 
		&& obj->query("combat_exp") > random(dest->query("combat_exp")))
 {
                     obj->revive();
                     obj->move(environment(me));
		     obj->receive_wound("qi", (int)(obj->query("eff_qi")/2));	

message_vision("$n的头被"+dest->name()+"咬了一口，$n顿时疼的醒了过来！\n", me, obj);
                     obj->kill_ob(me);
		     obj->kill_ob(dest);	
                     return 1;
                } 
}
	if (!living(obj) && obj->is_character() && !obj->query("food_supply") && dest->query("race")=="野兽" ) {
		if (obj->query("disable_type") == "<睡梦中>"
		    && random(obj->query_con()) > 10) {
		     obj->enable_player();
		     obj->move(environment(me));
		     message_vision("$N想把$n的头喂给" + dest->name()+"吃，$n突然惊醒！\n", me, obj);
		     obj->kill_ob(me);
		     return 1;
	        } else {
		     message_vision("$N把$n的头喂给" + dest->name()+"吃了。\n",  me, obj);
		     if (userp(obj) && userp(me) )
			me->apply_condition("pker", me->query_condition("pker")+120);
		     obj->set_temp("last_damage_from", "被" +me->name()+"喂了" + dest->name()+"了");
		     obj->die();
		     return 1;
		}
	}

	if( obj->query("food_supply") <= 0 || obj->query("food_race") != dest->query("race") )
		return notify_fail("你不能用这东西喂它！\n");

	if (!obj->query("food_remaining"))
		return notify_fail(obj->name() + "已经没什么好喂的了。\n");

	if( dest->query("food") >= dest->max_food_capacity() )
		return notify_fail("它已经吃太饱了，再也塞不下任何东西了。\n");

	dest->add("food", obj->query("food_supply"));
	dest->add("jingli", obj->query("food_supply"));
	if( dest->query("jingli") > dest->query("max_jingli")) 
	dest->set("jingli", dest->query("max_jingli"));

//	if (obj->query("food_remaining")>4) obj->set("food_remaining",4);
	obj->add("food_remaining", -1);
	if (!obj->query("food_remaining") ) {
		message_vision("$N喂著" + dest->name() + "吃完了" + obj->name() +"。\n",  me);
		destruct(obj);
	}
	else 
	message_vision("$N拿起" + obj->name() + "喂著" + dest->name() + "吃了几口。\n", me);

	if( dest->is_fighting() ) dest->start_busy(2);

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : feed|wei <食物名称> to <某动物>
 
这个指令可以让你将某样食物喂给某动物食用，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
