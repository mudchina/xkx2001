//Cracked by Roath
// /d/shenlong/npc/yinhuan.c
// ALN Sep / 97

inherit NPC;

int snake_attspeed(object);

void create()
{
        set_name("银环蛇", ({ "snake", "yinhuan she", "she","yinhuan" }) );
        set("race", "蛇类");
        set("age", 8);
        set("long", "一条全身闪着银光，绕着一圈圈圆环的毒蛇。\n");
        set("attitude", "peaceful");

        set("str", 29);
        set("cor", 30);

        set("jingli",100);

        set("combat_exp", 10000 + random(5000));
        set_temp("apply/attack", 10 + random(10));
        set_temp("apply/damage", 5 + random(5));
        set_temp("apply/armor", 4 + random(4));

        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("snake_poison", 50 +
                victim->query_condition("snake_poison"));
}

#include "/d/shenlong/npc/snake.h"
