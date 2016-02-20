//Cracked by Roath
inherit NPC;
#include <ansi.h>

string ask_me(object);
int do_answer(string);

void create()
{
        set_name("一灯大师", ({ "yideng dashi", "yideng", "dashi" }));
        set("nickname", "南帝");
        set("long", "此人身形高大，身着一袭青色袈裟，却是不怒自威，让人肃而起敬。\n");
        set("gender", "男性");
        set("age", 55);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing",1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("combat_exp", 1800000);

        set_skill("force", 180);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("finger", 200);
        set_skill("kurong-changong", 180);
        set_skill("yiyang-zhi", 200);
        set_skill("cuff", 180);
        set_skill("strike", 180);
        set_skill("buddhism", 180);
        set_skill("sword", 180);
        set_skill("duanshi-shenfa", 200);
        set_skill("duanjia-jian", 200);
        set_skill("qingyan-zhang", 200);
        set_skill("jinyu-quan", 180);
        set_skill("medicine", 120);
        
        map_skill("dodge","duanshi-shenfa");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike","qingyan-zhang");
        map_skill("force", "kurong-changong");
        map_skill("sword","duanjia-jian");
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger", "yiyang-zhi");
        prepare_skill("strike", "qingyan-zhang");


        create_family("大理段家", 17, "弟子");
        setup();
        carry_object("/d/shaolin/npc/obj/cloth")->wear();
//      carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        command ("say 这「侠客行」的古诗图解，包藏着古往今来最博大精深
的武学秘奥，老夫竭尽心智，尚自不能参悟其中十之一二，那还能分
心去理会世上俗事。 ");
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

      if (opp = present("huang yaoshi", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("humble huang yaoshi");
				command("say 劲力内含，发之无形，伤人与不觉之中。");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}
