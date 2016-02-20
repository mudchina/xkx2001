//Cracked by Roath
// xingxiu.c 星宿弟子
// Ssy

#include <ansi.h>
inherit NPC;
string* menpai = ({
	"say 
          星宿派的开山祖师丁春秋，师承是逍遥派。逍遥派的武功
是道家一脉，但是丁老仙一生精於炼毒，已不同於道家的炼丹。星宿
派的功夫基本都是丁老仙叛师後自创，主要在毒字上下的功夫。掌上
带毒、暗器上带毒、化功大法吸人内力，江湖上人提起，无不谈虎色
变。",
});
int ask_menpai(string* message);

void create()
{
        set_name("黑梦子", ({ "xingxiu dizi", "dizi", "heimeng"}));
        set("long", 
                "他是星宿派高手，看上去功力深厚，你要是没有把握可别惹他。\n"
                "他手中拿着一对铜钹，一边敲一边扯着嗓子唱些肉麻的话。\n");
        set("gender", "男性");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);

        set("combat_exp", 250);


        create_family("星宿派", 2, "弟子");
	set("inquiry", ([
			"星宿"   :  (: ask_menpai, menpai:),
		]));

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
"黑梦子敲着铜钹，高声唱道，“星～宿～老～仙，威～震～寰～宇”。\n",
"黑梦子敲着铜钹，高声唱道，“星～宿～老～仙，德～配～天～地”。\n",
"黑梦子敲着铜钹，高声唱道，“星～宿～老～仙，古～今～无～比”。\n",
        }) );

        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
        carry_object("/d/xingxiu/obj/tongbo")->wield();
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
	{	
	        command("hehe " + me->query("id"));
		command("say " + RANK_D->query_respect(me) + 
			"星宿老仙武功天下第一，只要你马屁功高，\n"+
			"就能出人投地。你有什麽问题问我就好啦。\n"+
			HBRED+HIW"(ask heimeng about 星宿)"NOR + " 或 "+HBRED+HIW"(help xingxiu)"NOR +"。");
		me->set_temp(this_object()->query("id"), 1);
	}
	
}

#include "/d/xiakedao/npc/xkdnpc.h"
