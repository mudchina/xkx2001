//Cracked by Roath
// xiao_louluo.c

inherit NPC;

void create()
{
        set_name("小喽罗", ({"xiao louluo", "louluo"}) );
        set("gender", "男性" );
        set("age", 14+random(8));
        set("long", "这是一个年纪不大的小喽罗，象是第一次出来做这无本生意。\n");

        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set("combat_exp", 50);
//		set("shen_type", -1);
        set("shen", -15);
        set("str", 10+random(10));
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","aggressive");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 10);
}
