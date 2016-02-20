//Cracked by Kafei
// beiming-shengong.c 北冥神功
// Acep, modified by xuy
// Modified by Xuanyuan 8/2001

#include <ansi.h>;
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
  return notify_fail("北冥神功只能通过研读《北冥秘籍》来提高。\n");
}

int practice_skill(object me)
{
  return notify_fail("北冥神功只能通过研读《北冥秘籍》来提高。\n");
}

string exert_function_file(string func)
{
  return __DIR__"beiming-shengong/" + func;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        if ((int)victim->query_skill("beiming-shengong",1)>50
         && (int)me->query_skill("beiming-shengong",1)<50
         && !me->query_temp("weapon")
         && me->query("id")!="mu ren"
         && me->query("max_neili")>100
         && victim->query("combat_exp")>me->query("combat_exp")/2
         && (victim->query("combat_exp")*100/me->query("combat_exp")-50)>random(149))
        {
                victim->add("max_neili", 1*(1+((int)victim->query_skill("beiming-shengong",1)/100)));
                me->add("max_neili", -1*(1+((int)victim->query_skill("beiming-shengong",1)/100)));

		if (victim->query("max_neili") > (int)victim->query_skill("force") * (int)victim->query("con") * 2 / 3 * 2)
			victim->set("max_neili",victim->query_skill("force") * (int)victim->query("con") * 2 / 3 * 2);

                if ((int)me->query("potential") < 97)
                        victim->add("potential",  3);
                victim->add("combat_exp", 10);
                return HIY "$N运足内力一击命中，却不料只觉息关一开，一股内力被$n吸了过去！\n" NOR;
        }
	
	return damage;
}
