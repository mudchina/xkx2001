//Cracked by Roath
// /clone/npc/obj/xbiaoche.c 镖车
// sdong,12/05/98 created
// Modified by xQin 11/00 - prevent players from using "object id" bug to escape busy time

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
int do_rob();
void host_appear();
void destroy_cart(object cart);
void greeting(object ob);
void destroy_it(object ob);
void do_leave(object ob);
void robber_rob(object me);

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
	add_action("do_rob", "jiebiao");
	add_action("do_drive", "gan");
	add_action("do_drive", "g");
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
	if(sO) owner = present( sO,here);
	if( !owner || owner != ob )
	{
		sO = query("owner2");
		if(sO)
		 owner = present( sO,here);
	}
	if( !owner || owner != ob) return;
	if( !owner && here && (robber = present("robber",here)) )
	{
		robber->command("jiebiao");
	}
	else if( query_temp("xbiao/dest2") && here && (base_name(here) == query_temp("xbiao/dest2") )&& owner && userp( owner ) )
	{
		message_vision(HIG"\n$N"+HIG"累得半死，总算赶到目的地！\n\n",owner);

		if( (target = present( query_temp("xbiao/dest"),here)  ) )
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
	else if( query_temp("xbiao/dest") && here && (target = present( query_temp("xbiao/dest"),here)  ) )
	{
			message_vision("$N急急忙忙离开了！\n",target);
			target->move( query_temp("xbiao/dest2")+".c" );
			message_vision("$N急急忙忙走了过来！\n",target);
	}
}

void host_appear()
{
	object target;
	string host = query_temp("xbiao/dest");

	if(!host) return;

	target = find_object( host );
	if(!target)target = find_player(host);
	if(!target )target = find_living(host);

	if( !target )
	{
		seteuid(geteuid());
		if ( query_temp("xbiao/dest") == "dao baifeng" ) target = new ("/kungfu/class/dali/daobaifeng.c");
		else if ( query_temp("xbiao/dest") == "hu laoye" ) target = new ("/d/xingxiu/npc/bayi.c");
		else if ( query_temp("xbiao/dest") == "ye erniang" ) target = new ("/kungfu/class/xixia/ye.c");
		else if ( query_temp("xbiao/dest") == "feng yiming" ) target = new ("/d/foshan/npc/yiming.c");
		else if ( query_temp("xbiao/dest") == "wang tongzhi" ) target = new ("/d/quanzhou/npc/wang.c");
	}
	else
	{
		if( target && environment( target) )
			message_vision("$N急急忙忙离开了！\n",target);
	}

	if(target)
	{
		target->move( query_temp("xbiao/dest2")+".c" );
		message_vision("$N急急忙忙走了过来！\n",target);
	}

}

void award2(object dest,object owner)
{
	object wage;
	object here = environment(dest);
	int nGold;

	if( userp(owner) && owner->query("xbiao/dest2") )
	{
		nGold = 2 + random(2+owner->query("combat_exp")/100000);
		if (MONEY_D->player_job_pay(owner, dest, nGold * 10000))
		message_vision(HIY"$N"+HIY"递给$n几锭黄金，说：“一点小意思，"+RANK_D->query_respect(owner)+"请笑纳！”\n"NOR,dest,owner);
		owner->delete("xbiao/dest");
		owner->delete("xbiao/dest2");
		owner->delete_temp("riding");
		owner->set("xbiao/bonus",660+random(500) );
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
		remove_call_out("killer_show");
		remove_call_out("auto_check");
		if( owner->query_condition("biaoju") )
			owner->clear_one_condition("biaoju");

		obj = all_inventory(here);

		 for(i=0;i<sizeof(obj);i++)
		{
			if( living(obj[i]) && ( obj[i]->query_temp("xbiao/owner") == owner->query("id")
				|| obj[i]->query_temp("xbiao/owner2") == owner->query("id") )
			 && obj[i] != owner )
			{
				call_out("destroy_cart",2,obj[i]);
			}
			if( obj[i]->query("id") == "robber" && !userp(obj[i]) )
				do_leave(obj[i]);
		}

		call_out("destroy_cart",5,cart);
	}
}

void destroy_cart(object cart)
{
	if( !objectp(cart) ) return;
	if( cart->query("race") != "人类" )
		message_vision("仆人上前把$N拉走了。\n",cart);
	else message_vision("丫环上前把$N请进去了。\n",cart);

	destruct(cart);
}

void set_owner(object owner,object owner2)
{
	object ob = this_object();//present("xbiao che",environment());
	set("owner",owner->query("id"));
	if(owner2)
		set("owner2",owner2->query("id"));
	set_temp("xbiao/dest",owner->query("xbiao/dest") );
	set_temp("xbiao/dest2",owner->query("xbiao/dest2") );

	call_out("destroy_it", 1200,ob);
}



int do_ride(string arg)
{
	object me = this_player();
	object cart = this_object();


	if (!arg) return notify_fail("你要上什么？\n");

	if( me->query_temp("riding") )  return notify_fail("你已经在镖车上！\n");

	if( cart = present("biao che",environment()) );

	if( query("owner") != me->query("id") && query("owner2") != me->query("id")) return notify_fail("不是你的车。\n");

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
	if( !me ) return;
	here = environment(me);
	if(!here) return;
	call_out("auto_check", 45+random(30) );
	
		if( !(owner = find_player(query("owner")) ) &&  query("owner2") && !(owner = find_player(query("owner2")) ) )
		{
			call_out("auto_check", 1+random(3) );
			call_out( "destroy_it",5, me );
			return 1;
		}

	if( !owner || !owner->query("xbiao/dest2") )
	  {
			call_out( "destroy_me",1, me );
			return;
	  }

	if( strsrch(base_name(here), "/d/city") == -1 &&
		strsrch(base_name(here), "/d/") != -1 &&
		strsrch(base_name(here), "duchuan") == -1   )
	{
				call_out( "killer_show",1+random(5),owner );
				if( query("owner2") && query("owner2") != query("owner") )
				{
					owner = find_player( query("owner2") );
					if( owner && random(3) ==0 ) call_out( "killer_show",1+random(5),owner );
				}
	}

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


void run_away()
{
	object obj, ob=this_object(), me,partner;
	object here = environment(ob);
	string *dirs,dir,dest,target_dir;
	mapping exit;

	if(!ob) return;
	if(!here || !objectp(here) ) return;

	if(random(16) != 0) call_out("run_away",0);

	exit = here->query("exits");
	if( !exit ) return;
	dirs = keys(exit);
	dir = dirs[random(sizeof(dirs))];
	if(!dir) return;
	dest = exit[dir];
	if( !dest ) return;

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return;
	if( !wizardp(ob) && obj->query("short") == "巫师休息室" )
		return;
	if( obj->query("short") == "大沙漠" || obj->query("short") == "沙漠" || obj->query("short") == "茶亭" )
		return;

	if( !undefinedp(default_dirs[dir]) )
					 target_dir = default_dirs[dir];
		  else
					 target_dir = dir;

	message( "vision", HIY"骡子受惊，四蹄发力，疯狂地拉了镖车就跑。\n"NOR,environment(ob), ({ob}));

	if( ob->move(obj) ) {
			message( "vision", HIY "只见一辆"
				+ob->name()+HIY"轰隆隆沉重的驶了过来。\n" NOR, environment(ob), ({ob}));

			if( ob->query("owner") )
			{
				if( (me = present( ob->query("owner"),here )) && me->query_temp("riding") )
				{
					me->move(obj);
					all_inventory(here)->follow_me(me,dir);
				}
			}

			if( ob->query("owner2") )
			{
				 if( (partner = present( ob->query("owner2"),here )) && partner->query_temp("riding") )
				 {
					partner->move(obj);
					all_inventory(here)->follow_me(partner,dir);
				 }
			}
	}
}

void action(object me, object ob)
{
	object here = environment();

	if( !ob || !objectp(ob) ) return;

	if( !environment(ob) || environment(ob) != here)
	{
		call_out("do_leave",30, ob);
		return;
	}

	call_out("action",random(10),me,ob);

	if( !(me=present( query("owner"), here ) ) )
	{
		if( query("owner2") )
		{
		  if( !(me=present( query("owner2"), here )) )
			{
				if( here == environment(ob) )
				{
					robber_rob(ob);
					return;
				}
			}
		} else
		{
			if( here == environment(ob) )
			{
				 robber_rob(ob);
				 return;
			}
		}
	}

	if( !living(ob) )
	{
		 call_out("do_leave",1,ob);
		 return;
	}

	if( !ob->is_busy() && !ob->is_fighting() )
	{
	  if( random(3) ) message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(ob)+"我正好缺几个钱花。相好的，识趣点交出宝贝，就饶你一条全尸！\n"NOR, ob);
	  else if( random(3) )  message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(ob)+"我替天行道，劫富济贫，狗腿子，识趣点交出宝贝，就饶你不死！\n"NOR, ob);
	  else message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(ob)+"听说什么屁鹰镖局的为虎作伥，狗腿子，识趣点早点滚蛋，就饶你不死！\n"NOR, ob);
	  ob->kill_ob(me);
	}

	if( random(200) == 1 )
	{
	  message_vision(HIR"\n$N"+HIR"突然飞起一脚，向骡子踢去，结果正好踢在骡子的屁股上。\n"NOR, ob);
	  call_out("run_away",0);
	}
}

void robber_rob(object me)
{
	object here, target;

	if(random(3)) message_vision(HIR"\n$N"+HIR"喝道：此树是我栽，此路是我开，要从此处过，留下买路钱。相好的，识趣点交出宝贝，就饶你一条狗命！\n"NOR, me);
	else if( random(3) ) message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我正好缺几个钱花。相好的，赶快交出宝贝受死，就饶你一条全尸！\n"NOR, me);
	else message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我替天行道，劫富济贫，狗腿子，识趣点交出宝贝，就饶你不死！\n"NOR, me);

	target = find_player( query("owner") );
	remove_call_out("destroy_it");
	message_vision(HIY"$N打开镖车，取出一大包镖货。\n",me);
	if(target)
	{
			 target->remove_all_killer();
			 target->remove_enemy(me);
			 CHANNEL_D->do_channel(this_object(), "rumor","听说"+me->name()+"洗劫了"+target->name()+"的镖车！" );
			 target->delete("biao");
			 target->set("biao/fail");
	}
	else
	 CHANNEL_D->do_channel(this_object(), "rumor","听说"+me->name()+"洗劫了"+ query("owner")+"的镖车！" );

  call_out("do_leave",1,me);
  call_out("destroy_me",3,this_object() );
  return ;
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
					 "ning zhongze",
					 "sun buer",
					 "huang yaoshi",
					 "hong qigong",
					 "lin zhennan",
					 "biao shi",
					 "master",
					 "feng qingyang",
                "mao zei",
		"miejue shitai",
		  });

		  if(  !victim || !clonep(victim) || !living(victim) || userp(victim)
			|| victim->query("race") != "人类"
			|| victim->query("shen") <= 0
			|| victim->query("winner")
			|| strsrch(base_name(victim), "/kungfu/skill/") != -1
			|| strsrch(base_name(victim), "/kungfu/class/huashan") != -1
			|| strsrch(base_name(victim), "/clone/") != -1
			|| strsrch(base_name(victim), "/u/") != -1
			|| strsrch(base_name(victim), "/d/xiakedao/") != -1
			|| victim->query("combat_exp") < killer->query("combat_exp") * 1/10
			|| victim->query("combat_exp") > killer->query("combat_exp")*7/4
			|| victim->query("family/family_name") == killer->query("family/family_name")
			|| victim->query("family/family_name") == "桃花岛"
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

	if(!objectp(me) || !objectp(obj) ) return;

	if( obj->query("combat_exp") < me->query("combat_exp") )
	{
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(100) )  );
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
	else if( obj->query("combat_exp") < 2000000)
	{
		level = level/2 + random(level/2);
	}
	else
		level = level/2 + random(level*3/4);

	if( me->query("family/family_name") == "峨嵋派" ) // their qi short, so lower robber's skill a bit
	{
		level = level*9/10 ;
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
	obj->set_temp("xbiao/dest",me->query("xbiao/dest"));

	if( query("owner2") )
		obj->set("owner2",query("owner2"));

	call_out("do_leave",20+random(15),obj);

}

void killer_show(object me)
{
  object ob,here,owner;
  object *target_list;
  int i;

  if( !me || !( here = environment() ) || strsrch(base_name(here), "/d/") == -1 || here->query("no_fight") )
  {
		if( query("owner2") )
		{
			owner = find_player( query("owner2") );
			if( owner ) call_out( "killer_show",1,owner );
		}
		return;
 }

  if( !me->query("xbiao/dest2") )
  {
		call_out( "destroy_me",1, this_object() );
		return;
  }

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

  if( random(3) == 1)
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

	if( me->query("xbiao/dest") )
	{
		for(i=0;i<sizeof(obj);i++)
		{
			if( living(obj[i]) &&
				(	obj[i]->query("xbiao/dest") == me->query("xbiao/dest")
					|| obj[i]->query_temp("xbiao/owner") == me->query("id")
					|| obj[i]->query_temp("xbiao/owner2") == me->query("id")
				)  && obj[i] != me && obj[i]->query("id") != "robber" && target->query("id") != obj[i]->query("id") )
			{
				if( obj[i]->query("combat_exp") < target->query("combat_exp") )
				{
					message_vision(HIY "只见$N应声冲着$n扑了过去！喝道："+RANK_D->query_rude(target)+HIY"拿命来吧！\n" NOR, obj[i], target);
					obj[i]->kill_ob(target);
				}
				else
				{
					message_vision(HIG "只见$N对着$n不屑地哼了一声：这个不知天高地厚的"+RANK_D->query_rude(target)+HIG"就交给你们去收拾了！\n" NOR, obj[i], target);
				}
			}
		}
	}
	if( living(target) )
	{
		if(random(2)==0)
			message_vision( HIR "\n$N对着$n"+HIR"冷笑一声：狗腿子便是全上，俺又有何惧，看招！\n\n" NOR, target,me );
		else message_vision( HIR "\n$N对着$n"+HIR"冷笑一声：想倚多为胜？看招！\n\n" NOR, target,me );
		target->kill_ob(me);
	}

	return 1;
}


int do_check()
{
	object ppl = this_player();
	object obj = this_object();

	if ( obj->query_temp("xbiao/dest") == "dao baifeng" ) write("这是由"+obj->query("owner")+"压运的大理王妃刀白凤的镖货。\n");
	else if ( obj->query_temp("xbiao/dest") == "hu laoye" ) write("这是由"+obj->query("owner")+"压运的北疆小镇巴依托送的重镖，要尽快送到。\n");
	else if ( obj->query_temp("xbiao/dest") == "ye erniang" ) write("这是西夏叶二娘托送的重镖，由"+obj->query("owner")+"压运，要尽快送到。\n");
	else if ( obj->query_temp("xbiao/dest") == "feng yiming" ) write("这是佛山英雄会馆凤一鸣的重镖，由"+obj->query("owner")+"压运。\n");
	else if ( obj->query_temp("xbiao/dest") == "wang tongzhi" ) write("这是泉州济世堂老店的重镖，由"+obj->query("owner")+"压运，务必交到药铺掌柜王通治手里。\n");

	return 1;
}

void destroy_it( object obj)
{
	object ppl;
	if(!objectp(obj)) return;

	remove_call_out("killer_show");
	remove_call_out("auto_check");

	if( !obj->query("owner") ) return;
	ppl = find_player( obj->query("owner") );
	if( userp(ppl) )
	{
		ppl->delete_temp("apply/short");
		ppl->delete("xbiao");
		ppl->set("xbiao/fail", 1);
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

void destroy_me(object me)
{
  remove_call_out("killer_show");
  remove_call_out("auto_check");
  destruct(me);
}


int do_rob()
{
	object here, *obj, me = this_player(),target,xbiaohuo;
	int i,bGuarded = 0;

	here = environment(me);

	if(!here) return 1;

	if( !me->query("biao/owner") ||
		( me->query("biao/owner")!= query("owner") && me->query("biao/owner") != query("owner2") ||
		  query_temp("xbiao/dest") != me->query("biao/dest")
		)
	)
		return notify_fail("没事乱劫镖？担心你的小命！\n");

	obj = all_inventory(here);

	if( random(3) ) message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我正好缺几个钱花。相好的，识趣点交出宝贝，就饶你一条全尸！\n"NOR, me);
	else if( random(3) )  message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我替天行道，劫富济贫，狗腿子，识趣点交出宝贝，就饶你不死！\n"NOR, me);
	else message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"听说什么屁鹰镖局的为虎作伥，狗腿子，识趣点早点滚蛋，就饶你不死！\n"NOR, me);

	 for(i=0;i<sizeof(obj);i++)
	 {
			if( living(obj[i]) &&
					(	obj[i]->query("id") == me->query("biao/owner")
						|| ( query("owner2") && obj[i] == present( query("owner2"), here ) )
						|| obj[i]->query_temp("xbiao/owner") == me->query("biao/owner")
						|| obj[i]->query_temp("xbiao/owner2") == me->query("biao/owner")
					)  && obj[i] != me && obj[i]->query("id") != "robber"
				)
			{
				obj[i]->kill_ob(me);
				me->kill_ob(obj[i]);
				bGuarded = 1;
			}
	 }

	 target = find_player(me->query("biao/owner"));

	 if( !bGuarded )
	 {
		 remove_call_out("destroy_it");
		 xbiaohuo = new ("/clone/npc/obj/biaohuo.c");
		 if(xbiaohuo)xbiaohuo->move(me);
		 message_vision(HIY"$N打开镖车，取出一大包镖货。\n",me);
		 xbiaohuo->set("owner",me->query("id"));
		 me->remove_all_killer();
		 me->delete("biao/owner");
		 if(target)
		 {
			 me->remove_enemy(target);
			 target->remove_all_killer();
			 target->remove_enemy(me);
			 CHANNEL_D->do_channel(this_object(), "rumor","听说"+me->name()+"洗劫了"+target->name()+"的镖车！" );
			 target->delete("xbiao");
			 target->set("xbiao/fail");
		 }
		 else
			 CHANNEL_D->do_channel(this_object(), "rumor","听说"+me->name()+"洗劫了"+me->query("biao/owner")+"的镖车！" );
		 call_out("destroy_me",1,this_object() );
	 }

	return 1;
}


int do_drive(string arg)
{
	object env, obj, ob, me = this_player(), partner;
	string target_dir, dir, dest, victim;
	mapping exit;
	object here = environment(me),robber = present("robber",here);
	int busy_time;

	if (!arg) return notify_fail("你要驱赶什么？\n");
	if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("指令错误！\n");
	if ( victim == me->query("id") ) return notify_fail("何必多此一举？\n");
	if( !me->query_temp("riding") )  return notify_fail("你又不在镖车上！怎么赶车？\n");
	if ( victim != "che" && victim != "da che" ) return notify_fail("你要驱赶什么？\n");
	ob = present(victim, environment(me));
	if (!ob) return notify_fail("这里并无此人！\n");
	if ( me->is_busy() ) return notify_fail("你在忙着呢！\n");
	env = environment(me);
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) return notify_fail("无此方向可去！\n");
	dest = exit[dir];
	if( !(obj = find_object(dest)) ) call_other(dest, "???");
	if( !(obj = find_object(dest)) ) return notify_fail("无法走！\n");
	if( !wizardp(ob) && obj->query("short") == "巫师休息室" ) return notify_fail("无法走！\n");
	if( !undefinedp(default_dirs[dir]) ) target_dir = default_dirs[dir];
	else target_dir = dir;
	message_vision( HIG"$N"+HIG"扬了扬鞭子，高声驱赶骡子驾着$n"+HIG"朝"+target_dir+"驶去。\n" , me, ob);
	if( robber && ( robber->query("owner") == me->query("id") || robber->query("owner2") == me->query("id")) )
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
	if( ob->move(obj) )
	{
		message( "vision", HIY "只见一辆"+ob->name()+HIY"轰隆隆沉重的驶了过来。\n" NOR, environment(ob), ({ob}));
		busy_time = 4 + random(4);
		if( ob->query("owner") )
		{
			if( (me = present( ob->query("owner"),env )) && me->query_temp("riding") )
			{
				message_vision( HIG"$N坐在镖车上向"+target_dir+"驶过去。\n" NOR,me);
				me->move(obj);
				message_vision( HIG"$N坐在镖车上驶过来。\n" NOR,me);
				all_inventory(env)->follow_me(me,dir);
				me->start_busy( busy_time );
			}
			else if ((me = present( ob->query("owner"),environment(ob)))) me->start_busy( busy_time );
		}
		if( ob->query("owner2") )
		{
			if( (partner = present( ob->query("owner2"),env )) && partner->query_temp("riding") )
			{
				message_vision( HIG"$N坐在镖车上向"+target_dir+"驶过去。\n" NOR,partner);
				partner->move(obj);
				message_vision( HIG"$N坐在镖车上驶过来。\n" NOR,partner);
				partner->start_busy( busy_time );
				all_inventory(env)->follow_me(partner,dir);
			}
			else if ((partner = present( ob->query("owner2"),environment(ob))))
			{
				if (ob->query("owner2") && ob->query("race") == "人类" )
				{
					partner->start_busy( busy_time );
				}
			}
		}
	}
	return 1;
}

