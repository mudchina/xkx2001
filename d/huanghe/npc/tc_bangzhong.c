//Cracked by Roath
// bangzhong1.c

inherit NPC;

void create()
{
	set_name("帮众", 
              ({ "tiecha bangzhong", "bangzhong" }));
        set("title", "铁叉帮");
	set("long", 
		"这是一个惯于为非作歹的铁叉帮众。\n"
		"他心神不定，面露怯色，好像害怕什么。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("cuff", 60);
	set_skill("parry", 60);

        set("inquiry", ([
                "铁叉帮" : "咱们铁叉帮横行黄河两岸，天不怕，地不怕，连皇帝老儿都不买他的帐。",
                "尤得胜" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
                "赏善罚恶使者" : "赏善罚恶使者重入江湖，各帮各派都是难逃大劫。唉！",
                "侠客岛" : "赏善罚恶使者重入江湖，各帮各派都是难逃大劫。唉！",
                "胡大哥" : "胡大哥在弊帮劳苦功高，颇得帮主信任。",
                "帮主" : "我家帮主尤大爷乃是山西‘伏虎门’的惟一传人，叉法绝世无双。",
        ]));

	setup();

 	carry_object("/clone/weapon/sangucha")->wield();
}

