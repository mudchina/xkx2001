//Cracked by Roath
// quanjude_xiaoer.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("店小二", ({ "seller" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是全聚德的店小二，想吃烤鸭赶紧向他买吧。\n");
        set("combat_exp", 10000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city/obj/kaoya",
                "/d/city/obj/jiudai",
        }) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("silver", 10);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
