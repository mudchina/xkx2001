//Cracked by Roath
// xiaolan.c

inherit NPC;

void create()
{
	set_name("蕊初",({ "ruichu" }) );
        set("gender", "女性" );
        set("age", 18);
        set("long", "这是一个容貌秀丽的小姑娘，似乎有点心神不定。\n");

//      set("shen", -100);
        set("shen_type", 1);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("combat_exp", 2000);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
        set("attitude", "peaceful");
        setup();

        carry_object("/d/taihu/obj/red_cloth")->wear();
	add_money("coin", random(1000));
}

