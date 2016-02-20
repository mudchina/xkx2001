//Cracked by Roath
// shanzeitou.c

inherit NPC;

void create()
{
        set_name("山贼头", ({ "shanzei tou","bandit leader","tou","shanzei" }) );
        set_color("$RED$");
        set("gender", "男性");
        set("age", 35 + random(20));
        set("long",
                "这家伙满脸杀气，一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 100000 + random(25000));
        set("shen_type", -100);
        set("attitude", "aggressive");

        set("str", 18 + random(5));
        set("int", 22 + random(5));
        set("con", 18 + random(5));
        set("dex", 25 + random(5));
        set("max_qi", 650 + random(250));
        set("max_jing", 300 + random(250));
        set("neili", 850 + random(250));
        set("max_neili", 850 + random(250));

        set("apply/attack",  50 + random(25));
        set("apply/defense", 50 + random(25));

        set("chat_chance", 10);
        set("chat_msg", ({
                "山贼头嘿嘿地冷笑着: 此山是我开，此树是我栽，若要从此过，留下买路财！\n",
        	(: random_move :)
	}) );

        set_skill("stick", 90 + random(30));
        set_skill("dagou-bang", 85+ random(30));
        set_skill("parry", 85 + random(30));
        set_skill("strike", 85 + random(30));
        set_skill("force", 95 + random(30));
        set_skill("huntian-qigong", 95 + random(30));
        set_skill("dodge", 100 + random(30));

        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        map_skill("force", "huntian-qigong");

        setup();
        carry_object("/d/gaibang/obj/tongbang")->wield();
        carry_object("/clone/armor/wushifu")->wear();
        carry_object("/clone/armor/toukui")->wear();
        carry_object("/d/city/obj/chaoxue")->wear();
        add_money("silver", 50+ random(50));
}

