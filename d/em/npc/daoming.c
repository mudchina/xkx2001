//Cracked by Roath
// d/emei/npc/daoming.c 道明小师父
// Shan 96/09/24

inherit NPC;

void greeting(object);
void init();

void create()
{
	set_name("道明小师父", ({"daoming", "dao ming"}) );
	set("rank_info/respect", "小师父");
	set("gender", "男性" );
	set("age", 14+random(6));
	set("long",
	  "这是个年龄不大的小师父。他见有人来到，轻轻点头笑了笑。\n");
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

		set("combat_exp", 2000+random(200));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("峨嵋派", 5, "弟子");

//        set("inquiry", ([
//            "出家" : "您去问那边的静和师叔吧。\n",
//        ]));

        setup();
        
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
}

void init()
{	
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	say("道明小师父轻声说道：欢迎来保国寺藏经楼。您要读经书吗？\n");
}

