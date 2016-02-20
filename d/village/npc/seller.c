//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("小贩", ({ "seller" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/stick",
                __DIR__"obj/shoes",
                __DIR__"obj/bottle",
                __DIR__"obj/egg",
                __DIR__"obj/fire",
                __DIR__"obj/rope",
                "/clone/food/corn",
        }) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin", 60);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

