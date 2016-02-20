//Cracked by Roath
// d/emei/npc/wenfang.c 文方小师太
// Shan 96/07/09

inherit NPC;

void create()
{
	set_name("文方小师太", ({"wenfang", "wen fang"}) );
	set("rank_info/respect", "小师太");
	set("gender", "女性" );
	set("age", 12+random(6));
	set("long",
	  "这是个年龄不大，眉清目秀的小师太。\n");
	set("attitude", "friendly");
    	set("shen_type", 1);
        set("class", "bonze");

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

		set("combat_exp", 1000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("峨嵋派", 5, "弟子");

        set("inquiry", ([
            "出家" : "您去问那边的静空师父吧。\n",
        ]));

        setup();
        
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

