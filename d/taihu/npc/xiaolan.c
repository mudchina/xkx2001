//Cracked by Roath
// xiaolan.c

inherit NPC;

void create()
{
	set_name("小兰",({ "xiao lan", "lan" }) );
        set("gender", "女性" );
        set("age", 18);
        set("long", "一个模样乖巧的小丫环，扎两个发环，眼睛大大的，嘴角浅浅一对酒窝。\n");

//      set("shen", -100);
        set("shen_type", 1);
        set("str", 15);
        set("dex", 18);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 2000);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
        set("attitude", "peaceful");
        setup();

        carry_object("/d/taihu/obj/red_cloth")->wear();
	add_money("coin", random(1000));
}

