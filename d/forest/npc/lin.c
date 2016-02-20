//Cracked by Roath
// Jay 7/12/96

inherit NPC;

void create()
{
        set_name("林玉龙", ({ "lin yulong", "lin", "yulong" }) );
        set("gender", "男性" );
        set("age", 28);
        set("str", 40);
        set("dex", 30);
        set("con", 27);
        set("int", 25);
        set("shen_type", 1);

	set_skill("blade",60);
        set_skill("unarmed", 60);
	set_skill("force", 60);
        set_skill("dodge", 65);

        set("combat_exp", 45000);

        set("max_qi", 400);
        set("max_jing", 200);
        set("neili", 500);
        set("max_neili", 500);
	set("jiali",20);


        set("attitude", "peaceful");

        setup();
        set("chat_chance", 5);
        set("chat_msg", ({  
		"林玉龙喝道：「你住口，他们的刀法是我教的！」\n",
	}));
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	if (present("yuan dao", me) || present("yang dao", me)) {
	command("say 好你个小贼，竟杀死好人！拿命来！");

	write("\n\n\n");
	kill_ob(me);
	}
}


