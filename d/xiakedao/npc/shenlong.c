//Cracked by Roath
// chi.c 侠客岛神龙赤龙门弟子
inherit NPC;
#include <ansi.h>
string* menpai = ({
	"say 
          我们教主神通广大，天下第一。教主夫人美如天仙。教中
五龙使，胖瘦头陀，个个武功高强。化骨绵掌，美人三招，都是武林
绝学。岛上弟子还能学挖陷井"+HBRED+HIW"(trap)"NOR +"，可用来击杀高手。",
});
int ask_menpai(string* message);

void create()
{
	set_name("神龙女弟子", ({ "chilong dizi","dizi" }) );
	set("gender", "女性");
	set("age", 15+random(10));
        set("long",
		"这是赤龙门弟子，年纪都很小，似乎不谙世事。\n");
	set("combat_exp", 100);
        set("shen_type", -1);
        set("attitude", "heroism");

	set("apply/attack",  15);
	set("apply/defense", 15);

	set("jingli",100);

	create_family("神龙教", 4, "弟子");
	set("inquiry", ([
			"神龙岛"   :  (: ask_menpai, menpai:),
		]));

      setup();
	switch( random(3) )
        {
                case 0:
			carry_object("/clone/weapon/gangjian")->wield();
			break;
                case 1:
			carry_object("/clone/weapon/changjian")->wield();
                        break;
                case 2:
			carry_object("/clone/weapon/duanjian")->wield();
                        break;
        }

        carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 20);
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
	{	command("flirt " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + 
		"来我们神龙岛吧，我们那最多少年少女。\n" +
		"你有什麽问题问我就好啦。"+HBRED+HIW"(ask dizi about 神龙岛)"NOR +"或试试 \n" +
		HBRED+HIW"(help shenlong)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
