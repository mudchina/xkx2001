//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;


void create()
{
	set_name("萨木活佛", ({ "samu huofo", "samu", "huofo" }));
	set("long", 
"一个瘦高的中年喇嘛，身穿一领黄色袈裟，面无表情。眎\n");
	set_weight(10000000);
	set("gender", "男性");
	set("age", 45);
	set("attitude", "heroism");
	set("class","lama");
	set("shen_type", -1);
	set("str", 27);
	set("int", 33);
	set("con", 27);
	set("dex", 30);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 250000);

	set_skill("force", 70);
	set_skill("dodge", 75);
	set_skill("parry", 70);
	set_skill("staff", 70);
	set_skill("cuff", 70);
	set_skill("jingang-chu", 80);
        set_skill("lamaism", 140);
	set_skill("shenkongxing", 80);
	set_skill("longxiang-banruo", 80);
	set_skill("necromancy", 80);
	set("inquiry", ([
        "出家" : "找昌齐大喇嘛为你剃度吧。\n"
	]) );

	map_skill("force", "longxiang-banruo");
	map_skill("parry", "jingang-chu");
	map_skill("staff", "jingang-chu");
	map_skill("cuff", "yujiamu-quan");
	map_skill("dodge", "shenkongxing");
	
	prepare_skill("cuff", "yujiamu-quan");

	create_family("雪山派", 11, "喇嘛");


	setup();
	carry_object("/d/xingxiu/npc/obj/gangzhang")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("family/family_name") != "雪山派"
        && ob->query("family/family_name") != "血刀门"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                +ob->query("family/family_name")+"高手，本派可不敢收留！");
                return;
        }
	if (ob->query("class") != "lama") {
		command("say " + RANK_D->query_respect(ob) +
			"欲修练我密宗的功夫，尘缘未断很难提高。"); 
		return;
	}
        else if ((int)ob->query_skill("longxiang-banruo", 1) < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在般若龙象功上多下点功夫？");
		return;
	}
        else if ((int)ob->query("max_neili") < 300) {
		command("say " + RANK_D->query_respect(ob) +
			"应该再加深一点内力修为吧。");
		return;
	}
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
