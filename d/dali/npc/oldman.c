//Cracked by Roath
// oldman.c 摆夷老叟

inherit NPC;

string ask_me();

void create()
{
	set_name("摆夷老叟", ({ "oldman" }));
	set("long", "　　一个摆夷老叟大大咧咧地坐在竹篱板舍门口，甩着三四个巴掌大的棕吕树叶，\n瞧着道上来来往往的人们，倒也快活自在。\n");
	set("gender", "男性");
	set("age", 78);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("chat_chance", 10);
	set("chat_msg", ({
		"摆夷老叟深深地叹了口气道：该死的土匪，天天的在城外骚扰百姓，这官兵们怎么不管啊？\n",      
		}) );
	set("combat_exp", 800);
	set("inquiry", ([
		"土匪" : (: ask_me :),
		]) );
	setup();
	carry_object("/clone/armor/cloth")->wear();
}
string ask_me()
{
	object ob;
	ob = this_player();
	if ( ob->query("family/family_name") == "大理段家")
	{
		command("say 该死的土匪，这位"+RANK_D->query_respect(ob)+"身为官爷，该去为民除害啊！\n");
		ob->set_temp("差事1", 2);
		command("addoil " + ob->query("id"));
		return "要是我早二十年。。。";
	}
	else
	{
		command("say 该死的土匪，天天的在城外骚扰百姓，偏偏没人治止，世风日下啊！\n");
		command("sigh");
		return "要是我早二十年。。。";
	}
}
