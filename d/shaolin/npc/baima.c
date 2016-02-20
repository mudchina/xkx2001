//Cracked by Roath
// baima.c 白马

inherit NPC_TRAINEE;

int return_home(object home);

void create()
{
	set_name("白马", ({ "bai ma", "ma", "horse" }) );
	set("race", "家畜");
	set("age", 10);
	set("long", "这是一匹白色的大宛马，生得龙颈狮鬃，四蹄飞青，确是匹罕见的千里马。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，人立起来！");
	set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
	set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
	set("auto_follow",1);
	set("attitude", "peaceful");

	set("wildness", 5);
	
	set("str", 30);	
	set("con", 40);
	set("dex", 40);	
	set("int", 20);

	set("max_tili", 1000);
	set("combat_exp", 10000);
	set_weight(100000);

	setup();
}

int return_home(object home) 
{
	return 1;
}
