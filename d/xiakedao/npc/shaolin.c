//Cracked by Roath


inherit NPC;
string* menpai = ({
	"say 
          少林武技，名显于世，始于隋末。当时少林寺有十三武僧
    ，应秦王李世民之邀，出山参加了讨平王世充的战役，他们凭着
    超群的技艺，活擒王世充的侄儿王仁则，逼降王世充。胜利后论
    功行赏，除昙宗一人受封大将军外，其余十二人不愿受封，回归
    少林，但均获赐紫罗袈裟，另赐少林寺大量的田地、银两，并赐
    「立僧兵」、「酒肉」等「荣宠」！自此少林寺遂以武功闻名于
    世。 ",
});
int ask_menpai(string* message);

void create()
{
	set_name("澄沧", ({
		"xiao heshang",
		"seng",
		"cang",
	}));
	set("long",
		"他虽只是个十来岁的小和尚，但看他那样子似乎有点武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 125);
	set("score", 1000);


	create_family("少林派", 37, "弟子");
	set("inquiry", ([
			"少林"   :  (: ask_menpai, menpai:),
		]));

	setup();

      carry_object("/d/shaolin/obj/qing-cloth")->wear();
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
	{	command("buddhi " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + 
            "你一看过去就是和佛有缘之人，出家吧。你\n" + 
	    "有什麽问题问我就好啦。(ask seng about 少林)或(help shaolin)。");
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
