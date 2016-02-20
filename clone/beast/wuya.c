//Cracked by Roath
// Jay 5/23/96

inherit NPC;

void create()
{
        set_name("乌鸦", ({ "wuya", "crow" }) );
        set("race", "飞禽");
        set("age", 3);
        set("long", "一只黑色的乌鸦，丑陋极了。\n");
        set("attitude", "peaceful");

//      set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
//      set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
		"乌鸦「嘎嘎」叫了几声。\n",
		"乌鸦叫道：「嘎嘎」。\n",
            "乌鸦在你眼前飞上飞下。\n",
        }) );
}
