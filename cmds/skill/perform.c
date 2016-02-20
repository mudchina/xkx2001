//Cracked by Roath
// perform.c
// modified by sdong to disable continuous perform and something like perform sword skill without wield sword
// disable skill gain, sdong 7/16/1999
// changed by wzfeng 99/12/2
// added can't pfm after 内力被三阴爪化去。 wsky 7/3/00

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping prepare;
        object weapon;
        string martial, martial1, martial2, skill, skill1, skill2;
        int result;

        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");

        if( me->query_temp("huagong"))
                return notify_fail(" ( 你内力不聚，不能运用内功。)\n");

        if( me->query_temp("feng"))
                return notify_fail(" ( 你的招数被封住了，无法使出绝招。)\n");

        if( !arg ) return notify_fail("你要用外功做什麽？\n");

        //add by wzfeng
                //////////////////////////////////////////////////////////////////
        if((int)me->query_temp("cannot_perform"))
                if(me->query("cannot_perfrom_msg"))
                return notify_fail(me->query("cannot_perfrom_msg")+"\n");
                else
                            return notify_fail("( 你现在不能施用外功。)\n");

                //////////////////////////////////////////////////////////////////

        prepare = me->query_skill_prepare();
        if (!prepare) prepare = ([]);

        if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
                if( weapon = me->query_temp("weapon") )
                        martial = weapon->query("skill_type");
                else {
                        if ( sizeof(prepare) == 0) martial = "unarmed";
                        if ( sizeof(prepare) == 1) martial = (keys(prepare))[0];
                        if ( sizeof(prepare) == 2) {
                                martial1 = (keys(prepare))[0];
                                martial2 = (keys(prepare))[1];
                                martial  = "combo";
                        }
                }
        }
        else if( userp(me) ) return notify_fail("你不能这样做！\n");

        //tell_object(me, "martial1 =  " + martial1 + "\n");
        //tell_object(me, "martial2 =  " + martial2 + "\n");

        if( stringp(martial) && stringp(skill = me->query_skill_mapped(martial)) ) {
                //tell_object(me, "martial =  " + martial + " skill = " + skill + "\n");
                notify_fail("你所使用的外功中没有这种功能。\n");

                if( SKILL_D(skill)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(skill) )
                        //      me->improve_skill(skill, 1, 1);

                        me->apply_condition("perform", martial);
                        return 1;
                } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(martial, 1) )
                        //      me->improve_skill(martial, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                }
                return 0;
        } else if( sizeof(prepare) == 2
        && stringp(skill1 = me->query_skill_mapped(martial1))
        && stringp(skill2 = me->query_skill_mapped(martial2)) ) {
                //tell_object(me, "martial1 =  " + martial1 + " skill1 = " + skill1 + "\n");
                //tell_object(me, "martial2 =  " + martial2 + " skill2 = " + skill2 + "\n");

                notify_fail("你所使用的外功中没有这种功能。\n");

                if( SKILL_D(skill1)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(skill1) )
                        //      me->improve_skill(skill1, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                } else if( SKILL_D(skill2)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(skill2) )
                        //      me->improve_skill(skill2, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                } else if( SKILL_D(martial1)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(martial1, 1) )
                        //      me->improve_skill(martial1, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                } else if( SKILL_D(martial2)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(martial2, 1) )
                        //      me->improve_skill(martial2, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                }
                return 0;
        }

        return notify_fail("你请先用 enable 指令选择你要使用的外功\。\n");
}

int help (object me)
{
                  write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>]

如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。

若是你的外功中有种类不同，但是招式名称相同的，或者不属於拳脚跟武器技能
的武功(如轻功)，可以用 <武功>.<招式>  的方式指定，如：

perform taiji-jian.chan

or

perform chan

换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
        return 1;
}

