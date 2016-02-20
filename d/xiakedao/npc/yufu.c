//Cracked by Roath
// yufu.c 侠客岛渔夫
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();
int do_enter();
void greeting(object);

void create()
{
	set_name("渔夫", ({ "yu fu", "fu"}));
	set("long", "他看过去象个普普通通的渔夫，满脸堆着笑容。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("cuff", 30);
	set_skill("sword", 30);
	
	set("inquiry", ([
			"侠客岛" :	"这里就是侠客岛。两位岛主每年都派弟子到中原，找寻资质不凡的少年上岛。你就是今年被选上的吧。\n",
			"船"     : 	"那船是我的。\n",
			"中原"   : 	(: ask_leave :),
			"岛主"   : 	"岛主好象在後山\n",
			"离岛"   :  (: ask_leave :),
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

void greeting(object me)
{	object room;
	if ((int)me->query_temp("marks/离") == 1)
	{	
		command("say 恭喜，恭喜。你可以回中原了。");
	}
	else if ((int)me->query_temp("marks/离") == 2)
	{	
		command("whisper " + me->query("id") + " 快上船吧。别被别人看到了。(enter)");
	}
	else
	{	if (me->query_temp(this_object()->query("id")) == 0 )
		{	command("hi " + me->query("id"));
			command("say 
          你不妨四处看看(look)。地上有什麽东西你都可以捡起来
    (get)收着。你可以先查查(i or inventory)看你现在身上有些什
    麽。你要不时地查查(hp)你的身体状态，要是饿了或渴了就去找
    些吃的喝的吧。你要是有什麽问题可以问我。
    "+HBRED+HIW"(ask fu about 侠客岛，ask fu about 离岛)"NOR);
			me->set_temp(this_object()->query("id"), 1);

		}
	}
}
int ask_leave()
{	object me = this_player();
	if ((int)me->query_temp("marks/离"))
	{	
		command("say 恭喜，恭喜。你可以回中原了。");
	}
	else
	{	command("shake " + me->query("id"));
		command("say 要去中原可得要岛主同意才行，我也不敢私自出海。等你\n" +
			"功夫有点小成，岛主就会让你离岛回中原去闯天下了。");
	}
	return 1;
}
int accept_object(object me, object ob)
{	
	if (ob->query("id") != "fish")
	{	message_vision("渔夫对$N摇了摇头，说道：你自己留着吧。\n", me);
		return 0;
	}
	if (ob->query("speical") == 0)
	{	message_vision("渔夫接过$N手中的$n看了看，对$N摇了摇头说道：这种鱼到处都是，自己留着吧。\n", me, ob);
		return 0;
	}
	message_vision("渔夫兴高采烈地接过$N手中的$n。\n", me, ob);
	command("whisper " + me->query("id") + " 你过一会儿再回来，可别被别人看到了。");
	me->set_temp("marks/离", 2);
	return 1;
}
