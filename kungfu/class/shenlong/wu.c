//Cracked by Roath
// chilong shi 赤龙使

inherit NPC;

void create()
{
	set_name("无根道人", ({ "wugen daoren","wugen", "chilong shi","shi" }));
	set("nickname", "赤龙使");
	set("long",
		"黑须道人，可是脸上充满了激愤之情。\n");
	set("gender", "男性");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 32);
	set("int", 27);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1400);
	set("max_jing", 1400);
	set("neili", 1400);
	set("max_neili", 1400);
	set("jingli", 1400);
	set("max_jingli", 1400);
	set("jiali", 60);
	set("combat_exp", 360000);
	set("score", 50000);
	set("shen", -22000);

	set_skill("force", 120);
	set_skill("dulong-dafa", 100);
	set_skill("dodge", 120);
	set_skill("lingshe-shenfa", 120);
//	set_skill("hook", 100);
//	set_skill("shenlong-goufa", 94);
	set_skill("parry", 110);
	set_skill("blade", 120);
//      set_skill("magic", 60);
//      set_skill("shenlong-magic", 60);
	set_skill("kick", 120);
	set_skill("jueming-tui", 140);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("kick", "jueming-tui");
//	map_skill("hook", "shenlong-goufa");

	prepare_skill("kick", "jueming-tui");
	prepare_skill("strike", "huagu-mianzhang");

	create_family("神龙教", 2, "使者");

	setup();

	carry_object("/d/shenlong/obj/yanlindao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();

        if( living(this_object()) && !is_fighting()
        &&  interactive(this_player())
        &&  this_player()->query("sg/cured") ) {
                remove_call_out("do_killing");
                call_out("do_killing", 1, this_player());
        }
}

void do_killing(object ob)
{
        if( !living(this_object()) || is_fighting()
        || environment() != environment(ob) )
                return;

        message_vision("$N对$n喝道：无耻的叛徒，我宰了你！！！\n", this_object(), ob);
        kill_ob(ob);
}
