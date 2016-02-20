//Cracked by Roath
//
// sdong, 3/18/2000

#include <ansi.h>
#include <armor.h>
inherit F_SSERVER;
inherit ITEM;

void create()
{
	set_name( HIR "霹雳弹" NOR, ({ "bomb", "zha yao"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
                set("long", "这看起来似乎是一枚出自明教烈火旗的霹雳弹，上面还有导火索(fire)。\n");
                set("value", 1000000);		
	        set("material", "iron");
        }
        setup();
}

void init()
{
	add_action( "do_fire", "fire" );
	add_action( "do_fire", "throw" );
}

int do_fire(string arg)
{
	object ob = this_object();
	object me = this_player();
	int exp_time;

	/*
	if ( !arg || arg!="bomb" )
	   return notify_fail( "你想要引燃什么？\n");
	*/

	if ( !ob->query_temp("fired") ) {
	   message_vision("$N掏出一枚$n，伸手用力一拉，拉开了导火索。\n", me,ob);
	   ob->set_temp("fired", 1);
	   ob->set_temp("owner",me);
	   call_out("explode", 1+ random(5), me, ob);
	}
	else return notify_fail("你一拉才发现此霹雳弹已被引燃了，就快爆炸了！\n");

	return 1;
}

int explode(object me, object ob)
{
	object *victims, env, owner;
	int i,damage;
	string str;

	message_vision("只听的一声惊天动地的爆响，四周一切已被炸得灰飞烟灭！\n", ob);

	owner = query_temp("owner");

	if( !owner || !objectp(owner) )
	{
		if(me && objectp(me) )
			owner=me;
		else owner=ob;
	}

	env = environment(ob);

	if(!env || !objectp(env) )
	{
		destruct(ob);
		return 0;
	}

	if( !userp(env) && env->query("no_fight") )return 0;
	
	if( userp(env) ){
		env->set("eff_qi",-1);
		message_vision(HIR"$N被炸得粉身碎骨！\n"NOR,env);
        env->receive_damage("qi", env->query("max_qi"),  owner);
        env->receive_wound("qi", env->query("max_qi"), owner);
		env=environment(env);
	}

	victims = all_inventory(env);

	for (i=0; i<sizeof(victims); i++) {
	   	if (!living(victims[i]) || victims[i]==me ) continue;
		message_vision(HIR"$N被炸得人仰马翻！\n"NOR,victims[i]);
		damage= 2000+random(8000);
        victims[i]->receive_damage("qi", damage,  owner);
        victims[i]->receive_wound("qi", random(damage), owner);
        str = COMBAT_D->status_msg((int)victims[i]->query("qi") * 100 /(int)victims[i]->query("max_qi"));
        message_vision("($N"+str+")\n", victims[i]);
	}
	
	destruct(ob);

	return 1;
}
