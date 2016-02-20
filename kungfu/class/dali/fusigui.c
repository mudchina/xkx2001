//Cracked by Roath
// fusigui.c 傅思归

inherit NPC;
inherit F_MASTER;
string ask_me_1();

void create()
{
	set_name("傅思归", ({ "fu sigui", "fu"}));
    set("long", "　　他黄衫褚巾头，手持一根熟铜齐眉棍。看起来孔武有力。\n");
	set("title","大理国武将");
    set("gender", "男性");
    set("age", 35);
    set("inquiry", ([
		"段正淳": "我家王爷生性风流。",
		"手谕" :  (: ask_me_1 :),
		]));
	set_skill("cuff", 60);
    set_skill("jinyu-quan", 60);
    set_skill("dodge", 50);
    set_skill("duanshi-shenfa", 50);
    set_skill("parry", 50);
    set_skill("force", 40);
    set_skill("club", 60);
	set_skill("buddhism", 68);
	set_skill("kurong-changong",60);
    map_skill("cuff","jinyu-quan");
    map_skill("dodge","duanshi-shenfa");
	map_skill("force","kurong-changong");
	prepare_skill("cuff","jinyu-quan");
    set("str", 32);
    set("int", 21);
    set("con", 27);
    set("dex", 23);
    set("max_qi", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 30);
    set("combat_exp", 150000);
    set("attitude", "peaceful");
    set("shen_type", 1);
    create_family("大理段家", 15, "弟子");
    setup();
	carry_object("/d/dali/obj/ycloth")->wear();	
	carry_object("/d/dali/obj/tonggun")->wield();
}
string ask_me_1()
{
	mapping fam, skl; 
    object ob;
    string *sname;
    int i, k;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "大理段家")
		return RANK_D->query_respect(this_player())+"如要投官，何不前往南宋？";

	skl=this_player()->query_skills();
    sname=sort_array(keys(skl), (: strcmp :) );
    for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]] < 30) k++;
	}
	if (k>2) return RANK_D->query_respect(this_player())+"功力不够，不够资格领取手谕。";
	ob = new("/d/dali/obj/allow-letter1");
	ob->move(this_player());
	message_vision("$N获得一封手谕。\n",this_player());
	return "好吧，凭这封手谕，你可以去向卫士长挑战。";
}
#include "/kungfu/class/dali/master.h"
#include "/kungfu/class/dali/condition.h"
