//Cracked by Roath
// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj, old_target;
        int time,i,l,a;
        time = ((me->query("mud_age"))-(me->query("pktime")));

        if( environment(me)->query("no_fight") )
                return notify_fail("这里禁止战斗。\n");

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("你想攻击谁？\n");

        if( !obj->is_character() )
                return notify_fail("看清楚一点，那并不是生物。\n");
                
        if( obj->query_temp("surrender/ownder")!=0)
                return notify_fail("他刚投降，你现在不能偷袭！");
           
        if( me->query_temp("surrender/ownder")!=0)
                return notify_fail("你刚投降，现在不能偷袭他人！");
                
       if(userp(obj)&& userp(me) &&me->query("combat_exp")/3>obj->query("combat_exp") )
                return notify_fail(obj->query("name")+"与你武功相差太远，用不着偷袭？直接用kill吧。\n");

      if(userp(obj)&& userp(me) &&me->query("combat_exp")<obj->query("combat_exp")/3 )
               return notify_fail("你这点微末武功还想偷袭人家？别做梦了。\n");
  		
	  i=obj->query("qi");
	  l=obj->query("eff_qi");
	  a=obj->query("max_qi");
		if ( userp(me) && userp(obj) && ((i*10/a)<4 || (l*10/a)<4))
                return notify_fail("对方已经很虚弱，无力再和你切磋了。\n");

	   if(((string)SECURITY_D->get_status(me)=="(immortal)" )
         && ((string)SECURITY_D->get_status(obj)!="(immortal)" ))
                return notify_fail("你不能攻击这个人！\n");

        if( !userp(obj) )
                return notify_fail("你只能偷袭玩家。\n");
	      if(me->query_temp("yield") )
			  return notify_fail("你现在打架不还手如何能偷袭呢？\n");


        if( !living(obj) || obj->query_temp("cursed") )
                return notify_fail("你必须等此人醒来才能进行切磋比试。\n");

        if( obj->is_fighting(me) )
                return notify_fail("加油！加油！加油！\n");

        if( me->query_temp("hitting") )
                return notify_fail("加油！加油！加油！\n");
/*
        if( !living(obj) )
                return notify_fail(obj->name() + "已经这样了你还要打，过分了点吧？\n"); 
*/

        if(obj==me)     return notify_fail("打自己？别这么想不开。\n");

        if( strsrch(file_name(environment(me)), "/d/xiakedao/") >= 0 && userp(obj))
                return notify_fail("龙岛主有令：不得在岛上攻击他人！\n");


        if( userp(obj) ) {
                if( (int)obj->query("mud_age") < 18000 ) 
                        return notify_fail("找小孩试什么招？\n");
                message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
                me->set_temp("hitting");
                // cyz&&kitten@xeno 99/05/08
                // addded a temp array for determine who initiated the fight
                // if some1 feels the need the reduce its size, feel free to
                // do so.
                obj->add_temp("initiate_pk", ({me->query("id")}));
                remove_call_out("do_hit");
                call_out("do_hit", 1, me, obj);
                return 1;
        }

        return notify_fail("这个指令只能用来与其他玩家切磋一招。\n");
}

void do_hit(object me, object obj)
{
        if(objectp(present(obj, environment(me)))) {

                COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
  	      if(!obj->query_temp("yield") )
                COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
        }
        me->delete_temp("hitting");
        return;
}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>
 
这个指令让你偷袭一个人物，这种形式的战斗并不需要征得对方的同意。
 
其他相关指令: kill, fight

HELP
    );
    return 1;
}
