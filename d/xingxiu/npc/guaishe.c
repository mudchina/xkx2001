//Cracked by Roath
//lingshe 西域怪蛇
//sdong, 11/19/98

#include <ansi.h>
#include <room.h>
inherit NPC;

mapping default_dirs = ([
	"north":	"北",
	"south":	"南",
	"east":		"东",
	"west":		"西",
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
	"up":		"上",
	"down":		"下",
	"out":		"外",
	"enter":	"里",
]);

void set_owner(object owner);
int do_drive(string arg);
int do_yao(string arg);
int do_stop(string arg);
int random_walk();
int auto_check();
int auto_perform();
void killer_show(object me);
private int is_suitable(object victim, object killer);
void action(object me, object ob);
void setup_skill(object me,object obj);
string long_desc();

void create()
{
	int max,max1;

		set_name("怪蛇", ({ "guai she", "she", "snake" }) );
		set_color("$HIW$");
		set("race", "蛇类");
		set("unit", "条");
		set("age", 29);
		set("long", (: long_desc :));
		set("attitude", "peaceful");

		set("auto_follow",0);
		set("wildness", 90);

		set("str", 30);
		set("cor", 30);
		set("dex", 45);

		set("combat_exp", 100000);

		set_temp("apply/attack", 65);
		set_temp("apply/damage", 56);
		set_temp("apply/armor", 150);

		set_skill("dodge", 10);
		set_skill("parry", 10);
		set_skill("force", 10);

		setup();

	  set("chat_chance_combat", 50);
	  set("chat_msg_combat", ({
		 (: auto_perform :),
	  }));

	  set("chat_chance", 3);
	  set("chat_msg",({
		 (: auto_check :),
	  }));
}

string long_desc()
{
		string desc ;
		object snake = this_object();

		desc = HIW"一条全身银鳞的小蛇，是西域欧阳峰用几十种最毒的蛇杂交培育出来的，奇毒无比，它正伸出血红的毒舌盯住你。\n"NOR;

		if( snake->query("food") < 50 )
			 desc += RED"它看起来胃瘪瘪的，恐怕饿得正慌。\n"NOR;
		else if( snake->query("food") < 100 )
			 desc += "它看起来不是很有精神，恐怕有点饿。\n";
		else if( snake->query("food") < 150 )
			 desc += "它看起来满活泼的，看来是半饱了。\n";
		else if( snake->query("food") < 200 )
			 desc += "它看起来胃鼓鼓的，看来是快饱了。\n";
		else
			 desc += HIY"它看起来胃鼓鼓的，似乎吃的太饱撑得简直快要爆炸了。\n"NOR;

		return desc;
}

int auto_check()
{
	object me = this_object();
	object here;
	if( !me )return;
	here = environment(me);
	if(!here) return;
	remove_call_out("auto_check");
	call_out("auto_check",3);


	if( !is_busy() && strsrch(base_name(here), "/d/") != -1   )
	{

	  if( random(10)==1 )
			random_walk();
	  else if( random(5)==1 )
	  {
				remove_call_out("killer_show");
				call_out( "killer_show",3+random(15),me );
	  }
	}

}


void init()
{
		object ob,me = this_object();

		if( me->query("id") != "guai she" )
			me = present( "guai she",environment(this_player()) ) ;

		add_action("convert","convert");
		add_action("do_drive","gan");
		add_action("do_yao","attack");
		add_action("do_stop","stop");


		if( interactive(ob = this_player()) &&
				ob->query("family/family_name") != "白驼山" &&
				random(ob->query_kar() + ob->query_per()) < 30 &&
				ob->query("combat_exp") > me->query("combat_exp") * 9/10 )
		{
				remove_call_out("kill_ob");
				call_out("kill_ob", 1, ob);
		}

	remove_call_out("auto_check");
	call_out("auto_check",3);
}

void set_owner(object owner)
{
	int max, max1;
	object me = this_object();
	if(!owner)return;
	set( "owner",owner->query("id") );
	set( "combat_exp",owner->query("combat_exp") );
	set( "max_qi", owner->query("max_qi")*3);
	set( "qi", owner->query("max_qi")*3);
	set( "eff_qi", owner->query("max_qi")*3);
	set( "max_jingli", owner->query("max_jingli"));
	set( "jingli", owner->query("max_jingli"));
	set( "eff_jingli", owner->query("eff_jingli"));
	set( "eff_jing", owner->query("eff_jing"));
	set( "jing", owner->query("jing"));
	set( "max_jing", owner->query("max_jing"));
	set( "max_neili", owner->query("max_neili"));
	set( "neili", owner->query("max_neili"));

	max = pow( query("combat_exp")*10.,0.33333);
	max1 = (int)max;
	set_skill("dodge", max1);
	set_skill("parry", max1 );
	set_skill("force", max1);
	set_skill("claw", max1);
	set_skill("force", max);
	set_skill("hamagong", max);
	map_skill("force", "hamagong");

	if( owner->query("combat_exp") < 4000)
	{
		set_temp("apply/attack", 35);
		set_temp("apply/damage", 15);
		set_temp("apply/armor", 100);
	}
	else if( owner->query("combat_exp") < 30000)
	{
		set_temp("apply/attack", 45);
		set_temp("apply/damage", 26);
		set_temp("apply/armor", 100);
	}
	else if( owner->query("combat_exp") < 60000)
	{
		set_temp("apply/attack", 45);
		set_temp("apply/damage", 36);
		set_temp("apply/armor", 120);
	}
	else if( owner->query("combat_exp") < 300000)
	{
		set_temp("apply/attack", 55);
		set_temp("apply/damage", 46);
		set_temp("apply/armor", 130);
	}
	else
	{
		set_temp("apply/attack", 65);
		set_temp("apply/damage", 55);
		set_temp("apply/armor", 150);
	}
}

void do_leave(object ob)
{
		if( objectp(ob) )
		{
			if( ob->is_busy() || ob->is_fighting())
			{
				message_vision("$N向后一跳，跳出战圈！\n",ob);
				if(present("guai she",environment(ob)))
				message_vision("$N说道：没想到老毒物的宝贝玩意还真有两下子。"+RANK_D->query_self(ob)+"改日再来奉陪！\n",ob);
				else message_vision("$N说道：哈蛤，老毒物的宝贝玩意到底不是"+RANK_D->query_self(ob)+"的对手！\n",ob);
			}
			if(!living(ob))ob->revive(0);
			message_vision("$N急急忙忙离开了。\n",ob);
			destruct(ob);
		}
}

void action(object me, object ob)
{
	object owner, here = environment(me);
	if( !me || !ob || !present(ob->query("id"),here) )
	{
		do_leave(ob);
		return;
	}

	if( me->is_busy() || ob->is_busy() || ob->is_fighting() || me->is_fighting() || !living(me) || !living(ob) )
	{
		 call_out("action",random(10),me,ob);
		 return;
	}

	if( random(8) == 0 )
	{
		message_vision("\n$N"+HIR"突然一口向$n咬去!\n"NOR, me,ob);
		me->kill_ob(ob);
	}
	else if( random(6) !=0 && (owner = present(me->query("owner"),here) )  )
	{

		message_vision(HIR"\n$N"+HIR"喝道：老毒物的弟子驱蛇伤人无数，今天"+RANK_D->query_self(ob)+"特来送你们上西天！\n"NOR, ob);
		ob->kill_ob(me);
		ob->kill_ob(owner);
	}
	else if( random(2)==0 )
	{
		message_vision(HIR"\n$N"+HIR"突然向$n"+HIR"发动进攻!\n"NOR, ob,me);
		ob->kill_ob(me);
	}
	else
	{
		message_vision(HIR"\n$N"+HIR"喝道：老毒物的怪蛇害人无数，今天"+RANK_D->query_self(ob)+"誓为民除害！\n"NOR, ob);
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
					 "yue buqun",
					 "qiu chuji",
					 "gao lao",
					 "ai lao",
					 "hong qigong",
					 "zhang sanfeng",
					 "zuo lengchan",
					 "ouyang zhan",
					 "seng bing",
					 "huang yaoshi",
					 "yideng dashi",
					 "ma guangzuo",
					 "black gargoyle",
					 "white gargoyle",
					 "tang nan",
					 "lao chaofeng",
		});

		if(  !clonep(victim) || userp(victim)
			|| victim->query("race") != "人类"
			|| victim->query("shen") < 0
			|| victim->query("winner")
			|| strsrch(base_name(victim), "/kungfu/skill/") != -1
			|| strsrch(base_name(victim), "/kunfu/class/huashan") != -1
			|| strsrch(base_name(victim), "/clone/") != -1
			|| strsrch(base_name(victim), "/u/") != -1
			|| strsrch(base_name(victim), "/d/xiakedao/") != -1
			|| strsrch(base_name(victim), "/d/city/") != -1
			|| strsrch(base_name(victim), "/d/bwdh/") != -1
			|| victim->query("combat_exp") < killer->query("combat_exp") * 1/12
			|| victim->query("combat_exp") > killer->query("combat_exp")*7/3
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
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 120+random(80) )  );
	}

	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;

	if( obj->query("combat_exp") < 4000 )
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 30000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 60000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 300000)
	{
		level = level/2 + random(level/4);
	}
	else
		level = level/2 + random(level/5);

	skills = obj->query_skills();
	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
	  obj->set_skill(names[i], level);
	}

	call_out("do_leave",60+random(60),obj);

}

void killer_show(object me)
{
	object ob, here, shegu;
	object *target_list;
	int i;

	if( !me ) return;
	here = environment(me);
	shegu = load_object("/d/baituo/shegu1");

	if(!here)return;
	if( strsrch(base_name(here), "/d/") == -1 ) return;

	if( here->query("shegu") && shegu->query("defense") ) return;

	if ( query("food") >= 200 )return;

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
		if(present(base_name(target_list[i]) + ".c",environment(this_object())))continue;
		ob=new( base_name(target_list[i]) + ".c" );
	}
	while( !objectp(ob) );

	ob->move(here);
	ob->set("snake_killer", 1);
	setup_skill(me,ob);
	message_vision("\n$N快步走了过来！\n", ob);

	call_out("action",random(10),me,ob);

	if( random(3) == 1)
	{
		remove_call_out("killer_show");
		call_out( "killer_show",30+random(15),me );
	}
}

int do_drive(string arg)
{
	object env, obj, ob, me = this_player();
	string target_dir, dir, dest, victim;
	mapping exit;

	if (!arg) return notify_fail("你要驱赶什么？\n");

	if( sscanf(arg, "%s %s", victim, dir) != 2 )
		return notify_fail("指令错误！\n");

	if ( victim == me->query("id") )
		return notify_fail("何必多此一举？\n");

	if ( victim != "snake" && victim != "guai she" && victim != "she" )
		return notify_fail("你要驱赶什么？\n");

	ob = present(victim, environment(me));

	if (!ob) return notify_fail("这里并无此人！\n");
	if (!living(ob)) return notify_fail("这不是活物！\n");


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

	if ( present("shezhang",me) || present("guai shezhang",me))
		message_vision(HIR "$N用蛇杖驱赶$n朝"+target_dir+"走去。\n" NOR, me, ob);
	else
		message_vision( "$N用手势驱赶$n朝"+target_dir+"走去。\n" , me, ob);


	if ( ob->query("owner") != me->query("id")  )
	{
		message_vision( "可是$N理都不理。\n" NOR, ob);
		return 1;
	}

	if( random(20) != 0)
	{
		message("vision", HIR "只见"+ob->name()+"乖乖的向"+target_dir+"游过去。\n" NOR, environment(ob), ({ob}));

		if( ob->move(obj) ) {
			message( "vision", HIR "只见"+ob->name()+"游了过来。\n" NOR, environment(ob), ({ob}));
			return 1;
		}
	}
	else
		message_vision( "可是$N理都不理。\n" NOR, ob);

	return 1;
}

int do_yao(string arg)
{
	object env, obj, ob, me = this_player(),snake;
	string target_dir, dir, dest, victim;
	mapping exit;

	if (!arg) return notify_fail("你要驱赶什么？\n");

	victim = arg;

	if ( victim == me->query("id") ) return notify_fail("怪蛇疑惑地看着你。\n");

	ob = present(victim, environment(me));
	snake = present("guai she",environment(me));

	if (!ob) return notify_fail("这里并无此人！\n");



	if ( present("shezhang",me) || present("guai shezhang",me))
		message_vision(HIR "$N用蛇杖驱赶蛇朝$n咬去。\n" NOR, me, ob);
	else
		message_vision( "$N用手指了指蛇，又朝$n指去。\n" , me, ob);

//	if (!living(ob)) return notify_fail("这不是活物！\n");



	if ( query("owner") != me->query("id") || ob->query("race") != "人类" || ob->query("id")=="guai she" )
	{
		message_vision( "可是$N理都不理。\n" NOR, snake );
		return 1;
	}

	if ( query("food") >= 200 )
	{
		message_vision( "可是$N吃得太饱了，理都不理。\n" NOR, snake );
		return 1;
	}

	if( ob->query("combat_exp") < me->query("combat_exp")*4/5 )
		return notify_fail("怪蛇只对武功高手感兴趣！\n");



	if( random(20) != 0)
	{
		message_vision( HIR "只见$N"+HIW"闪电般的向$n扑击过去。\n" NOR, snake, ob );
		snake->kill_ob(ob);
		if(random(4)!=0 && living(ob) )
		{
			message_vision( HIR "$N对着$n"+HIR"冷笑一声："+RANK_D->query_rude(me)+HIR"居然敢纵蛇伤我，看招！\n" NOR, ob,me );
			ob->kill_ob(me);
		}
	}
	else
		message_vision( "可是$N理都不理。\n" NOR, snake);

	return 1;
}

int do_stop(string arg)
{
	object env, obj, ob, me = this_player();
	string target_dir, dir, dest, victim;
	mapping exit;

	if (!arg) return notify_fail("你要驱赶什么？\n");

	victim = arg;


	ob = present(victim, environment(me));

	if (!ob) return notify_fail("这里并无此物！\n");

	if ( present("shezhang",me) || present("guai shezhang",me))
		message_vision(HIR "$N用蛇杖示意$n停下来。\n" NOR, me,ob);
	else
		message_vision( "$N用手指示意$n停下来。\n" , me, ob);

	if ( ob->query("owner") != me->query("id") )
	{
		message_vision( "可是$N理都不理。\n" NOR, ob);
		return 1;
	}


	if( random(20) != 0)
	{
		message("vision", HIR "只见$N乖乖地缩回来，不咬了。\n" NOR, ob );
		ob->remove_all_killer();
	}
	else
		message_vision( "可是$N理都不理。\n" NOR, ob);

	return 1;
}

int convert(string arg)
{
	object me = this_player();
	object target;
	object ob,snake = present("guai she",environment(me));

	if (arg != "guai she" && arg != "she" && arg != "snake" || !snake ) return 0;
	if (me->query("family/family_name") != "白驼山")
		return notify_fail("你不能化蛇为杖。\n");

	if( !(ob=present("guai shezhang",me)) ) return notify_fail("蛇杖在哪儿？\n");

	if(me->query("jingli")<50)return notify_fail("你实在太累了。\n");

	message_vision("$N左手持怪蛇杖伸到$n面前，右手对着$n做着奇怪的手势，口中念念有词。\n",
		me,snake);

	me->add("jingli",-20);

	if( snake->query("food") < 200 )
		return notify_fail("怪蛇还没喂饱，不肯进蛇杖。\n");

	if( ob->query("snake") >=2 )return notify_fail("蛇杖上已有两条蛇了，怪蛇挤不上去！\n");

	message_vision(HIW"$N看了看$n，突然似箭一般跃起，准确地落在蛇杖上，盘了起来。\n"NOR,
		snake,me);

	ob->add("poison_applied", me->query_skill("poison",1)/2);
	ob->add("snake",1);

	target = snake->select_opponent();
	if( target && target->query("snake_killer") ) do_leave(target);
	destruct(snake);

	return 1;
}

int random_walk()
{
		mapping exits, doors;
		string *dirs, dir, last_room, this_room;
		object there,here = environment(),snake=this_object();
		object env, ob, me = this_player();
		string dest, victim;
		mapping exit;


		if( !objectp(here) || !mapp(exits = here->query("exits")) )
		{
			if(snake)
			{
				if(!living(snake))snake->revive(0);
					message_vision("$N在地上找了一个缝钻了进去，不见了。\n",snake);
					destruct(snake);
			}
			return 0;
		}

		//if( is_fighting() || is_busy() || query("jingli") < query("max_jingli") / 2 )return 0;

		dirs = keys(exits);

		if( mapp(doors = here->query_doors()) ) {
			 dirs += keys(doors);
		}

		if( sizeof(dirs) == 0 )
		{
			if(snake)
			{
				if(!living(snake))snake->revive(0);
					message_vision("$N在地上找了一个缝钻了进去，不见了。\n",snake);
					destruct(snake);
			}
			return 0;
		}

		dir = dirs[random(sizeof(dirs))];
		if( stringp(last_room = query_temp("last_room"))
		&&  sizeof(dirs) > 1 && exits[dir] == last_room ) {
					 dirs -= ({dir});
					 dir = dirs[random(sizeof(dirs))];
		}

		if( mapp(doors) && !undefinedp(doors[dir])
		&& (doors[dir]["status"] & DOOR_CLOSED) )
		{
			return 0;
		}


	if( !mapp(exit = here->query("exits")) || undefinedp(exit[dir]) )
		return notify_fail("无此方向可去！\n");


		there = find_object( exit[dir] );
		if( there )
			{
				message_vision("$N蜿蜒地向"+default_dirs[dir]+"游了过去。\n",snake);
				this_object()->move(there);
				message_vision("$N蜿蜒地游了过来。\n",snake);
				all_inventory(here)->follow_me(this_object(), dir);
			}
		else return 0;

		set_temp("last_room", this_room);

		return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object owner;
	object here = environment(me);

	if ( query("food") >= 200  )
	{
		return random_walk();
	}


	if( (owner=present(me->query("owner"),here)) )
	{
		if( owner->query_skill("training") < 400 )
			owner->improve_skill("training", random(owner->query("int")));

		owner->add("combat_exp",2+random(3) );
		owner->add("potential",1+random(3) );
		if( owner->query("potential") > owner->query("max_potential") )
			owner->set("potential",owner->query("max_potential") );
		me->add("food",random(10));
	}
	victim->apply_condition("bt_poison", 10 + me->query("snake_poison") +
		victim->query_condition("bt_poison"));
	if (me->query("bite_busy")) victim->start_busy(2);
}

void die()
{
		object corpse, ling;
		mixed killer;

		remove_call_out("checking");

		if( !living(this_object()) ) revive(1);
		COMBAT_D->announce(this_object(), "dead");

		if( objectp(killer = query_temp("last_damage_from"))){
					 set_temp("my_killer", killer->query("id"));
					 COMBAT_D->killer_reward(killer, this_object());
					 if( !userp(killer) )
						call_out( "do_leave",1 , killer );
		}

		::die();
}

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object owner;
	object here = environment(me);
	int damage,bonus;


	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
			/ (int)target->query("combat_exp") + 1) ) return 0;

	if(me->query("neili")<100)return 0;

	if ( query("food") >= 200  )
	{
		return random_walk();
	}

	message_vision(HIW"\n$N突然闪电般地跃起，象一条白箭似的射向$n"+HIW"的咽喉。\n"NOR,me,target);

	if( random( me->query("combat_exp") ) > random( target->query("combat_exp") ) || !living(target) )
	{
			message_vision(HIR"结果$N"+HIR"一口咬住$n"+HIR"的咽喉，猛猛地吸起血来。\n\n"NOR,me,target);
			damage = random(  me->query_skill("force") + me->query_skill("hamagong") + me->query("jiali") )*( 1 + random(3) ) ;
			if(damage > 1000) damage = 1000;
			if(damage < 100) damage = 100;

			target->apply_condition("bt_poison", 15 +
				target->query_condition("bt_poison"));

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(2));
			me->start_busy(2+random(2));
			me->add("neili",-damage/2);

			bonus = damage/20 + random(damage/20);
			if(bonus > 30) bonus = 30;

			me->add( "food",bonus+random(bonus) );

			if( (owner=present(me->query("owner"),here)) )
			{
				if( owner->query_skill("training") < 400 )
					owner->improve_skill("training", owner->query("int") );
				owner->add("combat_exp", bonus + random(bonus)  );
				owner->add( "potential", bonus );
				if( owner->query("potential") > owner->query("max_potential") )
					owner->set("potential",owner->query("max_potential") );
			}
			add("combat_exp", bonus + random(bonus) );
			add("potential",bonus );

			COMBAT_D->report_status(target);
	}
	else
		message_vision(HIG"$N"+HIG"慌忙一闪身，正好躲过$n"+HIG"这一咬，不过也被吓得冷汗直流。\n"NOR,target,me);

	return 1;
}



