//Cracked by Roath
// guard.c
// Ryu, 4/28/98

#include <ansi.h>;
inherit F_CLEAN_UP;

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

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, dir;
	object env, obj, ob;
	mapping exit;

	if( !arg ) return notify_fail("你要守住哪个方向？\n");

	if( me->is_busy() )
		return notify_fail("你前一个动作还没有完成。\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也用不着守。\n");

	if( env->query("no_fight") || env->query("day_shop"))
		return notify_fail("你不能在这里挡他人出路。\n");

	if( strsrch(file_name(env), "/d/xiakedao/") >= 0 )
		return notify_fail("龙岛主有令：不得在岛上阻他人路！\n");
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) 
			return notify_fail("你想守住哪个方向？\n");

//	if( !env->valid_leave(me, arg) ) return 0;

	if( !stringp(dest = me->query_temp("new_valid_dest")) ) 
		dest = exit[arg];

	if( !(obj = load_object(dest)) )
		return notify_fail("ERROR。\n");


	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	if (objectp(ob=env->query("exit_blockers/"+dir)))
		return notify_fail(ob->query("name")+"已经挡住了往"+dir+"去的出路！\n");

	if (me->query_temp("exit_blocked")){
		message_vision("$N让开了往"+me->query_temp("exit_blocked")+"去的通路。\n", me);
		env->delete("exit_blockers/"+me->query_temp("exit_blocked"));
		me->delete_temp("exit_blocked");
	}

	me->start_busy(1);
	me->set_temp("exit_blocked", dir);
    env->set("exit_blockers/"+dir, me);

	message_vision(CYN"$N往路中间一站，挡住了向" + dir + "去的出路。\n"NOR, me);
	call_out("cost",3);
	return 1;
}

void cost()
{
	object env, obj, ob;
	object me = this_player();
	env = environment(me);

	if( !me->query_temp("exit_blocked") ) return;

	if(me->query("jingli",1)<200 || me->query("jing",1)<200)
	{
		message_vision("$N把守这么久，实在是太累了，只好让开了往"+me->query_temp("exit_blocked")+"去的通路。\n", me);
		env->delete("exit_blockers/"+me->query_temp("exit_blocked"));
		me->delete_temp("exit_blocked");
		return;
	}
	
	me->add("jingli", -me->query("max_jingli",1)/20);
	me->add("jing", -me->query("max_jing",1)/20);
	call_out("cost",3);
}

int help(object me)
{
	write(@HELP
指令格式 : block <方向>
 
让你挡住任一方向的出路，谁也不让过。
如果你不想继续挡着这个出路，离开这个房间即可。

HELP
    );
    return 1;
}
