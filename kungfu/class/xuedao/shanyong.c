//Cracked by Roath
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;
void create()
{
	set_name("善勇", ({ "shanyong", "shan", "yong" }));
	set("long", 
"一个胖胖的西藏僧人，面带笑容，却常干笑里藏刀的事。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "heroism");
	set("class","lama");
	set("chat_chance", 20);
	set("shen_type", -1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 500);
	set("max_jing", 350);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 60);
	set("combat_exp", 60000);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 60);
        set_skill("lamaism", 60);
//	set_skill("xue-dao", 50);
	set_skill("xueshitiao", 50);
//	set_skill("longxiang-banruo", 50);

//	map_skill("force", "longxiang-banruo");
//	map_skill("blade", "xue-dao");
	map_skill("dodge", "xueshitiao");
	

	create_family("血刀门", 5, "弟子");

	setup();
	carry_object("/d/qilian/obj/miandao")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player())
	&& ob->query("gender") == "女性"){
		message_vision("$N斜眼淫笑，目光不住在$n身上转来转去。\n", this_object(), ob);
		command("flirt "+ob->query("id"));
        }
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
 if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
                return;
        }
	command("say 好吧，贫僧就收下你了。");
        command("recruit " + ob->query("id"));
}

