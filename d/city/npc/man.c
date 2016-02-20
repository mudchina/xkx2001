//Cracked by Roath
// poorman.c

inherit NPC;

void create()
{
        set_name("壮汉", ({ "man", "han" }) );
        set("gender", "男性" );
        set("age", 33+random(10));
        set("long", "一个结实的壮汉。\n");
        set("attitude", "peaceful");
        set("combat_exp", 1500);
//	set("shen", 50);
	set("shen_type", 1);
        set("str", 20);
        set("dex", 18);
        set("con", 17);
        set("int", 13);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", random(10));
}

