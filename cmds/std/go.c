//Cracked by Roath
// go.c
// modified by sdong for biaoche, 12/23/98
//changed by wzfeng 99/12/2
//changed by maco for play 1/18/2000 

#include <ansi.h>;
inherit F_CLEAN_UP;

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
        "in":           "里",
        "left":         "左",
        "right":        "右",
]);

string day_event(){return NATURE_D->outdoor_room_event();}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string dest, mout, min, dir, rided_name, result;
        object env, obj, rided, rider, ob, play_ob;
        mapping exit;
        object *f_obs;

        if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");
		////////////////////////////////////////////////////////////////////////
		//add by wzfeng
		if(me->query_temp("cannot_move"))
			if(me->query_temp("cannot_move_msg"))
				return notify_fail(me->query_temp("cannot_move_msg")+"\n");
			else
				return notify_fail("你现在不能移动。\n");
///////////////////////////////////////////////////////////////////////////
        if (me->is_fighting()) {
                f_obs = me->query_enemy();
                if (objectp(f_obs[0]))
                if (5 + random((int)me->query("dex")) <=
                        random((int)f_obs[0]->query("dex"))) {
                        me->start_busy(1);
                        return notify_fail("你逃跑失败。\n");
                }
        }

        if( me->query("jingli") < me->query("max_jingli")/10 )
                return notify_fail("你已经精疲力尽，动弹不得。\n");

        env = environment(me);
        if(!env) return notify_fail("你哪里也去不了。\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("这个方向没有出路。\n");
                else
                        return 0;
        }

        if( !env->valid_leave(me, arg) ) return 0;

        if( !stringp(dest = me->query_temp("new_valid_dest")) ) 
                dest = exit[arg];

        if( !(obj = load_object(dest)) )
                return notify_fail("无法移动。\n");

        me->delete_temp("new_valid_dest");

        if( objectp(rided = me->query("rided")) 
        && environment(rided) == env
        && me->query("race") == "人类" )
                rided_name = rided->name();
        else me->delete("rided");
             
        if( obj->query("day_shop")
        && ( day_event() == "event_night" || day_event() == "event_midnight"))
        return notify_fail(obj->query("short")+"晚上不开，请天亮了再来！\n");

        if( objectp(rided) && !env->valid_leave(rided, arg) )
                return notify_fail("你不能骑著" + rided_name + "通过。\n");

        if( me->query("race") == "人类" && me->query_temp("riding") ) {
                if( present( "biao che", environment(me) ) )
                        return notify_fail("你正坐在镖车上呢！\n");
      else me->delete_temp("riding");
        }


        if( me->query("race") == "人类" && objectp(rided) ) {
                if( !obj->query("outdoors") )
                        return notify_fail("你不能骑著" + rided_name + "进去。\n");
                if( obj->query("cost") > rided->query("ability") )
                        return notify_fail(rided_name + "到了这地方好像走不动了！\n");
        } else  if( me->query("race") == "家畜" 
        && ( !obj->query("outdoors") 
        || obj->query("cost") > me->query("ability") ) ) return 0;

        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;

        if( me->is_fighting() ) {
                if( me->query("race") == "人类" ) {
                        if( objectp(rided)  ) {
                                mout = "伏在" + rided_name + "身上往" + dir + "落荒而逃了。\n";               
                                min = "骑著" + rided_name + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
                        }
                        else {    
                                mout = "往" + dir + "落荒而逃了。\n";
                                min = "跌跌撞撞地跑了过来，模样有些狼狈。\n";
                        }
                }
                else {    
                        mout = replace_string( me->query("fleeout_message"), "$d", dir );
                        min  = me->query("fleein_message");
                }
        } 
        else {
                if( me->query("race") == "人类" ) {
                        if( env->query("outdoors") ) {
                                if( objectp(me->query("rided")) ) {
                                        mout = "骑着" + rided_name + "往" + dir + "飞驰而去。\n";
                                        min  = "骑着" + rided_name + "奔驰过来。\n";
                                }
                                else {
                                        mout = "急步往" + dir + "离开。\n";
                                        min = "快步走了过来。\n";
                                }
                        }
                        else {
                                mout = "往" + dir + "走了出去。\n";
                                min = "走了过来。\n";
                        }
                }
                else {
                        mout = replace_string( me->query("comeout_message"), "$d", dir );
                        min = me->query("comein_message");
                }
        }
        
        // Added for play. by maco
	if( objectp(play_ob = env->query("playing")) && me->query("race") == "人类" && play_ob != me){
		if( !present(play_ob, env))
			env->delete("playing");
		if(play_ob->query_temp("exercise/playing") && me->query_temp("be_played/"+play_ob->query("id")) > 1 ) {
			message_vision("$N想朝"+dir+"走去，但是$n的箫声实在美妙之极，$N听在耳里，竟然舍不得就此离开。\n", me, play_ob);
			me->start_busy(2);
			me->delete_temp("be_played/"+play_ob->query("id"));
			return 1;
		}
	}

	
        //If the exit is blocked.
        if( objectp(ob = env->query("exit_blockers/"+dir)) && me->query("race") == "人类" && ob != me){
                if( !present(ob, env))
                        env->delete("exit_blockers/"+ob->query_temp("exit_blocked"));
                if( present(ob, env) && interactive(ob) && living(ob)){
                        if( !me->query("rided")){
                                if( me->query_dex() < ob->query_dex()+5+random(5)){
                                message_vision("$N试图朝"+dir+"走去，但是被$n挡住了出路。\n", me, ob);
                                return 1;
                                }
                                mout = "施展轻功，从" + ob->name() +"身旁一晃而过，连衣角也没挨着。\n";    
                        }
                        else {
                                if( me->query("combat_exp") >= ob->query("combat_exp")){
                                        if( ob->query("rided")){
                                                message_vision(HIR"$N骑着"+rided_name+"冲过来，一头把$n从坐骑上撞下来，摔个四脚朝天。\n"NOR, me, ob);
                                                ob->query("rided")->delete("rider");
                                                ob->delete("rided");
                                                }
                                else
                                message_vision(HIR"$N骑着"+rided_name+"冲过来，把$n撞个四脚朝天。\n"NOR, me, ob);

                                ob->receive_wound("qi", random(1000), rided);
                                result = COMBAT_D->eff_status_msg((int)ob->query("qi") * 100 /(int)ob->query("max_qi"));
                                message_vision("($N"+result+")\n", ob);
                                ob->start_busy(2);
                                ob->delete_temp("exit_blocked");
                                env->delete("exit_blockers/"+dir);
                                } 
                                if( me->query("combat_exp") < ob->query("combat_exp")/2){
                                message_vision(HIG"$N一把抓住"+rided_name+"的缰绳，把$n连人带坐骑一齐停了下来。\n"NOR, ob, me);
                                me->start_busy(2);
                                ob->start_busy(1);
                                return 1;
                                }
                                else if( me->query("combat_exp") < ob->query("combat_exp"))
                                message_vision(RED"$N见$n骑着"+rided_name+"冲过来，赶紧闪到一旁让$n通过。\n"NOR, ob, me);
                        }
                }
                if( !living(ob)) 
                        mout = "踩着" +ob->name()+ "向" +dir+ "走了出去。\n";
        } 
        if( me->query("race") == "人类" && !me->query("env/invisibility") ) {
                if( objectp(rided) ) {
                        if( random(5) == 0 ) me->add("jingli", -2);
                        rided->add("jingli", - env->query("cost")*2);
                        if( rided->query("jingli") <= 0 ) rided->unconcious();
                } else if (userp(me)) {
                        me->add("jingli", - env->query("cost")*2);
                        if( me->query("jingli") <= 0 ) me->unconcious();
                }
                message( "vision", me->name() + mout, env, ({me}) );
        } else if( !objectp(me->query("rider")) && me->query("race") != "人类" ){
                me->add("jingli", - env->query("cost")*2);
                if( me->query("jingli") <= 0 ) me->unconcious();
        }

        if( me->move(obj) ) {
                me->remove_all_enemy();
                if( !objectp(me->query("rider")) && !me->query("env/invisibility") )
                        message( "vision", me->name() + min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);

                if(( !objectp(rided = me->query("rided")) 
                || environment(rided) != environment(me))
                && me->query("race") == "人类")
                        me->delete("rided");

                if(( !objectp(rider = me->query("rider")) 
                || environment(rider) != environment(me))
                && me->query("race") != "人类")
                        me->delete("rider");

                if( me->query_temp("exit_blocked")){
                env->delete("exit_blockers/"+me->query_temp("exit_blocked"));
                me->delete_temp("exit_blocked");
                }

                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        tell_object(me, "看来该找机会逃跑了...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}
