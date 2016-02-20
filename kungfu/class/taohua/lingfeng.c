//Cracked by Roath
// kane, 21/01/98

inherit NPC;

void create()
{
	set_name("曲灵风", ({ "qu lingfeng", "lingfeng", "qu" }));
	set("shen_type", 0);

	set("str", 28);
	set("con", 30);
	set("dex", 20);
	set("gender", "男性");
	set("age", 35);
	set("long",
		"他是黄药师的三弟子曲灵风。他年纪虽然较轻，但两鬓已经斑白。\n"+
		"他虽在桃花四大弟子中名列第三，但武学修为却最高。\n");
	set("combat_exp", 400000);
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 80);
	set("shen_type", -1);

        set_skill("force", 160);
	set_skill("bitao-xuangong", 160);
	set_skill("luoying-shenfa", 160);
	set_skill("qimen-dunjia", 160);
	set_skill("hand", 160);
	set_skill("throwing",200);
	set_skill("lanhua-fuxue", 160);
	set_skill("strike", 160);
	set_skill("kick", 160);
	set_skill("luoying-shenjian", 160);
	set_skill("xuanfeng-saoye", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
	set_skill("sword", 160);
	set_skill("yuxiao-jian", 160);

	map_skill("force", "bitao-xuangong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "luoying-shenfa");
        map_skill("strike", "luoying-shenjian");
	map_skill("kick", "xuanfeng-saoye");

        prepare_skill("strike", "luoying-shenjian");

	set("attitude", "friendly");
/*
	set("inquiry", ([
		"黄药师" : "我师…，什么？我这里不卖药。\n",
		"卖药" : "不卖药就是不卖药。\n",
		"曲灵风" : "啊！我，……你说的人我不认识。\n",
		"生意" : "这个么……。\n",
	]));
*/	
	create_family("桃花岛", 2, "弟子");

	setup();
	carry_object("/d/taohua/obj/robe")->wear();
	carry_object("/d/taohua/obj/bagua")->wield();
}

void attempt_apprentice(object ob)
{
	string ttt;

        if( ob->query("family/family_name") != "桃花岛" ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                +ob->query("family/family_name")+"高手，本派可不敢收留！");
                return;
        }

        if( ob->query("family/family_name") == "桃花岛"
        && ob->query("family/master_name") == "黄药师" ) {
                command ("say " + RANK_D->query_respect(ob) + "是"
                + "本派高手，我可不敢收留！");
                return;
	}               
        if ((int)ob->query_skill("bitao-xuangong", 1) < 60){
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在内功修为上多下点功夫？");
                return;
        }

        if ((int)ob->query_skill("literate", 1) < 60){
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在文学修养上多下点功夫？");
                return;
        }

	if (this_player()->query("gender") == "男性") ttt = "门生";
	else  if (this_player()->query("gender") == "女性") ttt = "青衣"; 
	command("recruit " + ob->query("id"));
	ob->set("title", "归云庄" + ttt);
	command("say " + "虽然我收你为徒，但我不喜俗务，所以你还是陆师弟的门下，明白了麽？\n");
	command("say " + "以後来这儿，先进密室等我，注意别让别人发现了。\n");
}
