//Cracked by Roath
// zhangzi.c 獐子

inherit NPC;

void create()
{
	set_name("獐子", ({ "zhang zi", "zhang", "deer" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一匹小獐子，长得象小鹿，头上没有角。\n");
	set("attitude", "peaceful");
	
        set("str", 20);
        set("dex", 30);

//	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 150);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 2);

	setup();
}

void die()
{
	object ob;
	message_vision("$N凄惨的嚎了几声，倒在地上死了。\n", this_object());
	ob = new("d/gaibang/obj/zhangrou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
