//Cracked by Roath
// npc: /d/xingxiu/npc/maimaiti.c
// Jay 3/17/96

inherit NPC;
inherit F_VENDOR;


void create()
{
        set_name("买卖提", ({ "maimaiti", "seller" }) );
        set("title", "杂货铺老板");
        set("shen_type", 1);

        set("gender", "男性" );
        set("age", 43);
        set("long", 
"买卖提是个中年维吾尔族商人，去过几次中原，能讲一点儿汉话。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("rank_info/respect", "大叔");

 
        set("vendor_goods", ({
                __DIR__"obj/hu",
                __DIR__"obj/nang",
                __DIR__"obj/fire",
                __DIR__"obj/hamigua",
                __DIR__"obj/dongbula",
		__DIR__"obj/liuhuang",
		__DIR__"obj/si-cloth",
		"/d/quanzhou/obj/xiuhua",
		"/clone/weapon/biandan",
        }) );

        set("inquiry", ([
                "马" : "要说好马还得数咱们伊犁马",
                "伊犁马" : "嗨，都让赛马的那帮姑娘小伙买光了。",
        ]) );

        setup();
        carry_object(__DIR__"obj/wcloth")->wear();
        add_money("coin", 100);
}
void init()
{
        object ob;
        ::init();
        add_action("do_buy", "buy");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "买卖提笑嘻嘻地说道：色兰姆阿里空\n");
                        break;
                case 1:
                        say( "买卖提右手放在胸前，浅鞠一躬说道：阿里空色兰姆\n");
                        break;
        }
}

