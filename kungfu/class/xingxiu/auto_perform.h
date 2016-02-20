//Cracked by Roath
// wsky 28/8/00

// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if( objectp(me->query_temp("weapon")) ) {
                command("perform jinxian");
        }
        else
        {
                if( !target->query_temp("huagong") )
                        command("perform sanyin");
                else
                	command("perform yiji");
                        command("yun qisuck "+target->query("id"));
        }

/*        if( present("sanxiao san", me) ||present("biling zhen", me)
          ||present("lianxin dan", me)){
          command("throw " + target->query("id"));
          }
*/
                return 1;
}
