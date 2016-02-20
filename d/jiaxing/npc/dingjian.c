//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("丁坚",({ "ding jian","ding" }) );
        set("gender", "男性");
        set("age", 55);
	set("long",
		"他目光炯炯，步履稳重，显是武功不低。\n");
        set("nickname","一字电剑");
        set("title","梅庄家人");
        set("combat_exp", 60000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
	set_skill("force",60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
	set_skill("sword",60);

	set("max_neili",300);
	set("neili",300);
	set("jiali",30);


        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}



int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp("ding")) {
		command("say 阁下武功出众，在下很是佩服。你我不必在动手了。");
		return 0;
	}
	command("say 好吧，你我就比划比划，点到为止。");
	me->set_temp("challenger", ob);
	return 1;
}

int chat()
{
        int my_max_qi, his_max_qi;
	object me = this_object();
	object ob = me->query_temp("challenger");


	if( !objectp(ob) ) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

	if (me->is_fighting(ob)) return ::chat();

	me->delete_temp("challenger");
        if (me->is_fighting()) return ::chat();

        if ( !present(ob, environment()) ) return ::chat();

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
		command("say 阁下果然高明，我认输了。");
		ob->set_temp("ding",1);
		return ::chat();
	}

}


