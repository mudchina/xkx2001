//Cracked by Roath
// Jay 7/12/96

inherit NPC;

void create()
{
        set_name("萧半和", ({ "xiao banhe", "xiao", "banhe" }) );
        set("gender", "无性" );
	set("nickname", "晋阳大侠");
        set("age", 38);
        set("long", 
		"他躯体雄伟，满腮虬髯，果然极是威武。\n");
        set("str", 45);
        set("dex", 30);
        set("con", 27);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 80);
	set_skill("force", 80);
        set_skill("dodge", 75);

        set("combat_exp", 65000);

        set("max_qi", 500);
        set("max_jing", 200);
        set("neili", 800);
        set("max_neili", 800);
	set("jiali",40);


        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "我原名萧义，羡慕大明三宝太监郑和远征异域，宣扬我中"+
		     "华的德威，因此上将名字改为『半和』，意思说盼望有郑和的一半英雄。",
            "鸳鸯刀" : "世上有一对『鸳鸯刀』，得者可无敌於天下。",
       ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("silver", 10);
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
	command("say 好你个小贼，竟敢混入我萧府行凶！拿命来！");

	write("\n\n\n");
	kill_ob(me);
	}
	else {
	command("bow "+me->query("id"));
	command("say 同喜同喜。");
	}
}


