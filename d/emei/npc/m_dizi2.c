//Cracked by Roath
// /d/emei/npc/m_dizi2.c 男弟子 
// Shan: 96/07/09

#include <ansi.h>

inherit NPC;

string ask_me(string);

void create()
{
	set_name("男弟子", ({ "dizi", "nan dizi" }));
	set("long", 
        "他是峨嵋山的第五代弟子，是在华严庵守庵的小弟子。\n");
	set("gender", "男性");
	set("age", 14+random(5));
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20+random(2));
	set("int", 20+random(2));
	set("con", 21+random(2));
	set("dex", 24+random(2));
	
	set("max_qi", 100+random(60));
	set("max_jing", 100+random(50));
	set("neili", 140+random(30));
	set("max_neili", 140+random(30));

	set("combat_exp", 2000+random(200));
	set("score", 1000+random(200));

	set_skill("force", 25+random(5));
        set_skill("dodge", 20+random(4));
        set_skill("unarmed", 20+random(2));
        set_skill("parry", 20+random(3));
        set_temp("apply/attack", 15+random(4));
        set_temp("apply/defense", 15+random(3));
        set_temp("apply/damage", 5+random(2));

	create_family("峨嵋派", 5, "弟子");

	setup();
	
	carry_object(__DIR__"obj/hui-cloth")->wear();
        set("chat_chance", 3);
        set("chat_msg", ({
		"峨嵋小弟子道：这就是古心和尚结茅室的地方。\n",
        }) );

        set("inquiry", ([
                "玉女峰" : (: ask_me, "yunufeng" :),
        ]));

}

string ask_me(string name)
{

       if ( name == "yunufeng" )
        say(CYN "\n小弟子道：玉女峰顶有个小池子，四季不枯，听说以前有天女在那里沐浴呢！ \n\n" NOR);

}

