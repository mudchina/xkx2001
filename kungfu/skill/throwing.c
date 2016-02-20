//Cracked by Roath
// throwing.c

inherit SKILL;
int auto_throw()
{
        object me = this_object();
        object target = me->select_opponent();

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if (present("fei biao", me)){
        command("throw biao at "+target->query("id"));
        return 1;
        }
}
