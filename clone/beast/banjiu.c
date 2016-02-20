//Cracked by Roath
// banjiu.c 斑鸠

inherit NPC;

void create()
{
	set_name("斑鸠", ({ "ban jiu", "bird"}) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一只的小斑鸠。\n");
	set("attitude", "peaceful");
	
        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 100);

	set_temp("apply/attack", 2);
	set_temp("apply/defense", 6);
	set_temp("apply/damage", 1);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
	object ob = new(__DIR__"obj/banjiu-rou");

	message_vision("$N从树上掉下来，死了。\n", this_object());
	ob->move(environment(this_object()));
	destruct(this_object());
}

