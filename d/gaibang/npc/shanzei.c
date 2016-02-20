//Cracked by Roath
// shanzeitou.c

inherit NPC;

void create()
{
        set_name("山贼", ({ "shanzei","bandit","zei","shanzei" }) );
        set("gender", "男性");
        set("age", 15 + random(15));
        set("long",
                "这家伙满脸杀气，一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 500000 + random(25000));
        set("shen_type", -50+ random(25));
        set("attitude", "aggressive");

        set("str", 15 + random(5));
        set("int", 18 + random(5));
        set("con", 15 + random(5));
        set("dex", 20 + random(5));
        set("max_qi", 300 + random(50));
        set("max_jing", 300 + random(50));
        set("neili", 450 + random(50));
        set("max_neili", 450 + random(50));

        set("apply/attack",  50 + random(25));
        set("apply/defense", 50 + random(25));

        set("chat_chance", 10);
        set("chat_msg", ({
                "山贼嘿嘿地冷笑着: 此山是我开，此树是我栽，若要从此过，留下买路财！\n",
        	(: random_move :)
	}) );

        set_skill("stick", 60 + random(10));
        set_skill("parry", 65 + random(10));
        set_skill("strike", 65 + random(10));
        set_skill("force", 60 + random(10));
        set_skill("dodge", 65 + random(20));

        setup();
        carry_object("/clone/weapon/tiebang")->wield();
        carry_object("/clone/armor/beixin")->wear();
        add_money("silver", 10+ random(10));
}

