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
	
//	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set_weight(300);

	set("combat_exp", 100);
	//set("shen_type", -1);
	set("env/wimpy", 70);

	set_temp("apply/attack", 5);
//	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
        object ob;
        message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
        ob = new("/d/quanzhou/obj/shurou");
        ob->move(environment(this_object()));
        destruct(this_object());
}

