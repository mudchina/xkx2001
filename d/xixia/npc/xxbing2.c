//Cracked by Roath
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("西夏兵", ({ "xixia bing", "bing" }) );
	set_weight(random(600000));
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是名西夏兵，身披钢甲，手执长枪。\n");
	set("combat_exp", 80000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("str", 28);
	set("con", 23);
	set("int", 20);
	set("dex", 26);

	set("max_qi", 700);
	set("eff_qi", 700);
	set("qi", 700);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 25);
	set("shen_type", -1);

	set_temp("apply/attack",  40);
	set_temp("apply/defense", 40);

	set_skill("pike", 80);
	set_skill("unarmed", 60);
	set_skill("parry", 80);
	set_skill("dodge", 80);

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
