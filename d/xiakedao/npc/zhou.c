//Cracked by Roath
// /d/xiakedao/npc/zhou.c 周芷若
// xbc: 97/02/01

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("周芷若", ({ "zhou zhiruo", "zhou"}));
        set("long", 
		"她清丽秀雅，容色极美，腰间悬着一柄短剑。\n");
	set("gender", "女性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3000);
	set("jiali", 100);
	set("max_neili", 3000);

	set("combat_exp", 1800000);
	set("score", 100000);

	set_skill("literate", 180);
	set_skill("mahayana", 150);
        set_skill("force", 190);
	set_skill("linji-zhuang", 190);
        set_skill("claw", 190);
        set_skill("jiuyin-zhao", 190);
	set_skill("strike", 190);
	set_skill("jinding-zhang", 190);
	set_skill("finger", 190);
	set_skill("tiangang-zhi", 190);
        set_skill("sword", 190);
        set_skill("huifeng-jian", 190);
        set_skill("parry", 190);
        set_skill("dodge", 190);
        set_skill("zhutian-bu", 190);
        set_skill("throwing", 190);
        set_skill("persuading", 190);

        map_skill("claw", "jiuyin-zhao");
        map_skill("force", "linji-zhuang");
        map_skill("sword", "huifeng-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "huifeng-jian");
        map_skill("dodge", "zhutian-bu");
	map_skill("finger", "tiangang-zhi");
	map_skill("strike", "jinding-zhang");

	prepare_skill("claw", "jiuyin-zhao");
	prepare_skill("finger", "tiangang-zhi");


	create_family("峨嵋派", 4, "弟子");

	setup();
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

void init()
{
        object me = this_player();

        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 0, me);
        }
}

void greeting(object me)
{     object obj = this_object();
      object opp;
	int maxqi, maxjingli;
	int qi, jingli;
	qi = obj->query("max_qi");
	jingli = obj->query("max_jingli");

      if (opp = present("miejue shitai", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say 徒儿定会谨记于心的。");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				command("say 这一句是否指出掌必尽全力，伤敌无虑？");
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}
void attempt_apprentice(object ob)
{
        command ("say 你还是去拜我师父吧。");
}
