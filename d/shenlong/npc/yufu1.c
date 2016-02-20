//Cracked by Roath
// yufu-tanggu.c 渔夫

inherit NPC;
string ask_shenlong();

void create()
{
	set_name("渔夫", ({ "yu fu","fu" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"岛上以打鱼为生的渔夫。\n");
	set("combat_exp", 8800);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack",  50);
	set("apply/defense", 50);
	set("jingli",300);
	set("max_jingli",300);
//      set_skill("unarmed", 30);
//      set_skill("parry", 30);
//      set_skill("dodge", 30);

	set("inquiry",([
		"神龙岛"  : (: ask_shenlong :),
		"神龙教"  : (: ask_shenlong :),
	]));

	setup();
	carry_object("/d/shenlong/obj/cloth")->wear();
	add_money("coin", 50);
}

string ask_shenlong()
{
	mapping fam;
	object ob;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "神龙教"){
	 this_player()->set_temp("marks/shenlong", 1);
	 write("渔夫对你说：神龙岛可是个好去处，你想去就喊小人一声。\n");
	 return "快上船，走吧。\n";
	}
	else{
	 command("nod");
	 return "既是本教弟子，喊一声就行了。";
	}
}
