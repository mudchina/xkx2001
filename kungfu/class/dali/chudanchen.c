//Cracked by Roath
inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;
string ask_me();

void create()

{
        set_name("朱丹臣", ({ "zhu danchen", "zhu"}));
        set("long", "他手拿一册诗书，正在用心诵读，腰畔插着一对判官笔。\n");
        set("title","大理国武将");
        set("gender", "男性");
        set("age", 35);
        set("inquiry", ([
		"段正淳": "我家王爷生性风流。",
		"段誉": "请问阁下知否我家小王爷的下落。",
		"佛经" : (: ask_me :),

        ]));
        set_skill("strike", 60);
        set_skill("qingyan-zhang", 60);
        set_skill("dodge", 50);
        set_skill("duanshi-shenfa", 50);
        set_skill("parry", 50);
        set_skill("force", 40);
        set_skill("buddhism", 80);
	set_skill("sword", 60);
        set_skill("kurong-changong",60);
	set_skill("duanjia-jian", 65);
	
        map_skill("cuff","jinyu-quan");
        map_skill("dodge","duanshi-shenfa");
	map_skill("sword","duanjia-jian");
        map_skill("force","kurong-changong");
        map_skill("parry","duanjia-jian");
	
	 prepare_skill("strike","qingyan-zhang");

        set("str", 28);
        set("int", 29);
        set("con", 27);
        set("dex", 23);

        set("max_qi", 700);
        set("max_jing", 700);
        set("neili", 550);
        set("max_neili", 550);
        set("jiali", 50);
        set("combat_exp", 300000);

        set("attitude", "peaceful");
        set("shen_type", 1);
        create_family("大理段家", 15, "弟子");
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/d/dali/obj/panguanbi")->wield();

}
void attempt_apprentice(object ob)
{
        mapping fam;
        string dldj;

        command ("look "+ob->query("id"));
        if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="女性")
                command ("say 师太是峨嵋派的高手，大理荒僻之乡不敢多留。");
             else
                command ("say 大师是少林派的高手，大理荒僻之乡不敢多留。");
             return;
        }
        if( ob->query("family/family_name") == "丐帮") {
                command ("say 大理虽是荒蛮之地，但皇家收留乞丐成何题统？");
                return;
        }
        if ( ob->query("family/family_name") == "武当派" && ob->query("combat_exp") >= 10000 ) {
                command ("say 大理之处崇尚佛教，这位道兄还是另请高明吧。");
                return;
        }

       if ( ob->query("family/family_name") == "星宿派" && ob->query("combat_exp") >= 10000 ) {
                command ("say 你这星宿恶贼也敢来我大理境内倡狂？速速离去!");
                return;
        }
      if ( ob->query("family/family_name") == "白驼山" && ob->query("combat_exp") >= 10000 ) {
                command ("say 你这白驼恶贼也敢来我大理境内倡狂？速速离去!");
                return;
        }
       if ( ob->query("family/family_name") == "华山派" && ob->query("combat_exp") >= 10000 ) {
                command ("say 大理之处崇尚佛教，这位道兄还是另请高明吧。");
                return;
        }
		if ( ob->query("family/family_name") == "血刀门" && ob->query("combat_exp") >= 10000 ) {
                command ("say 你这血刀门的恶贼也敢来我大理境内倡狂？速速离去!");
                return;
        }
		if ( ob->query("family/family_name") == "神龙教" && ob->query("combat_exp") >= 10000 ) {
                command ("say 你这神龙教的恶贼也敢来我大理境内倡狂？速速离去!");
                return;
        }

	if (ob->query("combat_exp") > 20000) {
                command ("say "+ RANK_D->query_respect(ob) + 
                           "是武林高手，拜我为师？别取笑于在下了。");
                return;
        }

        if (ob->query("gender")=="女性") dldj="婢女";
        else  dldj = "家丁";
        command("say 好吧，我就斗胆代王爷收下你做个" + dldj + "吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","大理段氏"+dldj);
        return;
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "大理段家")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";

        if (query("book_count") > 10)
                return "你来晚了，佛经不在此处。";

        add("book_count", 1);
        ob = new("/d/shaolin/obj/fojing10");
        ob->move(this_player());

        return "好吧，这本佛经你拿回去好好钻研。";
}
#include "/kungfu/class/dali/promote4.h"
