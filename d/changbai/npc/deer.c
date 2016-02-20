//Cracked by Roath
// yetu.c 野兔

inherit NPC;

void create()
{
	set_name("梅花鹿", ({ "meihua lu", "lu", "deer" }) );
	set("race", "家畜");
	set("age", 5);
	set("long","一只温顺的梅花鹿，睁着圆圆的眼珠望着你，显得十分好奇。\n");
	set("attitude", "peaceful");
	
//	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);
//	set("shen_type", 0);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 12);
	set_temp("apply/armor", 11);

	setup();
}

void die()
{
	object ob;
	message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
	ob = new(__DIR__"lurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
