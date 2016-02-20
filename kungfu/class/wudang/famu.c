//Cracked by Roath
// famu.c 伐木道士

inherit NPC;

void create()
{
	int age;
	
	age = 15 + random(30);
	
	set_name("伐木道士", ({ "famu daoshi", "famu", "daoshi" }));
	set("long", 
		"他是武当山的伐木道士，到这里来砍树。\n");
	set("gender", "男性");
	set("age", age);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 35);
	set("int", 15);
	set("con", 25);
	set("dex", 30);
	
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 2000+age*10);
	set("score", 2000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("cuff", 40);
	set_skill("parry", 40);
	set_skill("sword", 30);
	set_skill("taiji-jian", 40);
	set_skill("taoism", 30);

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 5, "弟子");

    set("chat_chance", 6);
    set("chat_msg", ({
        "道士擦了一把额头上的汗，说道：小小砍树，大有学问。\n",
        "道士说道：凡做事都要恰到好处，砍树也不例外。\n",
        "道士说道：砍树的时候不要太急太快，否则树干倒下会伤人。\n",
        "道士说道：砍树的时候也不要太慢了，砍不够树不会倒。\n",
    }) );

	setup();
	add_money("coin", age*10);
	carry_object("/clone/weapon/changjian")->wield();
}
