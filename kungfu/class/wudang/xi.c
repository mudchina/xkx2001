//Cracked by Roath
// xi.c 张松溪

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("张松溪", ({ "zhang songxi", "zhang" }));
        set("nickname", "武当四侠");
        set("long", 
                "他就是张三丰的四弟子张松溪。\n"
                "他今年四十岁，身材短小精悍，满脸英气，\n"
                "为人精明能干，以足智多谋著称。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 36);
        set("int", 44);
        set("con", 37);
        set("dex", 36);

        set("max_qi", 3000);
        set("max_jing", 2600);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 110);
        set("combat_exp", 900000);
        set("score", 50000);

        set_skill("force", 180);
        set_skill("taiji-shengong", 180);
        set_skill("dodge", 170);
        set_skill("tiyunzong", 170);
        set_skill("cuff", 160);
        set_skill("taiji-quan", 160);
        set_skill("strike", 170);
        set_skill("mian-zhang",170);
        set_skill("parry", 180);
        set_skill("sword", 190);
        set_skill("taiji-jian",190);
        set_skill("literate", 180);
        set_skill("taoism", 180);
        //set_skill("taiji-gong",160);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
	prepare_skill("strike", "mian-zhang");
	
        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();

}

void attempt_apprentice(object ob)
{
        mapping fam;

        if( mapp(fam = ob->query("family")) && fam["family_name"] != "武当派" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "并非我门中人，习武还是先从各位道长起吧！");
                return;
        }

        if ((int)ob->query_skill("wudang-jiuyang", 1) < 60) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在武当九阳功上多下点功夫？");
                return;
        }

        if ((int)ob->query("shen") < 80000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，我一定收你。");
                return;
        }
        command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
                "我辈中人，今天就收下你吧。");
        command("recruit " + ob->query("id"));
}

