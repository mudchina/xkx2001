//Cracked by Roath
// animal: snake.c
// Jay 3/18/96

inherit NPC;

int snake_attspeed(object);

void create()
{
	set_name("腹蛇", ({ "snake", "fushe" }) );
	set("race", "蛇类");
	set("age", 10);
	set("long", "一条身形粗壮的腹蛇，奇毒无比。\n");
	set("attitude", "peaceful");

	set("str", 33);
	set("cor", 33);

//        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
//        set("verbs", ({ "bite" }) );

	set("combat_exp", 20000 + random(20000));

	set_temp("apply/attack", 50 + random(20));
	set_temp("apply/damage", 20 + random(10));
        set_temp("apply/dodge", 20 + random(10));
	set_temp("apply/armor", 20 + random(10));

	setup();
}

/*
void die()
{
	object ob;
//        message_vision("$N啪的一声断成两截！$N死了。\n", this_object());
	ob = new(DRUG_D("fushedan"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
*/

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 80 +
		victim->query_condition("snake_poison"));
}

#include "/d/shenlong/npc/snake.h"
