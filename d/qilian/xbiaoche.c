//Cracked by Roath
// /clone/npc/obj/xbiaoche.c 镖车
// sdong,12/05/98 created

#include <ansi.h>
#include <room.h>
inherit ITEM;

string *Robber_Name = ({
					 "土匪","山大王","路霸","山贼","毛贼","寨主","帮匪"
});



mapping default_dirs = ([
		  "north":        "北",
		  "south":        "南",
		  "east":         "东",
		  "west":         "西",
		  "northup":      "北边",
		  "southup":      "南边",
		  "eastup":       "东边",
		  "westup":       "西边",
		  "northdown":    "北边",
		  "southdown":    "南边",
		  "eastdown":     "东边",
		  "westdown":     "西边",
		  "northeast":    "东北",
		  "northwest":    "西北",
		  "southeast":    "东南",
		  "southwest":    "西南",
		  "up":           "上",
		  "down":         "下",
		  "out":          "外",
		  "enter":        "里",
]);



void set_owner(object owner,object owner2);
int do_drive(string arg);
int do_open();
int do_check();
int do_unride(string arg);
int do_ride(string arg);
int do_attack(string arg);
int do_rob(string arg);
void host_appear();
void destroy_cart(object cart);
void greeting(object ob);
void destroy_it(object ob);

void create()
{
	seteuid(getuid());
	set_name(HIB"镖车"NOR, ({"biao che", "che"}));
	set("long",
		"这是一辆非常结实的镖车，由两匹大骡子拉着，不知装着什么东西。镖车上竖着一面大旗，上书“神鹰镖局”四个大字。\n");
	set("unit", "辆");
	set_weight(10000);
	set_max_encumbrance(5000);
	set("value", 1000000);
	set("material", "steel");
	set("no_get",1);
	set("no_refresh", 1);
	remove_call_out("auto_check");
	call_out("auto_check", 30+random(30) );
}

void init()
{
	object ob;

	add_action("do_check", "check");
	add_action("do_open", "open");
	add_action("do_drive", "gan");
	add_action("do_ride", "ride");
	add_action("do_ride", "shang");
	add_action("do_unride", "leave");
	add_action("do_attack", "attack");
	add_action("do_attack", "att");

	if( interactive(ob = this_player()) ) {
		 call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	int bonus,old_pot;

	object target,robber;
	object here = environment(this_object());
	object owner;
	string sO;

	if( !ob || environment(ob) != environment() ) return;


	sO = query("owner");

	if(sO)
	 owner = present( sO,here);

	if( !owner || owner != ob )
	{
		sO = query("owner2");

		if(sO)
		 owner = present( sO,here);
	}

	if( !owner || owner != ob)return;


	if( !owner && here && (robber = present("robber",here)) )
	{
		robber->command("open");
	}
	else if( query_temp("biao/dest2") && here && (base_name(here) == query_temp("biao/dest2") )&& owner && userp( owner ) )
	{
		message_vision(HIG"\n$N"+HIG"累得半死，总算赶到目的地！\n\n",owner);

		if( (target = present( query_temp("biao/dest"),here)  ) )
		{
			call_out("award",1,target,ob );
		}
		else
		{
			message_vision(RED"可是$N"+RED"却找不到主人，把$P急得直冒汗！\n\n"NOR,owner);
			remove_call_out("host_appear");
			call_out("host_appear", 2 + random(3) );
		}
	}
	else if( query_temp("biao/dest") && here && (target = present( query_temp("biao/dest"),here)  ) )
	{
			message_vision("$N急急忙忙离开了！\n",target);
			target->move( query_temp("biao/dest2")+".c" );
			message_vision("$N急急忙忙走了过来！\n",target);
	}
}

void host_appear()
{
	object target;
	string host = query_temp("biao/dest");

	if(!host)return;

	target = find_object( host );
	if(!target)target = find_player(host);
	if(!target )target = find_living(host);

	if( !target )
	{
		return; //call_other(query_temp("biao/dest2")+".c", "???");
	}
	else
		message_vision("$N急急忙忙离开了！\n",target);

	if(target)
	{
		target->move( query_temp("biao/dest2")+".c" );
		message_vision("$N急急忙忙走了过来！\n",target);
	}

}

void award2(object dest,object owner)
{
	object wage;
	object here = environment(dest);
//	object owner = present( cart->query("owner"), here );

	if(userp(owner))
	{
		wage=new("/clone/money/gold");
		wage->set_amount( 1 + random(5) );
		wage->move(owner);
		message_vision(HIY"$N"+HIY"递给$n几锭黄金，说：“一点小意思，"+RANK_D->query_respect(owner)+"请笑纳！”\n"NOR,dest,owner);
		owner->delete_temp("biao/dest");
		owner->delete_temp("biao/dest2");
		owner->delete_temp("riding");
		owner->set_temp("biao/bonus",660+random(500) );
	}
}

void award(object dest,object owner)
{
	object *obj,here = environment(dest);
	object cart=this_object(); // = present( cart->query("owner"), here );
	int i;

	if(userp(owner))
	{
		message_vision(HIY"$N"+HIY"跳下了镖车！\n"NOR,owner);
		owner->delete_temp("riding");
		message_vision("$N上前对着$n抱拳道：“这位"+RANK_D->query_respect(dest)+"请了。"+RANK_D->query_self(owner)+"总算不负所托，现将镖货原物奉上。请您清点！”\n",owner,dest);
		message_vision("$N满脸堆笑的说：“这位神鹰镖局的"+RANK_D->query_respect(owner)+"果然英雄了得。"+RANK_D->query_self(dest)+"多谢了！”\n",dest);
		call_out("award2",1,dest,owner);


		obj = all_inventory(here);

		 for(i=0;i<sizeof(obj);i++)
		{
			if( living(obj[i]) && ( obj[i]->query_temp("biao/owner") == owner->query("id")
				|| obj[i]->query_temp("biao/owner2") == owner->query("id") )
			 && obj[i] != owner )
			{
				call_out("destroy_cart",2,obj[i]);
			}
		}

		call_out("destroy_cart",3,cart);
	}
}

void destroy_cart(object cart)
{
	if( !objectp(cart) )return;
	if( cart->query("race") != "人类" )
		message_vision("仆人上前把$N拉走了。\n",cart);
	else message_vision("丫环上前把$N请进去了。\n",cart);

	destruct(cart);
}

void set_owner(object owner,object owner2)
{
	object ob = this_object();//present("biao che",environment());
	set("owner",owner->query("id"));
	if(owner2)
		set("owner2",owner2->query("id"));
	set_temp("biao/dest",owner->query_temp("biao/dest") );
	set_temp("biao/dest2",owner->query_temp("biao/dest2") );

	call_out("destroy_it", 1200,ob);
}



int do_ride(string arg)
{
	object me = this_player();
	object cart = this_object();


	if (!arg) return notify_fail("你要上什么？\n");

	if( me->query_temp("riding") )  return notify_fail("你已经在镖车上！\n");

	if( cart = present("biao che",environment()) );

	if( query("owner") != me->query("id") && query("owner2") != me->query("id"))return notify_fail("不是你的车。\n");

	message_vision(HIY"$N"+HIY"神气地跳上了镖车，一手拿起鞭子，一手握住缰绳，吆喝了起来！\n"NOR,me);
	me->set_leader( cart );
	me->set_temp("riding",1);
	return 1;
}

int do_unride(string arg)
{
	object me = this_player();

	if( !me->query_temp("riding") )  return notify_fail("你已经不在镖车上！\n");

	message_vision(HIY"$N"+HIY"跳下了镖车！\n"NOR,me);
	me->delete_temp("riding");
	return 1;
}



int auto_check()
{
	object me = this_object();
	object here,owner;
	if( !me )return;
	here = environment(me);
	if(!here) return;

	if( !(owner = present(me->query("owner"),here) ) ) {
		call_out("auto_check", 30+random(30) );
		return 1;
	}

	if( strsrch(base_name(here), "/d/city") == -1 &&
		strsrch(base_name(here), "/d/") != -1 &&
		strsrch(base_name(here), "duchuan") == -1   )
	{
				remove_call_out("killer_show");
				call_out( "killer_show",1+random(5),owner );
	}

	call_out("auto_check", 30+random(30) );
	return 1;
}


void do_leave(object ob)
{
		if( objectp(ob) )
		{
			if( ob->is_busy() || ob->is_fighting())
			{
				message_vision("$N向后一跳，跳出战圈！\n",ob);
				if( random(2)==0 )
					message_vision("$N说道：没想到神鹰镖局的还真有两下子。"+RANK_D->query_self(ob)+"今天暂且饶你一条狗命！\n",ob);
				else
					message_vision("$N说道：今天老子手气不好，算你狠，改日再来陪你玩！\n",ob);
			}

			if(!living(ob))ob->revive(0);
			message_vision("$N急急忙忙离开了。\n",ob);
			destruct(ob);
		}
}

void action(object me, object ob)
{
	object here = environment(me);
	if( !me || !ob || !present(ob->query("id"),here) )
	{
		do_leave(ob);
		return;
	}

	if( !living(ob) )
	{
		 call_out("action",random(10),me,ob);
		 return;
	}

	if( !ob->is_busy() && !ob->is_fighting() )
	{
	  if( random(3) ) message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(ob)+"我正好缺几个钱花。相好的，识趣点交出宝贝，就饶你一条全尸！\n"NOR, ob);
	  else if( random(3) )  message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(ob)+"我替天行道，劫富济贫，狗腿子，识趣点交出宝贝，就饶你不死！\n"NOR, ob);
	  else message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(ob)+"听说什么屁鹰镖局的为虎作伥，狗腿子，识趣点早点滚蛋，就饶你不死！\n"NOR, ob);
	  ob->kill_ob(me);
	}

	call_out("action",random(10),me,ob);
}


private int is_suitable(object victim, object killer)
{
		  string *no_kill_list = ({
					 "mu ren",
					 "huang zhen",
					 "juexin dashi",
					 "fighter dummy",
					 "du e",
					 "du nan",
					 "du jie",
					 "xie yanke",
					 "ren woxing",
					 "qu san",
					 "yue buqun",
					 "qiu chuji",
					 "zhang sanfeng",
					 "zuo lengchan",
					 "ouyang zhan",
					 "seng bing",
					 "ma guangzuo",
					 "black gargoyle",
					 "white gargoyle",
					 "tang nan",
					 "zhu xi",
					 "tangzi shou",
					 "lao chaofeng",
					 "hua tiegan",
					 "lu tianshu",
                "yideng dashi",
					 "liu chengfeng",
					 "qu san",
					 "zhao zhijing",
					 "lu youjiao",
					 "cheng buyou",
		  });

		  if(  !clonep(victim) || userp(victim)
			|| victim->query("race") != "人类"
			|| victim->query("shen") <= 0
			|| victim->query("winner")
			|| strsrch(base_name(victim), "/kunfu/skill/") != -1
			|| strsrch(base_name(victim), "/clone/user/") != -1
			|| strsrch(base_name(victim), "/clone/test/") != -1
			|| strsrch(base_name(victim), "/u/") != -1
			|| strsrch(base_name(victim), "/d/xiakedao/") != -1
			|| victim->query("combat_exp") < killer->query("combat_exp") * 1/4
			|| victim->query("combat_exp") > killer->query("combat_exp")*7/4
			|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
		  {
					 return 0;
		  }
		  return 1;
}

void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) )return;

	if( obj->query("combat_exp") < me->query("combat_exp") )
	{
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(50) )  );
	}

	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;

	if( obj->query("combat_exp") < 300000 )
	{
		level = level/2 + random(level*2/3);
	}
	else if( obj->query("combat_exp") < 500000)
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 800000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 1000000)
	{
		level = level/2 + random(level/4);
	}
	else
		level = level/2 + random(level/5);

	if( me->query("family/family_name") == "峨嵋派" ) // their qi short, so lower robber's skill a bit
	{
		level = level*2/3 + random( level/3);
	}
	else if( me->query("family/family_name") == "少林派" || me->query("family/family_name") == "雪山派" )
	{
		level = level*3/4 + random( level/4);
	}


	skills = obj->query_skills();
	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
	  obj->set_skill(names[i], level);
	}

	obj->delete( "title" );
	obj->delete( "nickname");
	obj->delete( "long" );
	obj->delete( "family" );
	obj->delete( "name" );
	obj->delete( "short" );
	obj->set_name(Robber_Name[random(7)], ({ "robber", "zei" }));
	obj->set("owner",me->query("id"));
	obj->set_temp("biao/dest",me->query_temp("biao/dest"));

	if( query("owner2") )
		obj->set("owner2",query("owner2"));

	call_out("do_leave",20+random(20),obj);

}

void killer_show(object me)
{
  object ob,here;
  object *target_list;
  int i;

  if( !me ) return;
  here = environment(me);

  if(!here)return;
  if( strsrch(base_name(here), "/d/") == -1 ) return;

  if ( query("food") >= 200  )return;

  if( me->is_fighting() ) return;

  target_list = filter_array(livings(), "is_suitable", this_object(), me);
  if( sizeof(target_list) == 0 ) {
		  // try again in 5 secs.
		 call_out("killer_show", 5, me);
		 return;
  }

  do
  {
	  i = random(sizeof(target_list));
	  ob=new( base_name(target_list[i]) + ".c" );
  }
  while( !objectp(ob) );

  ob->move(here);
  setup_skill(me,ob);
  message_vision("\n$N突然跳了出来!\n", ob);

  ob->set_leader(me);
  call_out("action",random(3),me,ob);

  if( random(4) == 1)
  {
	  remove_call_out("killer_show");
	  call_out( "killer_show",1+random(2),me );
  }
}


int do_attack(string arg)
{
	object here, *obj, me = this_player(),target;
	string victim;
	int i;

	if (!arg) return notify_fail("你要攻击谁？\n");

	victim = arg;
	if ( victim == me->query("id") ) return notify_fail("你发疯啦？\n");
	here = environment(me);

	target = present(victim, here);
	if (!target) return notify_fail("这里并无此人！\n");

	if ( target->query("race") != "人类" )
	{
		return notify_fail("你发疯啦？\n");
	}

	obj = all_inventory(here);

	message_vision(HIR "$N对着$n"+HIR"喝道："+RANK_D->query_rude(target)+HIR"也想劫镖？弟兄们，给我狠狠地教训$p！\n\n" NOR, me, target);

	if( me->query_temp("biao/dest") )
	{
		for(i=0;i<sizeof(obj);i++)
		{
			if( living(obj[i]) &&
				(	obj[i]->query_temp("biao/dest") == me->query_temp("biao/dest")
					|| obj[i]->query_temp("biao/owner") == me->query("id")
					|| obj[i]->query_temp("biao/owner2") == me->query("id")
				)  && obj[i] != me && obj[i]->query("id") != "robber" && target->query("id") != obj[i]->query("id") )
			{
				message_vision(HIY "只见$N应声冲着$n扑了过去！喝道："+RANK_D->query_rude(target)+HIY"拿命来吧！\n" NOR, obj[i], target);
				obj[i]->kill_ob(target);
			}
		}
	}

	if(random(2)==0)
		message_vision( HIR "\n$N对着$n"+HIR"冷笑一声：狗腿子便是全上，俺又有何惧，看招！\n\n" NOR, target,me );
	else message_vision( HIR "\n$N对着$n"+HIR"冷笑一声：想倚多为胜？看招！\n\n" NOR, target,me );
	target->kill_ob(me);

	return 1;
}





int do_check()
{
	object ppl = this_player();
	object obj = this_object();

	if ( obj->query_temp("biao/dest") == "dao baifeng" ) write("这是由"+obj->query("owner")+"压运的大理王妃刀白凤的镖货。\n");
	else if ( obj->query_temp("biao/dest") == "hu laoye" ) write("这是由"+obj->query("owner")+"压运的北疆小镇巴依托送的重镖，要尽快送到。\n");
	else if ( obj->query_temp("biao/dest") == "ye erniang" ) write("这是西夏叶二娘托送的重镖，由"+obj->query("owner")+"压运，要尽快送到。\n");
	else if ( obj->query_temp("biao/dest") == "feng yiming" ) write("这是佛山英雄会馆凤一鸣的重镖，由"+obj->query("owner")+"压运。\n");
	else if ( obj->query_temp("biao/dest") == "wang tongzhi" ) write("这是泉州济世堂老店的重镖，由"+obj->query("owner")+"压运，务必交到药铺掌柜王通治手里。\n");

	return 1;
}

void destroy_it( object obj)
{
	object ppl;
	if(!objectp(obj))return;

	if( !obj->query("owner") ) return;
	ppl = find_player( obj->query("owner") );
	if( userp(ppl) )
	{
		ppl->delete_temp("apply/short");
		ppl->delete_temp("biao");
		ppl->set_temp("biao/fail", 1);
	}

	if( objectp(obj) )
	{
		if( userp(ppl) && ppl->query_temp("riding") )
		{
			message_vision( HIR"骡子突然发疯似的拉着$N"+HIR"就跑，把$n"+HIR"一屁股甩在地上，转眼就跑没影了。！\n",obj,ppl);
		}
		else
			message_vision( HIR"骡子突然发疯似的拉着$N"+HIR"跑，转眼就跑没影了。！\n",obj );
		destruct(obj);
	}
}

int do_rob(string arg)
{
	object here, *obj, me = this_player(),target;
	string victim;
	int i;

	if (!arg) return notify_fail("你要攻击谁？\n");

	victim = arg;
	if ( victim == me->query("id") ) return notify_fail("你发疯啦？\n");
	here = environment(me);

	target = present(victim, here);
	if (!target) return notify_fail("这里并无此人！\n");

	if ( target->query("race") != "人类" )
	{
		return notify_fail("你发疯啦？\n");
	}

	obj = all_inventory(here);

  if(random(3)) message_vision(HIR"\n$N"+HIR"喝道：此树是我栽，此路是我开，要从此处过，留下买路钱。相好的，识趣点交出宝贝，就饶你一条狗命！\n"NOR, me);
  else if( random(3) ) message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我正好缺几个钱花。相好的，识趣点交出宝贝，就饶你一条全尸！\n"NOR, me);
  else message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我替天行道，劫富济贫，狗腿子，识趣点交出宝贝，就饶你不死！\n"NOR, me);

	//me->kill_ob(me);
	//message_vision(HIR "$N对着$n"+HIR"喝道："+RANK_D->query_rude(target)+HIR"也想劫镖？弟兄们，给我狠狠地教训$p！\n\n" NOR, me, target);

	if( me->query_temp("biao/dest") )
	{
		for(i=0;i<sizeof(obj);i++)
		{
			if( living(obj[i]) &&
				(	obj[i]->query_temp("biao/dest") == me->query_temp("biao/dest")
					|| obj[i]->query_temp("biao/owner") == me->query("id")
					|| obj[i]->query_temp("biao/owner2") == me->query("id")
				)  && obj[i] != me && obj[i]->query("id") != "robber" && target->query("id") != obj[i]->query("id") )
			{
				message_vision(HIY "只见$N应声冲着$n扑了过去！喝道："+RANK_D->query_rude(target)+HIY"拿命来吧！\n" NOR, obj[i], target);
				obj[i]->kill_ob(target);
			}
		}
	}

	if(random(2)==0)
		message_vision( HIR "\n$N对着$n"+HIR"冷笑一声：狗腿子便是全上，俺又有何惧，看招！\n\n" NOR, target,me );
	else message_vision( HIR "\n$N对着$n"+HIR"冷笑一声：想倚多为胜？看招！\n\n" NOR, target,me );
	target->kill_ob(me);

	return 1;
}



int do_open()
{
	object *all, sender, ppl = this_player();
	object obn, obj = this_object();
	int i;

	return 1;
	remove_call_out("destroy_it");
	all = users();
	for(i=0; i<sizeof(all); i++) {
		if( all[i]->query("id") == obj->query("owner") ) sender = all[i];
	}

		  if ( obj->query_temp("prop") == 1 ) {
		switch( random(3) ) {
			case 0:
				obn = new("/clone/money/silver");
				obn->set_amount(20);
				break;
			case 1:
				obn = new("/clone/money/silver");
				break;
								case 2:
				obn = new("/clone/money/silver");
										  break;
		}
		ppl->add("shen", -1 );
	}
	else if ( obj->query_temp("prop") == 2 ) {
					 switch( random(3) ) {
                        case 0:
										  obn = new("/clone/money/silver");
                                obn->set_amount(20);
										  break;
								case 1:
										  obn = new("/clone/money/silver");
										  break;
								case 2:
										  obn = new("/clone/money/silver");
										  break;
					 }
		ppl->add("shen", -1 );
	}
	else if ( obj->query_temp("prop") == 3 ) {
					 switch( random(3) ) {
								case 0:
                                obn = new("/clone/money/silver");
                                obn->set_amount(20);
										  break;
								case 1:
										  obn = new("/clone/money/silver");
                                break;
								case 2:
										  obn = new("/clone/money/silver");
                                break;
                }
		ppl->add("shen", -1 );
        }
		  else if ( obj->query_temp("prop") == 4 ) {
					 switch( random(3) ) {
								case 0:
                                obn = new("/clone/money/silver");
										  obn->set_amount(20);
										  break;
								case 1:
										  obn = new("/clone/money/silver");
                                break;
								case 2:
										  obn = new("/clone/money/silver");
										  break;
					 }
		ppl->add("shen", -1 );
        }
	else if ( obj->query_temp("prop") == 5 ) {
					 switch( random(3) ) {
								case 0:
                                obn = new("/clone/money/silver");
										  obn->set_amount(20);
										  break;
                        case 1:
										  obn = new("/clone/money/silver");
										  break;
                        case 2:
										  obn = new("/clone/money/silver");
										  break;
					 }
		ppl->add("shen", -1 );
		  }
	else if ( obj->query_temp("prop") == 6 ) {
					 switch( random(3) ) {
								case 0:
                                obn = new("/clone/money/silver");
										  obn->set_amount(20);
										  break;
								case 1:
										  obn = new("/clone/money/silver");
                                break;
                        case 2:
                                obn = new("/clone/money/silver");
										  break;
					 }
		ppl->add("shen", -1 );
		  }
	else {
                switch( random(3) ) {
                        case 0:
										  obn = new("/clone/money/silver");
										  obn->set_amount(20);
										  break;
								case 1:
										  obn = new("/clone/money/silver");
										  break;
								case 2:
										  obn = new("/clone/money/silver");
										  break;
					 }
		ppl->add("shen", -1 );
		  }

	obn->move(ppl);
		  tell_object(ppl, "你打开红镖，发现里头装的原来是"+obn->name()+"。\n");

	if ( ppl->query("id") == obj->query("owner") ) {
					 ppl->add("biao_stealer", 1);
					 ppl->delete("biao");
					 CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s监守自盗了红镖！据闻红镖是%s！", ppl->name(), obn->name()));
	}
	else {
		if ( userp(sender) ) {
								sender->delete_temp("apply/short");
								sender->delete_temp("biao");
								sender->set_temp("biao/fail", 1);
					 }
					 CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s洗劫了红镖！据闻红镖是%s！", ppl->name(), obn->name()));
	}

	destruct(obj);

	return 1;
}


int do_drive(string arg)
{
	object env, obj, ob, me = this_player();
	string target_dir, dir, dest, victim;
	mapping exit;
	object here = environment(me),robber = present("robber",here);

	if (!arg) return notify_fail("你要驱赶什么？\n");

	if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("指令错误！\n");


	if ( victim == me->query("id") ) return notify_fail("何必多此一举？\n");

	if( !me->query_temp("riding") )  return notify_fail("你又不在镖车上！怎么赶车？\n");

	if ( victim != "che" && victim != "da che" ) return notify_fail("你要驱赶什么？\n");

	ob = present(victim, environment(me));

	if (!ob) return notify_fail("这里并无此人！\n");

	if ( me->is_busy() ) return notify_fail("你在忙着呢！\n");

	env = environment(me);
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) )
		return notify_fail("无此方向可去！\n");

	dest = exit[dir];

	if( !(obj = find_object(dest)) )
					 call_other(dest, "???");
		  if( !(obj = find_object(dest)) )
					 return notify_fail("无法走！\n");
	if( !wizardp(ob) && obj->query("short") == "巫师休息室" )
		return notify_fail("无法走！\n");

	if( !undefinedp(default_dirs[dir]) )
					 target_dir = default_dirs[dir];
		  else
					 target_dir = dir;

	message_vision( HIG"$N"+HIG"扬了扬鞭子，高声驱赶骡子驾着$n"+HIG"朝"+target_dir+"驶去。\n" , me, ob);

	if( robber && ( robber->query("owner") == me->query("id") || robber->query("owner2") == me->query("id"))  )
	{
		message_vision( HIR"$N喝道：想溜？没门！\n"NOR,robber);
		return 1;
	}

	if( ob->query("owner") != me->query("id") && ob->query("owner2") != me->query("id") )
	{
		message_vision( HIW"可是骡子理都不理$N。\n" NOR,me);
		return 1;
	}

	message("vision", HIY "只见"+ob->name()+HIY"轰隆隆沉重的向"+target_dir+"驶过去。\n" NOR, environment(ob), ({ob}));

	if( ob->move(obj) ) {
			message( "vision", HIY "只见一辆"+ob->name()+HIY"轰隆隆沉重的驶了过来。\n" NOR, environment(ob), ({ob}));
			all_inventory(env)->follow_me(this_object(), dir);
			me->start_busy( 2 + random(4) );
			return 1;
	}

	return 1;
}


