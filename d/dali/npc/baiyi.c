//Cracked by Roath
inherit NPC;

void create()
{
        set_name("摆夷女子", ({ "girl" }));
        set("long", 
"她是一个身着白衣的摆夷女子，长发飘飘，身态娥娜。\n"
"她长的颇有几分资色。\n");
        set("gender", "女性");
        set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        setup();


	 carry_object("/d/dali/obj/wcloth")->wear();

}


