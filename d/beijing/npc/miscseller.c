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
  	set("chat_chance", 10);
	set("chat_msg", ({
	"小贩叫卖道：客官，买份京城的地图吧，东南西北都清楚啊。\n",
	"小贩叫卖道：客官，买顶草帽吧，春夏秋冬都管用啊。\n",
        "小贩自言自语道：这京城可大啦，没有地图你可那儿都找不着。\n",
        "小贩自言自语道：您瞧这天，没准儿要下雨啦，没草帽哪行啊。\n",
	}));
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/beijing/obj/map",
                "/d/beijing/obj/caomao",
        }) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin", 60);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
