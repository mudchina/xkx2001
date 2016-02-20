//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("花帽摊贩", ({ "tan fan", "seller", "fan" }) );
        set("gender", "男性" );
        set("age", 45);
        set("long",
                "这是个中年回族男子，在巴扎贩卖各种手工花帽。\n");
        set("shen_type", 1);
        set("combat_exp", 1000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set("vendor_goods", ({
                "/d/xingxiu/obj/huamao2",
                "/d/xingxiu/obj/huamao1",
                "/d/xingxiu/obj/huamao3",
        }) );
        setup();
        add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
