//Cracked by Roath
// Ryu, 11/20/96.
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("毒蜘蛛", ({ "du zhizhu", "spider", "zhizhu" }) );
	set_color("$HIB$");
        set("race", "昆虫");
        set("subrace", "爬虫");
        set("age", 3);
        set("long", "一只黑色的大蜘蛛，肚子上有红蓝相间的环纹。\n");
        set("attitude", "peaceful");

//      set("limbs", ({ "头部", "身体", "触角", "前螯" }) );

        set("combat_exp", 900);
	set("qianzhu-wandu/spider", 10);
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
        message_vision("\n$N八条腿收拢，吐出一团丝，死了。\n", this_object());
        ob = new(__DIR__"zhusi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("insect_poison", 10 +
                victim->query_condition("insect_poison"));
}



