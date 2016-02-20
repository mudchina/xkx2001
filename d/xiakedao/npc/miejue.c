//Cracked by Roath
// Npc: /d/xiakedao/npc/miejue.c 灭绝师太
// Date: xbc 96/09/24, dong 8/1/97

inherit NPC;
inherit F_MASTER;

int auto_perform();

void create()
{
        set_name("灭绝师太", ({ "miejue shitai", "miejue", "shitai" }));
        set("long", 
"她就是峨嵋派第三代掌门人灭绝师太了。\n"
"她容貌算得极美，但两条眉毛斜斜下垂，一副面相便变得极是诡异，几乎\n"
"有点儿戏台上的吊死鬼味道。\n");

        set("gender", "女性");
        set("attitude", "friendly");
        set("class", "bonze");


        set("age", 45);
        set("shen_type", 1);

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 2500);
        set("max_jing", 2500);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 150);
        set("combat_exp", 1300000);
        set("score", 8000);
//Ryu: Avoid Yitian-jian be begged away!!!
        set("PKS", 100000000);

        set_skill("force", 150);
        set_skill("linji-zhuang", 150);
        set_skill("claw", 160);
        set_skill("throwing", 160);
        set_skill("strike", 160);
        set_skill("jinding-zhang", 160);
        set_skill("finger", 150);
        set_skill("tiangang-zhi", 150);
        set_skill("sword", 180);
        set_skill("huifeng-jian", 180);
        set_skill("blade", 150);
        set_skill("yanxing-dao", 150);
        set_skill("parry", 150);
        set_skill("dodge", 170);
        set_skill("zhutian-bu", 170);
        set_skill("literate", 150);
        set_skill("persuading", 160);
        set_skill("mahayana", 160);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("sword", "huifeng-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");

        create_family("峨嵋派", 3, "掌门人");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();

        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
	  carry_object("/clone/weapon/zhujian")->wield();
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

      if (opp = present("zhou zhiruo", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say 芷若，纵死侠骨香，除魔卫道定要此精神。");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );

				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}
void attempt_apprentice(object ob)
{
        command ("say 你是不是派来偷学峨嵋功夫的？快滚。");
}
#include "/kungfu/class/emei/auto_perform.h";