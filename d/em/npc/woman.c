//Cracked by Roath
// /d/emei/npc/woman.c
// Shan: 96/07/08

inherit NPC;

void create()
{
        set_name("年轻少妇", ({ "young woman", "woman" }) );
        set("gender", "女性" );
        set("age", 21);
        set("long", 
"一个年轻少妇，看样子是从一个富裕人家来的，要去峨嵋山进香许愿。\n");
	set("shen_type", 1);
	set("combat_exp", 1000);
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 15);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/pinkcloth")->wear();
	add_money("silver", 4);
}

