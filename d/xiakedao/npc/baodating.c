//Cracked by Roath
// baodating.c 
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

void greeting(object);

string *home_locations = ({
	"/d/xiakedao/shatan",
	"/d/xiakedao/pubu",
	"/d/xiakedao/dadong",
	"/d/xiakedao/xiakexing1",
});

string* secret = ({
	"你可以用 "+HBRED+HIW+"help"NOR+" 来查一些基本的东西，但如果你想知道其他的。",
	"听说武当掌门弟子宋大侠那儿有本秘籍是用来学内功的。",
	"听说少林寺中的竹林里有一块刻着轻功秘诀的旧竹片。",
	"听说华山绝顶上有一个藏着上乘剑法的山洞。",
	"听说失传已久的鸳刀出现在扬州附近的密林中。",
	"听说武当山下的松林中可以拾到对武林中人有极大补益的人参果。",
	"听说少林寺碑林下有一张刻着上乘拳掌功夫的石桌。",
});

string *greet = ({
	"你可知道当今武林都有哪些门派？",
	"你可知道每个门派的来历？",
	"你可知道每个门派有哪些武功？",
	"你可知道每个门派都有些什麽人物？",
});
	
void create()
{
	set_name("吴不至", ({ "wu buzhi", "wu"}));
	set("nickname", "包打听");
	set("long", 
"一位干瘦的小老头儿，两眼骨噜噜乱转，一副精明的样子。据说他知
道很多武林秘密。\n");
	set("gender", "男性");
	set("age", 60);
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
	set("combat_exp", 10000);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("cuff", 20);
	set_skill("sword", 20);
      set("chat_chance", 2);
	set("chat_msg", 
	    ({
      	"包打听道: 天下事我无所不知，我不知道的那一定没人知道了。\n",
      	"包打听道: 你想知道些秘密吗？\n",
      	"包打听道: 听说这侠客岛的溪水里有一种怪鱼。\n",	
      	"包打听道: 听说侠客岛的两位岛主已在侠客洞静修了四十年了。\n",	
      	"包打听道: 听说侠客洞里的武功是天下第一，但没人学会呢。\n",	
		(: random_move :),
	    }) );

	setup();
}

void init()
{
        object me = this_player();        
	  object home;
        home = load_object(home_locations[random(sizeof(home_locations))]);
//	  move(home);

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	int total, i;
	total = sizeof(greet);
	i = random(total);
//	command("say " + i);
//	command("say 你想知道吗？");
	command("say " + greet[i] + "你想让我告诉你
吗？我告诉你，你有些什麽表示呢？");
}
int accept_object(object who, object ob)
{	object me = this_player();
	int count;
	count = (int) me->query_temp("secret");
	if (count == -1)
	{	command("say 烦不烦啦你，有完没完了。\n");
		command("dunno "+ me->query("id"));
		return 1;	
	}
	if (random(5) > 2)
	{	command("whisper " + me->query("id") + " 你干嘛不试试"+HBRED+HIW"help"NOR+"。");
		return 1;
	}
	if (count == 0)
	{	
		command("papaya " + me->query("id") );
		command("whisper "+ me->query("id") + " " + (secret[count]));
		command("hehe " + me->query("id"));
		count = count + 1;
	}
	else if (count < sizeof(secret))
	{	command("whisper "+ me->query("id") + " " + secret[count]);
		count = count + 1;
	}
	else
	{	count = -1;
	}
	me->set_temp("secret", count);
	return 1;
}
