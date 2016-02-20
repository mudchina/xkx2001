//Cracked by Roath
// kid.c

inherit NPC;

void create()
{
	set_name("牧童",({ "boy" }) );
        set("gender", "男性" );
        set("age", 13);
        set("long", 
		"这是个牧民少年，大概因从小放羊，虽然年纪不大，可已长的很粗壮了。\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	set("shen_type", 1);
//	set("shen", 100);
        set_temp("apply/defense", 7);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

        carry_object("/d/village/npc/obj/cloth")->wear();
	add_money("coin", random(50));
}

