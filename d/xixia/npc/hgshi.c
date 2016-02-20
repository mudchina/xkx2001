//Cracked by Roath

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("皇宫卫士", ({ "wei shi", "shi", "guard" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"一名满腮虬髯的西夏武士。\n");
	set("combat_exp", 100000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("pike", 100);
	set_skill("unarmed", 80);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set("no_get", "你扛不动");

	setup();

        carry_object("/clone/weapon/qiang")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
void init()
{
        object ob;
//      ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_condition("xakiller")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
int accept_fight(object me)
{
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        me->apply_condition("xakiller", 100);
        kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        me->apply_condition("xakiller", 100);
        kill_ob(me);
        return 1;
}
