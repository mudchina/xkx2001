//Cracked by Roath
// kill.c
//modified by arthurgu for surrender ,10/99

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj;
        string *killer, callname;
        int time;
        time = ((me->query("mud_age"))-(me->query("pktime")));
        
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不准战斗。\n");

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if(((string)SECURITY_D->get_status(me)=="(immortal)" )
         && ((string)SECURITY_D->get_status(obj)!="(immortal)" ))
                return notify_fail("你不能杀这个人！\n");

        if( me->query_temp("last_persuader") == obj->query("id") )
// no chinese input now, will change message
                return notify_fail("你不能杀这个人！\n");

      if( me->query("id") == obj->query_temp("surrender/ownder") )
                return notify_fail("他/她已经投降了,你现在不能杀！\n");
            
      if( me->query_temp("surrender/ownder")!=0 )
                return notify_fail("你刚投降过别人，别老想着干坏事！\n");
                
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if( me->query("rided"))
                return notify_fail("你骑着马，杀起来腾挪不开吧。\n");

        if(obj==me)
                return notify_fail("用 suicide 指令会比较快:P。\n");

        if( strsrch(file_name(environment(me)), "/d/xiakedao/") >= 0 && userp(obj))
                return notify_fail("龙岛主有令：不得在岛上攻击他人！\n");

        if(userp(obj) && userp(me) && (me->query_condition("pker") > 240 
                                    || obj->query("mud_age") < 18000) )
                return notify_fail("你感到一丝内疚，手突然软了下来！\n");
                
/*        if(userp(obj) && userp(me) && time < 3600 && 
		obj->query("combat_exp") < me->query("combat_exp")/5 )
//		if(userp(obj) && userp(me))
                return notify_fail("你自觉杀心太重，手软了下来！\n");
  */              
        callname = RANK_D->query_rude(obj);

        message_vision("\n$N对著$n喝道：「" 
                + callname + "！今日不是你死就是我活！」\n\n", me, obj);

        if( ! living(obj)
        && obj->query_temp("last_damage_from") != me) 
        me->set_temp("free_rider", 1);

        me->kill_ob(obj);
        
        if( !userp(obj) )
        {
                obj->accept_kill(me);
                if (!obj->is_grpfight()) 
                        obj->kill_ob(me);
        }
        else {
                if (!obj->is_killing(me->query("id"))) 
                        me->set_temp("pking/"+obj->query("id"), 1);
                obj->delete_temp("initiator");
                obj->fight_ob(me);
                obj->add_temp("initiate_pk", ({me->query("id")}));
                tell_object(obj, HIR "如果你要和" + me->name() 
                        + "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
        }

        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且试图杀死对方，kill 和 fight 最大的
不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
