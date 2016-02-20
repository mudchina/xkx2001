//Cracked by Roath
//
// sdong, 3/18/2000

#include <ansi.h>
#include <armor.h>
#include <room.h>
inherit F_SSERVER;
inherit ITEM;
#define ORIGINAL "/d/bwdh/sjsz/room_28.c"
int explode(object me, object ob);
int do_fire(string arg);
int do_aim(string arg);
string look_room(object me, object env);
int do_load(string arg);

mapping default_dirs = ([
	"north":	"北",
	"south":	"南",
	"east":		"东",
	"west":		"西",
	"northup":	"北边",
	"southup":	"南边",
	"eastup":	"东边",
	"westup":	"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":	"东边",
	"westdown":	"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":		"上",
	"down":		"下",
	"out":		"外",
	"enter":	"里",
	"in":		"里",
	"left":		"左",
	"right":	"右",
]);

string day_event(){return NATURE_D->outdoor_room_event();}

void create()
{
        set_name(HIY"青铜炮"NOR, ({"pao","qingtong pao","bombgun"}));
        set_weight(1500000);
        set("value",150000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"一座青铜铸造的大炮，巨大的炮管昂然挺空，端的是威风八面。
久闻试剑山庄主人收集天下奇门兵器，没想到连大炮都有，只是
不知好用不好用。\n\n");

                set("unit", "座");
                set("material", "bronze");
        }
        setup();
}

void init()
{
	add_action( "do_load", "load" );
	add_action( "do_aim", "aim" );
	add_action( "do_fire", "shoot" );
}

int do_load(string arg)
{
	object ob = this_object(), huoyao, dantou;
	object me = this_player();
	int exp_time;

	if ( !arg || (arg!="powder" && arg!="huo yao" && arg!="dan tou" ) )
	   return notify_fail( "你想要加载什么？\n");

	if( me->is_busy() ) return notify_fail("你还在忙着呢！\n") ;
	
	if( arg=="powder" || arg =="huo yao" )
	{
		huoyao = present("huo yao");
		if( !huoyao || !objectp(huoyao) )return notify_fail( "你想要加载什么？\n");

		if( query_temp("yao_loaded") > 2 )return notify_fail("大炮已经装满火药了。\n");
		
		if( huoyao && objectp(huoyao) && huoyao->query("load") > 0 )
		{
			message_vision("$N往炮筒里加入一些火药。\n",me);
			huoyao->set("load",huoyao->query("load")-1 );
			if( huoyao->query("load") <=0 ) destruct(huoyao);
			add_temp("yao_loaded",1);
			me->start_busy(1);
		}
	}
	else if( arg =="dan tou" )
	{
		dantou = present("dan tou");
		if( !dantou || !objectp(dantou) )return notify_fail( "你想要加载什么？\n");

		if( query_temp("dan_loaded") > 0 )return notify_fail("大炮已经装有弹头了。\n");
		
		message_vision("$N往炮筒里加入一枚弹头。\n",me);
		destruct(dantou);
		add_temp("dan_loaded",1);
		me->start_busy(1);
	}

	return 1;
}



string look_room(object me, object env)
{
		  int i;
		  object *inv;
		  mapping exits;
		  string str, *dirs;

		  if( !env ) {
					 return "你的四周灰蒙蒙地一片，什么也没有。\n";
		  }
		  str = sprintf( "%s - %s\n    %s%s",
					 env->query("short"),
					 wizardp(me)? file_name(env): "",
					 env->query("long"),
					 env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

		  if( mapp(exits = env->query("exits")) ) {
					 dirs = keys(exits);
					 for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
										  dirs[i] = 0;
					 dirs -= ({ 0 });
					 if( sizeof(dirs)==0 )
								str += "    这里没有任何明显的出路。\n";
					 else if( sizeof(dirs)==1 )
								str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                else
                        str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
		  }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
					 if( inv[i]==me ) continue;
					 if( !me->visible(inv[i]) ) continue;
					 if( objectp(inv[i]->query("rider")) ) continue;
					 else inv[i]->delete("rider");
					 if( objectp(inv[i]->query("rided")) ) {
								str += "  " + inv[i]->short() + "骑在" +
								(inv[i]->query("rided"))->name() + "上";
					 if( stringp(inv[i]->query_temp("exit_blocked")))
								str += "挡着往"+inv[i]->query_temp("exit_blocked")+
								"去的路";
								str += "\n";
					 }
					 else {
								if (stringp(inv[i]->query_temp("exit_blocked")))
								str += "  " + inv[i]->short() + "挡着往" + inv[i]->query_temp("exit_blocked")
										  +"去的路\n";
								else
								str += "  " + inv[i]->short() + "\n";
								inv[i]->delete("rided");
					 }
		  }

		  return(str);
}


int do_aim(string arg)
{
	object me = this_player();
	object cur_target, target;
	string str, dest;
	mapping exit;

	if( me->is_busy() ) return notify_fail("你还在忙着呢！\n") ;

	cur_target = query_temp("target");

	if( !cur_target ){
		cur_target = find_object(ORIGINAL);
		if( !cur_target )cur_target=load_object(ORIGINAL);
		if (!objectp(cur_target))return notify_fail("找不到目标。\n");
	}

	if( arg=="down" || arg=="up" || arg=="out" || arg=="enter" )return notify_fail("这个方向没法打到。\n");
	
	if( arg )
	{
		if( !mapp( exit = cur_target->query("exits") ) || undefinedp(exit[arg]) ) {
			return notify_fail("这个方向没有出路。\n");
		}

		if( !cur_target->valid_leave(me, arg) ) notify_fail("这个方向太远了。\n");

		dest = exit[arg];

		if( !(target = load_object(dest)) )
			return notify_fail("无法移动。\n");
	}
	else target = cur_target;

	set_temp("target",target);

	str = look_room(me, target);
	tell_object(me, str+"\n");
	if(arg)
		message_vision(HIW"$N将炮口缓缓向"+ default_dirs[arg] + "转，瞄准了"+target->query("short")+"。\n"NOR,me);

	me->start_busy(1);

	return 1;
}

int do_fire(string arg)
{
	object ob = this_object();
	object me = this_player();
	int exp_time;

    if( ob->query_temp("fired") ) return notify_fail("你一拉才发现此炮已被引燃了，就快发射了！\n");
	if( ob->query_temp( "dan_loaded" ) <=0 )return notify_fail("炮还没有上弹头呢！\n");
	if( ob->query_temp( "yao_loaded" ) < 3 )return notify_fail("炮还没装满\弹药呢！\n");

	message_vision("$N伸手用力一拉，拉开了$n导火索。\n", me,ob);
	ob->set_temp("fired", 1);
	ob->set_temp("owner",me);
	call_out("explode", 1 + random(5), me, ob);

	return 1;
}

int explode(object me, object ob)
{
	object *victims, env, owner;
	int i,damage;
	string str;

		ob->delete_temp("fired");
		ob->delete_temp("owner");
		ob->delete_temp("dan_loaded");
		ob->delete_temp("yao_loaded");

	env = query_temp("target");
	if( !env ){
		env = find_object(ORIGINAL);
		if( !env )env=load_object(ORIGINAL);
		if (!objectp(env))return notify_fail("找不到目标。\n");
	}

	message_vision(HIY"只听的一声惊天动地的爆响，$N"+HIY"发射了，弹头带着一道火线飞向"+env->query("short")+HIY"，四周一片硝烟祢漫。\n"NOR, ob);

	owner = query_temp("owner");

	if( !owner || !objectp(owner) )
	{
		if(me && objectp(me) )
			owner=me;
		else owner=ob;
	}

	tell_room(env,HIR"只听的一声惊天动地的爆响，一发炮弹落地，四周一切立刻被炸得灰飞烟灭！\n"NOR, me);

	if( env->query("no_fight") ){
		return 0;
	}
	
	victims = all_inventory(env);

	for (i=0; i<sizeof(victims); i++) {
	   	if (!living(victims[i]) || victims[i]==me ) continue;
		damage= 4000+random(8000);
        victims[i]->receive_damage("qi", damage,  owner);
        victims[i]->receive_wound("qi", random(damage), owner);
        str = COMBAT_D->status_msg((int)victims[i]->query("qi") * 100 /(int)victims[i]->query("max_qi"));

		message_vision(HIR"$N被炸得人仰马翻！\n"NOR,victims[i]);
		message_vision(HIR"你远远看到"+victims[i]->query("name")+"被炸得人仰马翻！\n"NOR,ob);
        message_vision("($N"+str+")\n", victims[i]);
		message_vision(HIR"你远远看到("+victims[i]->query("name")+str+")\n",ob);
	}

        if (!env->query("th_buzhen")) return 1;

        env->set("long", env->query("org_desc"));
        env->set("exits", env->query("org_exits"));
        env->set("cost", env->query("org_cost"));
        env->delete("org_desc");
        env->delete("org_cost");
        env->delete("org_exits");
        env->delete("th_buzhen");
        env->delete("th_pozhen");
        env->delete("th_zhen_owner");

	return 1;
}
