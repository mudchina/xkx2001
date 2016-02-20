//Cracked by Roath
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("胜谛", ({ "shengdi", "sheng", "di" }));
	set("long", 
"这是一个身形魁梧的西藏僧人，神色冷漠。武功是同门中最高的一人。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "heroism");
	set("class","lama");

	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1000);
	set("max_jing", 750);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 60);
	set("combat_exp", 300000);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 90);
        set_skill("lamaism", 80);
	set_skill("cuff", 80);
	set_skill("yujiamu-quan", 90);
	set_skill("xue-dao", 90);
	set_skill("xueshitiao", 80);
	set_skill("longxiang-banruo", 80);

	map_skill("force", "longxiang-banruo");
	map_skill("cuff", "yujiamu-quan");
	map_skill("blade", "xue-dao");
	map_skill("parry", "xue-dao");
	map_skill("dodge", "xueshitiao");
	
	prepare_skill("cuff", "yujiamu-quan");

	create_family("血刀门", 5, "弟子");

	setup();
	carry_object("/d/qilian/obj/miandao")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}
void attempt_apprentice(object ob)
{
        if (ob->query("gender")=="女性") {
                command ("say 本派不收女弟子，你回去吧。");
                return;
        }

	if( ob->query("family/family_name") != "雪山派"
        && ob->query("family/family_name") != "血刀门"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                +ob->query("family/family_name")+"高手，本派可不敢收留！");
                return;
        }
	if ((int)ob->query("shen") > -50000) {
                command("say 兄弟想跟在下这混饭吃，得先做出点儿表现来。");
		return;
	}
	else if ((int)ob->query_skill("longxiang-banruo", 1) < 45) {
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在般若龙象功上多下点功夫？");
                return;
        }
	command("say 好吧，贫僧就收下你了。");
        command("recruit " + ob->query("id"));
}
