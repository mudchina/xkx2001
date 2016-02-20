//Cracked by Roath
// shopkeeper.c 

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("陈老板", ({ "chen laoban", "lao ban", "chen", "laoban" }));
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 45);
        set("long",
                "他是平定州杂货铺的老板，在这里做了十几年的买卖。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/heimuya/obj/fengguan",
                "/d/heimuya/obj/magua",
                "/d/heimuya/obj/xiapi",
                "/d/heimuya/obj/chaoxue",
                "/d/heimuya/obj/flower-shoe",
                "/d/heimuya/obj/pnecklace",
                "/d/xingxiu/npc/obj/fire",
        }));
        
        setup();
}

void init()
{
        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
