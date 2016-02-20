// full.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)

{
        int max;

        if(!str)
        me=this_player();
        else   {
                me = find_player(str);
                if (!me) return notify_fail (GRN+"No"+str+",or "+str+"not online!\n"+NOR);
        }

/*      this is full for fengyun
        max = me->query("max_gin");
        me->set("eff_gin",max);
        me->set("gin",max);
        max = me->query("max_kee");
        me->set("eff_kee",max);
        me->set("kee",max);
        max = me->query("max_sen");
        me->set("eff_sen",max);
        me->set("sen",max);
*/
//      this is full for xkx
        max = me->query("max_jing");
        me->set("eff_jing",max);
        me->set("jing",max);
        max = me->query("max_qi");
        me->set("eff_qi",max);
        me->set("qi",max);

        max = me->query("max_neili");
        me->set("neili",max);
        max = me->query("max_jingli");
        me->set("jingli",max);

        max = me->max_food_capacity();
        me->set("food",max);
        max = me->max_water_capacity();  
        me->set("water",max);
        me->clear_condition();
        message_vision(HIY+"$N打了一个哈欠，立即变精神了。\n"+NOR, me);
        return 1;
}
