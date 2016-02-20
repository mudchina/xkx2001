//Cracked by Roath
// ma-fu.c 马夫
// cleansword 12/25/96

inherit NPC;
inherit F_DEALER;

string ask_me_buy();
string ask_me_sell();
string ask_me_feed();
string ask_me_rent();

void create()
{
	set_name("马夫", ({ "ma fu", "fu", "pawn" }) );
	set("gender", "男性" );
	set("age", 20+random(20));
	set("long",
		"这是位老实巴交的马夫，满头大汗，脸上身上沾满了草料屑，手里拿着把锋利的铡刀。\n");
	set("combat_exp", random(5000));
	set("attitude", "friendly");
	set("no_get", 1);

	set("inquiry", ([
		"买马" : (: ask_me_buy  :),
		"卖马" : (: ask_me_sell :),
		"喂马" : (: ask_me_feed :),
		"租马" : (: ask_me_rent :),
	]));

	set("vendor_goods", ({
		"/d/shaolin/obj/caoliao",
		"/d/shaolin/obj/hulu",
	}));

	setup();
}

void init()
{	
	object me, ob, env, *inv;
	mapping exits;
	string *dirs;
	int i;

	me = this_object();
	ob = this_player();
	env = environment(me);
	inv = all_inventory(env);

	if( ob->query("race") == "野兽"
	&& mapp(exits = environment()->query("exits")) 
	&& query("jingli") < query("max_jingli") / 2 ) {
//		dirs = keys(exits);
//		message_vision("马夫一见情势不妙，急忙溜了出去。\n", ob);
        message_vision("\n突然，只见$N闪身拔开一堆草料，下面露出一道暗门，钻了进去，咔嚓从里边把门锁上了。\n",
		this_object());
		destruct(this_object());
//		command("go " + dirs[random(sizeof(dirs))]);
	}

	for( i=0; i<sizeof(inv); i++ ) {
		if( inv[i]->query("race") == "家畜" && inv[i]->query_lord() == ob ) {
			if( !living(inv[i]) ) {
				command("say 客官，您的马晕过去了，让我来弄醒它！");
				message_vision("马夫倒了一桶水泼在马身上，\n", ob);
				inv[i]->revive();
			} else command("say 客官，您的马就在这里，我这就把它牵过来！");	

			inv[i]->set_leader(ob);
			if( !ob->query("rided") ) {
				inv[i]->set("rider", ob);
				ob->set("rided", inv[i]);
				ob->delete_temp("horse_guest");
				remove_call_out("byebying");
				call_out("byebying", 3, ob);
			}

			return;
		}
	}

	if( ob->query_temp("horse_guest") ) {
		say("马夫苦丧著脸道：客官，实在对不起，我找不见您的马了 ... \n");
		command("say 您看是不是另买一匹骑乘？ 我这里给您打半折！");
		ob->delete_temp("horse_guest");
		ob->set_temp("horse_loser", 1);
		return;
	}

	if( interactive(ob) && ob->query("race") == "人类" && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_train", "train");
	add_action("do_train", "xun");
}

void greeting(object ob)
{
	object animal;
	mapping exits;
	string *dirs;

	if( !ob || environment(ob) != environment() ) return;

	if( objectp(animal = ob->query("rided")) && environment(animal) == environment() ) {
		if( animal->query("race") == "野兽"
		&& mapp(exits = environment()->query("exits")) ) {
//			dirs = keys(exits);
//			message_vision("马夫一见情势不妙，急忙溜了出去。\n", ob);
        message_vision("\n突然，只见$N闪身拔开一堆草料，下面露出一道暗门，钻了进去，咔嚓从里边把门锁上了。\n",
		this_object());
		 	destruct(this_object());	
//			command("go " + dirs[random(sizeof(dirs))]);		
		} else say("马夫小步跑了过来，笑道：客官可是要我替您喂牲口？请尽管吩咐！\n");
	} else {
		switch( random(2) ) {
		case 0:
			say( "马夫点头哈腰地说道：这位客官，是想到这里挑一匹好马吧？\n");
			break;
		case 1:
			say( "马夫笑咪咪说道：这位客官留步，我们这里多的是各地良马，您不妨瞧瞧。\n");
			break;
		}
	}
}

void byebying(object ob, object horse)
{
	if( !ob || environment(ob) != environment() || !horse) return;
	message_vision("\n马夫利落地把$N牵了过来，扶著$n骑了上去。\n\n", horse, ob);
	say("马夫挥手道：客官慢走，下次再来呀！\n");
}

int accept_object(object ob, object money)
{
	object me, horse, env, *inv;
	string name;
	int i, value;

	me = this_object();
	env = environment(me);
	inv = all_inventory(env);

	if(!money->query("money_id")) {
		say("马夫摆手道：对不起，小的不能乱收东西！\n");
		return 0;
	}

	if( ob->query_temp("horse_guest") && !ob->query_temp("horse_loser") ) {	
		if( money->value() >= 100 + random(500) ) {
			say("马夫哈腰说道：多谢，客官请放心，您的马我会照料好的！\n");
			for( i=0; i<sizeof(inv); i++ ) {
				if( inv[i]->query("race") == "家畜" && inv[i]->query_lord() == ob ) {
					if( !living(inv[i]) ) inv[i]->revive();
					message_vision("马夫当下就把马牵到马槽边喂马。\n", ob);

					inv[i]->set("water", inv[i]->max_water_capacity() * 8 /10 );
					inv[i]->set("food", inv[i]->max_food_capacity() * 8 /10 );
					inv[i]->set("jingli", inv[i]->query("max_jingli") * 8 /10 );
					return 1;
				}
			}
		} else {
			say("马夫点头笑道：小的多谢客官了！嘻嘻！\n");
			command("bow " + ob->id());
			return 1;
		}
	} else {
		if( objectp(horse = ob->query_temp("horse_asked")) ) {
			if( ob->query("horse_loser"))
				value = horse->query("value") * 50;
			else	value = horse->query("value") * 100;

			if( money->value() >= value ) {
				say("马夫一迭声地点头道：够了够了，我这就把" +
			horse->query("name") +"牵过来给您！\n");	

				horse->set_lord(ob);
				horse->set_leader(ob);

				if( !ob->query("rided") ) {
					horse->set("rider", ob);
					ob->set("rided", horse);
					ob->delete_temp("horse_asked");
					remove_call_out("byebying");
					call_out("byebying", 3, ob, horse);
				}
				return 1;
			} else {
				say("马夫挡住你的手，摇头道：对不起，客官。你的钱不够！\n");
				return 0;
			}
		} else {
			say("马夫摇头道：客官给小的银子作甚？您可是想在此挑匹好马？\n");
			return 0;
		}
	}

	return 1;
}

int do_train(string arg)
{
	object me, ob, animal, xunbu1, xunbu2, butou;

	me = this_object();
	ob = this_player();

	if(ob->is_fighting()){
		say("你正忙着呢！\n");
	return 1;
	}
	if( stringp(arg) && arg != 0 
	&& objectp(animal = present(arg, environment())) 
	&& animal->query("race") == "家畜" 
	&& !me->is_fighting() ) {
		message_vision("马夫大喊一声：贼骨头，想偷马！说罢朝著$N就冲了过来！\n", ob);
//		command("chat 来人啦！" + ob->query("name") + "这个"
//		+  RANK_D->query_rude(ob) + "想偷马！");
//		me->kill_ob(ob);
//		message_vision("捕头带着两位巡捕急急忙忙冲了进来！\n", ob);
		ob->apply_condition("killer", 100);
/*		xunbu1=new("/d/city/npc/xunbu");
		xunbu1->move(environment(ob));
		xunbu1->set_leader(ob);
		xunbu1->kill_ob(ob);
		xunbu2=new("/d/city/npc/xunbu");
                xunbu2->move(environment(ob));
                xunbu2->set_leader(ob);
                xunbu2->kill_ob(ob);
		butou=new("/d/city/npc/xunbu");
                butou->move(environment(ob));
                butou->set_leader(ob);
                butou->kill_ob(ob);
*/
		return 1;
	}

	return 0;
}

int do_say(string arg)
{
	object ob, horse, *inv;
	string name;
	int i, value;

	ob = this_player();
	inv = all_inventory(environment());

	if( objectp(horse = ob->query_temp("horse_asked")) ) {
		if( arg == "中意" )
			say("马夫笑道：呵呵呵，那就给钱吧，客官！\n");
		if( arg == "不中意" )
			say("马夫笑道：没关系，客官您就再挑一匹吧！\n");
		return 1;
	}

	if( stringp(arg) && arg != 0 ) {
		for( i=0; i<sizeof(inv); i++ ) {
			if( inv[i]->query("race") == "家畜" && inv[i]->query("name") == arg ) {
				if( inv[i]->query_lord() )
					ob->set_temp("horse_else", inv[i]);
				else	ob->set_temp("horse_asked", inv[i]);
			}
		}
		
		if( objectp(horse = ob->query_temp("horse_asked")) && horse->name() == arg ) {
			say("马夫道：客官好眼力，这匹" + horse->name() + "只要" 
			+ chinese_number(horse->query("value")) + "两银子，您中意不？\n");
			return 1;
		}

		if( objectp(horse = ob->query_temp("horse_else")) && horse->name() == arg ) {
			say("马夫道：客官，这匹马是别人寄在这儿的，不能卖！\n");
			ob->delete_temp("horse_else");
			return 1;
		}		
	}
//	remove_action("do_say", "say");
	
	return 0;
}

string ask_me_buy()
{
	object *inv;
	string word;
	int i, j;

	inv = all_inventory(environment());

	if( sizeof(inv) < 1 )
	return "唉，最近光顾的客人太多，我们这里已经没马可卖了！";

	say("马夫说道：您瞧，\n");
	for( i=0; i<sizeof(inv); i++ ) {
		if( inv[i]->query("race") == "家畜" ) {
			j++;
			if( objectp(inv[i]->query_lord()) ) word = "有主儿了。\n";
			else word = "值" + chinese_number(inv[i]->query("value")) + "两银子。\n";
			say("	第" + chinese_number(j) + "匹" + inv[i]->name() + word);
		}
	}

	add_action("do_say", "say");
	return "我们这里有的是好马，您说要哪一匹吧！";
}

string ask_me_sell()
{
	object ob, horse, silver;
	int value;

	ob = this_player();	

	if( objectp(horse = ob->query("rided")) && environment(horse) == environment() ) {
		if( horse->query("qi") <= horse->query("max_qi")/10 
		||  horse->query("jing") <= horse->query("max_jing")/10 
		||  horse->query("jingli") <= horse->query("max_jingli")/10 )
			return "这马都快死了，还来卖！滚开！";
		if( horse->query("baituo"))
			return "小的只有一个脑袋，白驼山主人的座骑可不敢买的。";
		else {
			value = horse->query("value")/2;

			horse->set_lord(0);
			horse->set_leader(0);
			horse->delete("rider");
			ob->delete("rided");

			silver=new("/clone/money/silver");
			silver->set_amount(value);
			silver->move(ob);

			message_vision("马夫点点头，扔给$N几锭银子。接著牵过疆绳，把马拉到一旁。\n", ob);

			return "这匹马又老又丑，只能用来拉磨！算" 
			+ chinese_number(value) + "两银子吧！";
		}
	} else return "马呢？";
}

string ask_me_feed()
{
	object ob, horse;
	ob = this_player();	

	if( objectp(horse = ob->query("rided")) && environment(horse) == environment() ) {
		horse->set_leader(0);
		horse->delete("rider");
		ob->delete("rided");
		ob->set_temp("horse_guest", 1);

		message_vision("马夫牵著疆绳，把马拉到一旁。\n", ob);
		return "客官放心，您的马我会照看好的。";
	} 
	else 	return "马呢？";
}

string ask_me_rent()
{
	return "现在我们这里没马可租！";
}
int accept_kill(object me)
{
	object xunbu1, xunbu2, butou;
	if (!this_object()->is_fightin()){
	command("chat 来人啦！" + me->query("name") + "这个"
	+  RANK_D->query_rude(me) + "想偷马！");
        me->apply_condition("killer", 100);
        return 1;
	}
}
void unconcious()
{
        message_vision("\n突然，只见$N闪身拔开一堆草料，下面露出一道暗门，钻了进去，咔嚓从里边把门锁上了。\n",
                this_object());
        destruct(this_object());
}

