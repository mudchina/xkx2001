//Cracked by Roath

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("校尉", ({ "xiao wei", "wei" }));
        set_color("$YEL$");
	set_weight(1000000);
	set("age", 22);
	set("gender", "男性");
	set("long", "一个魁武的西夏军官。\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", -1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("stick", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);

	set("chat_msg_combat", ({
		"校尉喝道：大胆刁民，竟敢造反不成？\n",
		"校尉喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
	}));
	setup();
	carry_object("/clone/weapon/langya-bang")->wield();
	carry_object("/d/city/obj/junfu")->wear();
}

void init()
{
	object ob;
//	::init();
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

