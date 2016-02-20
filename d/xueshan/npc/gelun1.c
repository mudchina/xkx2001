//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;
int do_huanyuan();
void create()
{
	set_name("葛伦布", ({ "ge lunbu", "ge", "lunbu" }));
	set_weight(300000000);
	set("long", 
"他是密宗的戒律僧，长得膀大腰，手中提着法杵，身着黄袍，头戴黄帽，\n"
"满面肃杀之气。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "heroism");
	set("class","lama");
	set("shen_type", -1);
	
	set("max_qi", 500);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 80000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("dodge", 55);
	set_skill("parry", 60);
	set_skill("strike", 60);
	set_skill("staff", 60);
	set_skill("cuff", 60);
	set_skill("jingang-chu", 70);
	set_skill("longxiang-banruo", 60);
	set_skill("yujiamu-quan", 60);

	map_skill("cuff", "yujiamu-quan");
        map_skill("force", "longxiang-banruo");
        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");

	prepare_skill("cuff", "yujiamu-quan");

        set("inquiry", ([
                "还愿" : (: do_huanyuan :),
		"烧香" : (: do_huanyuan :),
		"供佛" : (: do_huanyuan :),
        ]) );

        setup();
	carry_object("/d/qilian/obj/fachu")->wield();
        carry_object(__DIR__"obj/lamajiasha")->wear();
}


int do_huanyuan()
{
        say("葛伦布说道：你拿什麽孝敬佛爷呀? \n");
	return 1;
}
int accept_object(object who, object ob)
{
	if (ob->name()!="酥油罐") {
	write("葛伦布脸上露出迷惑的表情。\n");
	command ("shake");
        return 1;
	}
	write(
	"葛伦布一哈腰：佛爷保佑施主，里边请。\n");
        this_player()->set_temp("marks/酥", 1);
        return 1;
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	
	if (ob->query_temp("mark/comin"))
                say( "葛伦布双手合什笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，扎西德勒！\n");
	else
                say( "葛伦布双手合什笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，喀列别！\n");
}
void destroy (object ob)
{
        destruct(ob);
        return;

}
