//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("杀手", ({ "shashou" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", 
	     "一个杀气腾腾的杀手。\n");
        set("shen_type", -1);

        set("combat_exp", 10000);

        set("attitude", "friendly");

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);

        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

void init()
{
        object ob;

        ::init();
        if ((ob = present("xiang wentian",environment(this_object()))) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	say("杀手大喝一声：向问天休走！\n");
	kill_ob(me);
}

