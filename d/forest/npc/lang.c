//Cracked by Roath
//lang.c 狼

inherit NPC;

void create()
{
	set_name("狼", ({ "lang", "wolf" }) );
	set("race", "野兽");
	set("age", 15);
	set("long", "这是一头灰色的狼，正用红色的眼睛盯着你，不时发出令人胆战的嗥声！\n");
	set("attitude", "aggressive");
	
	set("str", 40);	
	set("con", 40);
	set("dex", 40);	
	set("int", 10);

	set("combat_exp", 2000);

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor",  20);

	set("chat_chance", 10);
	set("chat_msg", ({
		"狼发出一声嗥叫，好象随时都要扑上来！\n",
		"狼的双目在黑暗中闪着红光，紧紧地注视着你的一举一动。\n",
	}) );
	
	setup();
}


