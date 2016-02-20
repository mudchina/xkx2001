//Cracked by Roath
// xiao_tufei.c

inherit NPC;

void create()
{
        set_name("小土匪", ({"xiao tufei", "tufei"}));
        set("gender", "男性" );
        set("age", 16+random(8));
        set("long", "这是个胆大包天的小土匪，杀人越或货，无恶不做。\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 150);
		set("shen", -15);
//		set("shen_type", -1);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude","aggressive");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 30);
}

