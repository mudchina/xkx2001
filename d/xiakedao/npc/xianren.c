//Cracked by Roath
// puren.c 侠客岛闲人
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();
void greeting(object);

void create()
{
	set_name("闲人", ({ "xian ren", "xian"}));
	set("long", "他是岛上一个游手好闲的人。\n");
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
	set("combat_exp", 1000);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("cuff", 20);
	set_skill("sword", 20);
	
	set("inquiry", ([
			"中原"   : 	(: ask_leave :),
			"岛主"   : 	"岛主好象在後山\n",
			
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
{	if (me->query_temp(this_object()->query("id")) == 0 )
	{	command("pat " + me->query("id"));
		command("say 
         这位" + RANK_D->query_respect(me) + 
	          "来侠客岛多久啦？我可在这呆了二三十年了。在
   这儿练功之余可以和别人闲聊（ｃｈａｔ）来交流交流感情。还可
   以散布些谣言（ｒｕｍｏｒ）。闲聊和散布谣言时可以用一些已经
   有了的动作。你可以试试 chat* hi。 用ｓｅｍｏｔｅ可以查出哪
   些是已经有了的动作。如果你话太多惹人厌就会被人投票关闭交谈
   频道。(vote chblk xxx)频道被关了后只有等别人投票打开。(vote
   unchblk xxx)如果你想找人聊天而不想让其他人听到，你可以告诉
   （ｔｅｌｌ）他(她)。有人告诉你什麽事，你可以用（ｒｅｐｌｙ）
   来回答他(她)。你还可以跟某一位与你在同一房间的人讲悄悄话
   （ｗｈｉｓｐｅｒ）。江湖上不少人沉迷在武功之中，然而我觉得
   还是闲聊交友更有趣。你好自为之吧。");
		command("yawn");
		me->set_temp(this_object()->query("id"), 1);
	}

}
int ask_leave()
{	command("shake ");
	command("say 没有岛主同意，你可不能私自离岛。");
	return 1;
}
