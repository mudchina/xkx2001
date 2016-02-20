//Cracked by Roath
// copy from zhu.c 朱熹
// CLEANSWORD 1996/2/2
// Jay 9/11/96, added degree

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老学士", ({ "shi", "xue shi" }));
        set_color("$YEL$");
	set("long", "他是个精通诗理的学者，原本是被逼而来到侠客岛，但学了武功後死\n心塌地的留了下来。\n");
	set("gender", "男性");
	set("age", 65);
        set("max_jing", 200);
        set("max_qi", 200);
	set_skill("literate", 200);

	set_temp("apply/attack", 14);
	set_temp("apply/defense", 14);
	set_temp("apply/damage", 30);

	set("combat_exp", 400);
	set("shen_type", 1);

	set("inquiry", ([
		"学位" : "读书作官哪里比得上学武练功强？\n",
		"科举" : "读书作官哪里比得上学武练功强？\n",
	]));

	setup();
	carry_object(__DIR__"obj/yellowrobe")->wear();

/*	set("chat_chance", 3);
	set("chat_msg", ({
	}) );
*/
}

int recognize_apprentice(object ob)
{	if (ob->query_skill("literate", 1) <= 20)
	{	ob->set_temp("mark/朱", 1);
		return 1;
	}
	else
	{	ob->delete_temp("mark/朱", 1);
		return 1;
	}
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

void greeting(object me)
{
	if (me->query_skill("literate", 1) == 0 )
	{	command("say " + RANK_D->query_respect(me) + 
			"虽说练武比读书重要，但你目不识丁，如何去理
解那侠客行武功秘籍呢？");
		command("say 你可以跟我学点读书(xue " + query("id") + " literate)");
	}
	else 
	{	if (me->query_skill("literate", 1) >= 20 )
		{	command("say 快去练武吧，读那麽多书考状元哪？");
		}
	}
}

