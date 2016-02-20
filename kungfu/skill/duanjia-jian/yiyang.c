//Cracked by Roath
// yiyang.c 一阳指力注入武器

#include <ansi.h>

inherit F_SSERVER;

private int remove_effect(object me, object weapon);

int perform(object me, object target)
{
        object weapon;
        int skill, skill1;

        if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("你所用得内功心法不对，无法运用一阳指。\n");

        if (me->query_temp("yiyang"))
                return notify_fail("你已运一阳指指力于武器上了！\n");

        if (me->query_skill("force",1)<100
                || me->query_skill("kurong-changong",1)<100
                || me->query_skill("duanjia-jian",1)<100
                || me->query_skill("yiyang-zhi",1)<120)
                return notify_fail("你的功力不够，无法运用一阳指指力于武器上！\n");

        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="staff")
                return notify_fail("你没有使用正确的武器，无法运一阳指力于其上。\n");

        if (me->query("neili") <= 300)
                return notify_fail("你的内力不够运一阳指力！\n");
        if (me->query("jingli") <= 100)
                return notify_fail("你的精力不够运一阳指力！\n");

        if (weapon->query("rigidity")>=1000)
                return notify_fail("你发现这件武器质地特别坚硬，无法灌注内力于其上！\n");

        message("vision", HIY "\n"+me->query("name")+"紧握"+weapon->query("name")+"凝神运气片刻。\n\n" NOR, environment(me), me);
        tell_object(me, HIY "\n你凝神运气，把一阳指指力灌注到"+weapon->query("name")+"上。\n\n" NOR);

        skill = me->query_skill("kurong-changong",1);

        me->set_temp("yiyang", 25+skill/6);

        skill = me->query_skill("yiyang-zhi",1) + me->query_skill("kurong-changong",1);
        weapon->set_temp("rig", weapon->query("rigidity"));
        weapon->set_temp("yiyang", 1);
        me->set_temp("apply/attack", me->query_skill("force")/3);

        if (weapon->query("rigidity") < 100 )
                weapon->add("rigidity", 300+skill);
        else if ( weapon->query("rigidity") < 500 )
                weapon->add("rigidity", 200+skill);
        else if ( weapon->query("rigidity") < 1000 )
                weapon->add("rigidity", 100+skill);

        call_out("checking", 1, me, weapon);
        me->add("neili", -200);
        me->add("jingli", -50);

        return 1;
}

void checking(object me, object weapon)
{
        if (!me) {
                weapon->set("rigidity", weapon->query_temp("rig"));
                weapon->delete_temp("yiyang");
                weapon->delete_temp("rig");
                return;
        }
        if (me->query_temp("yiyang")) {
           if (environment(weapon)!= me || weapon!=me->query_temp("weapon")) {
                remove_effect(me, weapon);
                tell_object(me, HIY "\n你把一阳指指力从"+weapon->name()+"上收了回来。\n\n" NOR);
                return;
           }
           else if (weapon->query("weapon_prop") == 0) {
                remove_effect(me, weapon);
                tell_object(me, HIY "\n你的"+weapon->name()+"已毁，不得不收回灌注于其上的一阳指指力。\n\n" NOR);
                return;
           }
           else if (me->query_skill_mapped("force") != "kurong-changong") {
                remove_effect(me, weapon);
                tell_object(me, HIY "\n你感到内息不畅，无法保持灌注在"+weapon->name()+"上的一阳指指力。\n\n" NOR);
                return;
           }

           me->add_temp("yiyang", -1);
           call_out("checking", 1, me, weapon);
        }
        else {
           remove_effect(me, weapon);
        tell_object(me, HIY "\n你感到内息混浊，不得不换气运功，从"+weapon->name()+"上收回灌注的一阳指指力。\n\n" NOR);
        }
}       

private int remove_effect(object me, object weapon)
{
        weapon->set("rigidity", weapon->query_temp("rig"));
        weapon->delete_temp("yiyang");
        weapon->delete_temp("rig");
        me->delete_temp("apply/attack");
        me->delete_temp("yiyang");
        return 1;
}
