//Cracked by Roath
// ling-zhi.c 灵智上人

inherit NPC;

void create()
{
	set_name("灵智上人", ({ "lingzhi shangren", "lingzhi", "shangren" }));
	set("long", 
"灵智上人身披大红袈纱，头戴一顶金光灿然的僧帽，是个藏僧。\n"
"他身材魁武之极，站着比四周众人高出了一个半头。\n");
	set_weight(10000000);
	set("class","lama");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 23);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 40);
	set("combat_exp", 700000);

        set_temp("apply/attack",  75);
        set_temp("apply/defense", 75);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand", 120);
        set_skill("lamaism", 80);
        set_skill("literate", 30);
	set_skill("longxiang-banruo", 100);
	set_skill("necromancy", 100);
	set_skill("dashou-yin", 120);
	set_skill("shenkongxing", 120);
	set_skill("staff", 120);
	set_skill("jingang-chu", 120);

	map_skill("parry", "dashou-yin");
	map_skill("hand", "dashou-yin");
	map_skill("dodge", "shenkongxing");
	map_skill("force", "longxiang-banruo");
	map_skill("staff", "jingang-chu");

	prepare_skill("hand", "dashou-yin");
	create_family("雪山派", 10, "喇嘛");

        set("inquiry", ([
            "name" : "我的法名是灵智。",
            "here" : "我也不是中原人氏，不谙本地民情，抱歉。",
	    "密宗" : "密宗是佛法的一个宗派，又称金刚密宗。佛教的其他宗派还有"
		     "华严宗、律宗、禅宗、莲花宗、净土宗等。你们中原的少林寺"
		     "属禅宗。密宗与其他宗派的一个区别是密宗在修行中讲究密法"
                     "兼修。法是指佛法，密是指密咒。",
	    "吐蕃" : "吐蕃在西川以西，天竺以北，西域以南。",
//	    "密咒" : "阁下非为密宗弟子，恕不传授。",
	    "少林寺" : "少林寺是中原的禅宗丛林。",
	    "丛林" : "佛教中丛林指寺院。",
       ]) );

	setup();
//	carry_object("/clone/weapon/tongbo")->wield();
	carry_object("/d/qilian/obj/dahong-jiasha")->wear();
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
                        "如欲修练我密宗的功夫，尘缘未断很难提高。");
                return;
        }
        else if ((int)ob->query_skill("longxiang-banruo", 1) < 45) {
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在般若龙象功上多下点功夫？");
                return;
        }
        else if ((int)ob->query("max_neili") < 400) {
                command("say " + RANK_D->query_respect(ob) +
                        "应该再加深一点内力修为吧。");
                return;

}
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
