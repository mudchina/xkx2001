//Cracked by Roath
// /d/quanzhou/npc/seller2.c 摊贩
// Shan: 96/07/09

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("摊贩", ({ "tan fan", "seller", "fan" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long",
"这是个机灵能干的小摊贩，摆弄着摊子里的各种武器，药品，大声向来往江湖客吆喝着。\n");
	set("shen_type", 1);
	set("combat_exp", 60000);
        set("str", 26);
        set("dex", 25);
        set("con", 22);
        set("int", 23);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/quanzhou/npc/obj/renshen-guo",
		"/clone/weapon/changjian",
		"/clone/weapon/wandao",
		"/clone/weapon/hammer",
		"/clone/weapon/stick",
		"/clone/weapon/zhubang",
		"/d/city/obj/jinchuang",
                "/d/village/npc/obj/bottle",
		"/clone/food/jiudai",
		"/clone/food/kaoya",
	}) );
	setup();
        carry_object("clone/misc/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

