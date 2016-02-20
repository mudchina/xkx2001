//Cracked by Roath
// Ryu, 11/20/96.
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("彩雪蛛", ({ "caixue zhu", "spider", "zhizhu" }) );
	set_color("$HIW$");
        set("race", "昆虫");
        set("subrace", "爬虫");
        set("age", 3);
        set("long", "一只酒杯口大小的蜘蛛，蜘蛛模样甚是怪异，全身条纹红绿相间，\n"+
		"鲜艳到了极处，令人一见便觉惊心动魄。\n"+
		"这种蜘蛛产於西藏雪山之顶，乃天下三绝毒之一。");
        set("attitude", "peaceful");

//      set("limbs", ({ "头部", "身体", "触角", "前螯" }) );

        set("combat_exp", 900);
	set("qianzhu-wandu/spider", 15);
  	set("qianzhu-wandu/poison", 100);   // speed up
  	set("qianzhu-wandu/level", 150);   // min level that can use
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
        victim->apply_condition("insect_poison", 100 +
                victim->query_condition("insect_poison"));
}



