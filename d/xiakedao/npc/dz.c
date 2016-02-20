//Cracked by Roath
// daozhu1.c 侠客岛龙岛主
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();

void create()
{
	set_name("龙岛主", ({ "long daozhu", "long", "daozhu"}));
	set("long", "他鬓眉全白，脸色红润，有如孩童。\n");
	set("gender", "男性");
	set("age", 70);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 35);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 2000);
	set("eff_qi", 2000);
	set("qi", 2000);
	set("max_jing", 2000);
	set("eff_jing", 2000);
	set("jing", 2000);
	set("max_neili", 3000);
	set("eff_neili", 3000);
	set("neili", 3000);
	set("max_jingli", 2000);
	set("eff_jingli", 2000);
	set("jingli", 2000);
	set("combat_exp", 2000000);
	set("score", 100000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("cuff", 200);
	set_skill("sword", 200);
	
	set("inquiry", ([
			"中原"   : 	(: ask_leave :),
			"离岛"   : 	(: ask_leave :),
			
		]));
	setup();
}
void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{	mapping skl;
	skl = me->query_skills();

	if ((int)me->query("combat_exp") < 250)
	{	say("龙岛抬头望了你一眼，说道：经验善浅。\n");
		return 0;
	}
	if (sizeof(skl) < 10)
	{	say("龙岛抬头望了你一眼，说道：功夫不够。\n");
		return 0;
	}
	say("龙岛抬头望了你一眼，微微一笑道：你去吧。\n");
	me->set_temp("marks/离", 1);

}

int ask_leave()
{	
	say("龙岛主对你不理不睬，只是凝望着石壁出神。\n");
	return 1;
}
