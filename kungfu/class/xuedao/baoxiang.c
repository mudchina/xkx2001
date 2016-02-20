//Cracked by Roath
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;
string ask_me();

void create()
{
	set_name("宝象", ({ "bao xiang", "bao", "xiang" }));
	set("long", 
"一个极高极瘦的僧人，俩眼凶芒四射。此人在血刀老祖门下，最是心狠手辣。\n");
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
	
	set("max_qi", 800);
	set("max_jing", 450);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 60);
	set("combat_exp", 90000);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("lamaism", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("xue-dao", 60);
	set_skill("cuff", 60);
	set_skill("yujiamu-quan", 60);
	set_skill("xueshitiao", 60);
	set_skill("longxiang-banruo", 60);
	set("book_count", 1);
	set("inquiry", ([
                "血刀秘笈" : (: ask_me :),
        ]));

	map_skill("force", "longxiang-banruo");
	map_skill("blade", "xue-dao");
	map_skill("dodge", "xueshitiao");
	map_skill("parry", "xue-dao");
	map_skill("cuff", "yujiamu-quan");

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
	if ((int)ob->query_skill("longxiang-banruo", 1) < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "的身板儿跟我们这儿混饭可吃不消。");
                return;
	}
	command("say 好吧，贫僧就收下你了。");
        command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam;
        object ob;
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="血刀门")
                return  "我。。。不知道。";
        if (query("book_count") < 1)
                return "我。。。不知道。";
        if( (random(30) > 5))
                return "我。。。不知道。\n";
        add("book_count", -1);
        ob = new("/d/qilian/obj/xuedao_book");
        ob->move(this_player());
        return "好吧，这本书就借给你看几天吧。";
}
