//Cracked by Roath
// su quan 苏荃

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("苏荃", ({ "su quan","su", "furen" }));
	set("title", "神龙教教主夫人");
	set("long",
		"美貌少妇，看模样不过二十三四岁年纪，微微一笑，媚态横生，艳丽无比。\n");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "peaceful");
	set("shen_type", -1);

	set("str", 23);
	set("int", 28);
	set("con", 24);
	set("dex", 24);
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 20);
	set("combat_exp", 500000);
	set("score", 5000);
	set("shen", -8000);

	set_skill("force", 50);
	set_skill("dulong-dafa", 50);
	set_skill("dodge", 55);
	set_skill("lingshe-shenfa", 55);
	set_skill("parry", 56);
	set_skill("sword", 58);
	set_skill("meiren-sanzhao", 65);
	set_skill("kick", 55);
	set_skill("jueming-tui", 55);
	set_skill("literate", 80);
	set_skill("medicine", 80);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("parry", "meiren-sanzhao");
	map_skill("sword", "meiren-sanzhao");
	map_skill("kick", "jueming-tui");

	prepare_skill("sword", "meiren-sanzhao");

	set("chat_chance", 10);
	set("chat_msg", ({
			"\n",
	}) );


	setup();
	carry_object("/clone/weapon/duanjian")->wield();
	carry_object("/clone/armor/cloth")->wear();
}

void init()
{
        object me = this_player();

        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

void greeting(object me)
{     object obj = this_object();
      object opp;
	int maxqi, maxjingli;
	int qi, jingli;
	qi = obj->query("max_qi");
	jingli = obj->query("max_jingli");

      if (opp = present("hong antong", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say 教主啊，这句「脱剑膝前横」似乎合美人三招之理，出其不备，防不胜防。");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}
