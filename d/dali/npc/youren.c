//Cracked by Roath
inherit NPC;

void create()
{
        set_name("游人", ({ "you ren", "ren" }) );
        set("gender", "男性" );
        set("age", 22+random(30));
        set("int", 28);
        set("long",
                "这是外出游览的普通百姓。\n");

        set("attitude", "peaceful");
        set("combat_exp", 400+random(2200));
        set_skill("literate", 40);
        setup();
}

