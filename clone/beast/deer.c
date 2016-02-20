//Cracked by Roath

inherit NPC;

void create()
{
	set_name("梅花鹿", ({ "deer" }) );
	set("race", "家畜");
	set("age", 5);
	set("long", "一只漂亮的梅花鹿。\n");
	set("attitude", "peaceful");
	
//	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 800);

	set("chat_chance", 6);
	set("chat_msg_combat", ({
                "\n梅花鹿一转身，扬起鹿角朝你顶过来！\n",
        }) );
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	setup();
}

	
