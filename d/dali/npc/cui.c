//Cracked by Roath
// banker.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
string ask_me();

void create()
{
	set_name("崔百泉", ({"cui baiquan", "cui", "baiquan"}));
	set("nickname", "金算盘");
	set("long","这是一个看上去猥猥祟祟的一个中年人，面色发黄。\n");
	set("gender", "男性");
	set("age", 55);
	set("title", "平南王府管家");
	set("str", 28);
	set("int", 24);
	set("dex", 28);
	set("con", 28);

	set("shen", 1000);

	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);

	set_skill("cuff", 80);
	set_skill("dodge", 80);
	set_skill("hammer", 180);
	set_skill("duanshi-shenfa",80);
	set_skill("jinyu-quan",65);
	map_skill("dodge","duanshi-shenfa");
	map_skill("cuff", "jinyu-quan");
	prepare_skill("cuff", "jinyu-quan");

	set("inquiry", ([
		"工钱" : (: ask_me :),
		]));

	create_family("大理段家",17,"弟子");
	setup();
	add_money("coin", 188);
	add_money("silver", 88);
	add_money("gold", 1);
	carry_object("/d/city/obj/guazi")->wear();
	carry_object(__DIR__"obj/jinsuanpan")->wield();
}

void enough_rest()
{
	delete_temp("busy");
}

/*void unconcious()
{
        message_vision("\n突然，只见$N闪身拉开柜台下一道暗门，钻了进去，咔嚓从里
边把门锁上了。\n",
                this_object());
        destruct(this_object());
}
*/
void attempt_apprentice(object ob)
{
	command("haha");
	command("say 他奶奶的，老子一到阴天就腰酸腿疼，教不了你什么。");
	return;
}

string ask_me()
{
	int wage;
	object ob = this_player();
	if (ob->query("family/family_name")!="大理段家") {
		command("say 你是哪里来的" + RANK_D->query_rude(ob) +
				"欺负大理人老实你想搞诈骗啊？快给我滚！");
		command("slap " + ob->query("id"));
		return ("小心我宰了你！");
	}
	if (ob->query("title")=="大理国侯爷") 
		return ("侯爷，应该是你给小的我发工钱呀。");

	if (ob->query("title")=="大理国平南王府家丁" ||
		ob->query("title")=="大理国平南王府婢女" )
		return ("王爷赏你口饭吃就不错了，还想要工钱。");

	if (ob->query("title")=="大理国平南王府武士")  
		return ("你身为武士，应该专心练功才是，给你钱会分你心的。");
	
	if (!ob->query("dali/jobdone"))
		return ("你要不要脸，想白吃饭啊？先干点什么再领钱。");

	else {
		if (ob->query("lastcheck") < ob->query("dali/jobdone") ) {
		if (ob->query("combat_exp")<30000) {
		wage = (ob->query("dali/jobdone")-ob->query("lastcheck"))*500;
	ob->set("lastcheck",ob->query("dali/jobdone"));
	command("say 这是你打杂的酬劳，好好干！");
	command("say 不过我看你笨手笨脚的，给你钱也收不牢，干脆我帮你存下吧！");
	ob->add("balance", wage);
	return ("加油继续干！");
}
	else { 
	wage=(ob->query("dali/jobdone")-ob->query("lastcheck"))*ob->query("combat_exp")/70;
	ob->set("lastcheck",ob->query("dali/jobdone"));
	command("say 这是你打杂的酬劳，好好干！");
	command("say 不过我看你笨手笨脚的，给你钱也收不牢，干脆我帮你存下吧！");
	ob->add("balance", wage);
	return ("加油继续干！");       
}
}
else
	return("从上次领薪水到现在你光吃饭不干活儿，没你的工钱！");
}
}
