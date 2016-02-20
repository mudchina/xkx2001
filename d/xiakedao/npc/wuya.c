//Cracked by Roath
// wuya.c 乌鸦

inherit NPC;

void create()
{
        set_name("乌鸦", ({ "wuya", "bird" }) );
        set("race", "飞禽");
        set("age", 4);
        set("long", "一只黑乎乎的乌鸦。\n");
        set("attitude", "peaceful");

        set("combat_exp", 120);

        set("chat_chance", 10);
        set("chat_msg", ({
                "乌鸦无聊地嘎嘎乱叫着，在你头顶上飞来飞去。\n",
                "乌鸦忽然飞上树梢，盯着你看。\n",
	    }) );

        set("chat_msg_combat", ({
                "乌鸦“嘎～”的一声，全身的羽毛都抖竖起来！\n",
	    }) );

        setup();
}








