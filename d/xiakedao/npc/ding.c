//Cracked by Roath
// ding.c 丁春秋
#include "/kungfu/class/xingxiu/auto_perform.h"
inherit NPC;
int auto_perform();
void create()
{
        set_name("丁春秋", ({ "ding chunqiu", "ding" }));
        set("nickname", "星宿老怪");
        set("long", 
                "他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
                "可是他看起来形貌清奇，仙风道骨。\n");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 3000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("shen", -400000);
        set("apply/armor", 50);
        set("PKS", 1000000);

        set_skill("force", 200);
        set_skill("huagong-dafa", 200);
        set_skill("dodge", 180);
        set_skill("zhaixinggong", 200);
        set_skill("strike", 180);
        set_skill("claw", 180);
        set_skill("sanyin-zhua", 180);
        set_skill("poison", 200);
        set_skill("chousui-zhang", 180);
        set_skill("parry", 180);
        set_skill("staff", 180);
        set_skill("tianshan-zhang", 200);
        set_skill("throwing", 180);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("sword", "tianshan-zhang");

        prepare_skill("strike", "chousui-duzhang");
        prepare_skill("claw", "sanyin-zhua");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        create_family("星宿派", 1, "开山祖师");
        set("class", "taoist");
        set("san_count", 1);
        set("zhen_count", 7);

        setup();
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
}

void attempt_apprentice(object ob)
{
        command ("say 你是不是活得不耐烦了，敢来烦我。");
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

      if (opp = present("ouyang feng", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say 十步杀一人，想练成绝世神功就要残忍。");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}
