//Cracked by Roath
inherit NPC;

void create()
{
        set_name("贵公子", ({ "gongzi"}));
        set("long", 
"这是一介翩翩贵公子，长得到也算玉树临风、一表人才，可偏偏一双眼睛"
"却爱斜着瞟人。\n");
	set("gender", "男性");
        set("age", 20+random(10));
	set("attitude", "friendly");

	set("combat_exp", 7500);
        set_skill("unarmed", 35);
        set_skill("force", 35);
        set_skill("dodge", 40);
	set_skill("ding-unarmed", 30+random(10));
	map_skill("unarmed", "ding-unarmed");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
        set("shen_type", -1);
        setup();
	add_money("gold", 1);

}
void init()
{
        add_action("do_kill", "kill");
}
int do_kill(string arg)
{
        object ob;
        int i;

        if (!arg || arg != "gongzi") return command("kill ");
	
	if (present("e nu", environment(this_object()))){
	command("say 你想谋害本公子，当真是自找死路！ 左右何在！");
        message_vision("贵公子左右的恶奴对$N发动攻击！\n", this_player());

        for(i=0; i<2; i++) {
                if( objectp( ob = present("e nu " + (i+1), environment(this_object())) ) )
                                 ob->kill_ob(this_player());
                else    this_object()->kill_ob(this_player());
        }
	}

        return command("kill gongzi");
}














