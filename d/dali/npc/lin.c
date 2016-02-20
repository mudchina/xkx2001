//Cracked by Roath
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("林老板", ({ "lin laoban", "seller", "lin" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
 "林老板是龙光阁的少东家，看上去一团和气。\n");
        set("combat_exp", 12000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");

	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 30);

        set("vendor_goods", ({
	"d/shaolin/obj/fojing10.c",
	"d/shaolin/obj/fojing20.c",        
}) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("gold", 1);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

