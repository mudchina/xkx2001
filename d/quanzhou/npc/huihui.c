//Cracked by Roath
// huihui 回回

inherit NPC;

void create()
{
        set_name("回回", ({ "huihui", "hui", "muslim" }));
        set("gender", "男性");
        set("age", 20 + random(40));

        set("long", "一个虔诚回回，正跪在地上向西方膜拜。\n");

        set("attitude", "friendly");

        set("combat_exp", 4000);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);

        setup();

        set("chat_chance", 15);
        set("chat_msg", ({
		"回回说：穆罕默德瑞素阿拉，伟大至尊的阿拉。\n",
        }) );
}

