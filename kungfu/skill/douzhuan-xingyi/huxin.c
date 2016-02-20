//Cracked by Roath
//Cracked by Kafei
//huxin.  护心功法

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("护心功只对自己有效！\n");

        if (me->query_temp("huxin"))
                return notify_fail("你已经护住心脉了。\n");

        if (me->query_skill("douzhuan-xingyi",1) < 80
                || me->query_skill("force",1) < 80
                || me->query_skill("literate",1) < 80 )
                return notify_fail("你的斗转星移神功未成，无法用来护心！\n");

        if (me->query("neili") < 300)
                return notify_fail("你的内力太少！\n");

        skill=me->query_skill("douzhuan-xingyi",1)+me->query_skill("literate",1);

        message("vision", HIW "\n"+me->query("name")+"潜用斗转星移神功，护住心脉。\n\n" NOR, environment(me), me);
        tell_object(me, HIW "\n你运转斗转星移内功，护住心脉。\n\n" NOR);

        me->set_temp("huxin", skill*8);
        me->add_temp("apply/armor",  me->query_skill("douzhuan-xingyi",1)/2);

        remove_call_out("checking");
        call_out("checking", 1, me);
        me->add("neili", -200);

        return 1;
}

void checking(object me)
{
        int maxqi, amount;

        if (!me->query_temp("huxin")) {
        	me->add_temp("apply/armor", -me->query_skill("douzhuan-xingyi",1)/2 );
                tell_object(me, HIW "你散去护心功法，长吁一口气。\n" NOR);
                return;
        }

        if (!me->is_fighting()) {
                if (me->query_temp("huxin")<=50)
                        me->delete_temp("huxin");
                else me->add_temp("huxin",-50);
        }

        maxqi=me->query("eff_qi");

        if (me->is_ghost()) {
                me->delete_temp("huxin");
                return;
        }

        if (living(me) && (maxqi < me->query("max_qi")*95/100 && me->query("neili") > 150)) {
                amount=(me->query_skill("douzhuan-xingyi",1)+me->query_skill("literate",1))/3+10;
                me->add("neili", -40);
                me->receive_curing("qi", amount);
        message_vision("$N转动护心功法，止住伤口的流血。\n", me);
        }

        if (living(me) && (me->query("qi") < (maxqi*2/3))) {
                amount = maxqi - me->query("qi");
                if (amount > me->query_temp("huxin")) amount=me->query_temp("huxin");
                me->add_temp("huxin",-amount);
        me->receive_heal("qi", amount);
        message_vision("$N转动护心功法，气色顿时好多了。\n", me);
        }

        call_out("checking", 1, me);
        return;
}       
