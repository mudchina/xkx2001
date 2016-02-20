//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("再尔格尔", ({ "zaier ger", "ger", "man" }) );
        set("gender", "男性" );
        set("title","手艺工匠");
        set("age", 30);
        set("long", "这是一位技艺娴熟的老工匠，以世代相传的手法制造首饰、玉石器具。\n"
        "“再尔格尔”是维吾尔语，意思是制做金银宝石手艺的工匠。\n");
        set("shen_type", 1);
        set("combat_exp", 8000);
        set("str", 18);
        set("dex", 20);
        set("con", 16);
        set("int", 20);
        set("attitude", "peaceful");
        set("vendor_goods", ({
		"/d/xingxiu/obj/yeguang",
		"/d/xingxiu/obj/necklace",
		"/d/xingxiu/obj/earring",
        }) );
        setup();
        add_money("silver", 5);
	carry_object("/clone/armor/wcloth")->wear();

}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
