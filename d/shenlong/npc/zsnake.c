//Cracked by Roath
// /d/shenlong/npc/zsnake.c
// ALN Sep / 97

inherit NPC;

int snake_attspeed(object);

void create()
{
        set_name("竹叶青", ({ "snake", "zhuye qing" }) );
        set("race", "蛇类");
        set("age", 4);
        set("long", "一只身体碧绿的蛇，显得特别细小。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("cor", 30);

        set("combat_exp", 10000 + random(2000));
        set_temp("apply/attack", 25 + random(10));
        set_temp("apply/damage", 2 + random(4));
        set_temp("apply/armor", 2 + random(6));

        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("snake_poison", 80 +
                victim->query_condition("snake_poison"));
}

#include "/d/shenlong/npc/snake.h"
