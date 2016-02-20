//Cracked by Roath
// Ryu, 11/20/96.

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("蝎子", ({ "scorpion", "xiezi" }) );
	set_color("$RED$");
        set("race", "昆虫");
        set("subrace", "爬虫");
        set("age", 3);
        set("long", "一只褐色的蝎子，尾巴上有黄蓝相间的环纹。\n");
        set("attitude", "peaceful");

//        set("limbs", ({ "头部", "身体", "触角", "前螯", "尾巴" }) );
//        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 900);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 6);
        set_temp("apply/armor", 1);

        setup();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
        }
}
void die()
{
        object ob;
        message_vision("\n$N尾巴一翘，死了。\n", this_object());
        ob = new(__DIR__"scorp_shell");
        ob->move(environment(this_object()));
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("insect_poison", 10 +
                victim->query_condition("insect_poison"));
}
