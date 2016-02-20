//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;

string ask_me();

void create()
{
	set_name("拉章活佛", ({ "lazhang huofo", "lazhang", "huofo" }));
	set("long", 
"他是本寺藏经阁的主管，曾经远渡天竺求经，历时三十年。五十二岁时来住本寺，\n"
"在辩经大会上独占鳌头。他看上去面黄肌瘦，身形瘦高。\n");
	set("gender", "男性");
	set("title","大轮寺喇嘛");
	set("age", 65);
	set("attitude", "friendly");
	set("class","bonze");
	set("shen_type", 1);
	set("str", 27);
	set("int", 33);
	set("con", 27);
	set("dex", 30);
	
	set("max_qi", 1400);
	set("max_jing", 850);
	set("jiali", 0);
	set("combat_exp", 50000);
	set("score", 5000);

	set("inquiry", ([
                "藏经" : (: ask_me :),
        ]));

        set("book_count", 3);
	setup();
	carry_object(__DIR__"obj/lamajiasha")->wear();
}
string ask_me()
{
	mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="雪山派"
	&& fam["family_name"] !="血刀门")
                return RANK_D->query_respect(this_player()) +
                "与本寺素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本寺的经书不在此处。";
        add("book_count", -1);
        ob = new("/d/xueshan/obj/fojing3.c");
        ob->move(this_player());
        return "好吧，这本经书你拿回去好好钻研。";
}

