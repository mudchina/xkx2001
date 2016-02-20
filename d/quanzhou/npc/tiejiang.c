//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("铁匠", ({ "tie jiang", "jiang" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long",
		"他打着赤膊，结实的肌肉高高愤起，朴实的脸上带着殷勤的微笑。\n");
	set("combat_exp", 3000);
        set("str", 25);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/weapon/caidao",
		"/clone/weapon/gangbang",
		"/clone/weapon/tiegun",
	}) );

	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("unarmed", 30);
	
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("silver", 3);
}

void init()
{
	object ob;

        ::init();
	if ( interactive(ob=this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

        add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say 欢迎这位"+RANK_D->query_respect(ob)+"光临，请随便参观。");
}
