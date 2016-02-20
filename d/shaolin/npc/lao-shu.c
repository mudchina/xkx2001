//Cracked by Roath
// laoshu.c 老鼠

inherit NPC;

void create()
{
	set_name("老鼠", ({ "lao shu", "shu", "mouse" }) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一只赃兮兮的小老鼠。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 100);
	set("shen_type", -1);
	set("env/wimpy", 70);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set_temp("apply/attack", 5);
//	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 1);

	setup();
}

int random_move()
{
        mapping exits;
        string *dirs;
	int i;

        if( !mapp(exits = environment()->query("exits")) ) return 0;
        dirs = keys(exits);
	i = random(sizeof(dirs));
        command("say " + "I am going to " + dirs[i] + ".");
	if(exits[dirs[i]][11..15] == "bagua")
        	command("go " + dirs[i]);
}


void die()
{
        object ob;
        message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
        ob = new(__DIR__"shurou");
        ob->move(environment(this_object()));
        destruct(this_object());
}

