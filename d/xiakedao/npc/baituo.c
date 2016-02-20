//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，白驼庄婢女
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          武林中人谈起白驼山无不变色。庄主西毒欧阳峰更是武林
    中第一高手。庄主的蛤蟆功独步武林，不但可以伤人，还可与人
    聊毒。白驼的毒功和星宿毒功乃天下两大奇功。庄主最护短，要
    是弟子在外被欺，他会为你出头。",
});
int ask_menpai(string* message);

void create()
{
	set_name("貂蝉", ({ "diaochan" }));
	set("long", "一个二十来岁的男装女子，面貌清秀，但眉间眼角透着一股邪气。却偏偏要用古代美女的名字。\n");
	set("gender", "女性");
	set("age", 22);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 100);

	set("attitude", "peaceful");
	set("shen_type", -1);

	create_family("白驼山", 4 , "弟子");
	set("inquiry", ([
			"白驼山"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/xingxiu/obj/wcloth")->wear();

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
	{	command("seduce " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + "来我们白驼山庄吧，我们庄主就是天下闻名的欧\n"+
	     "阳锋。你有什麽问题问我就好啦。"+HBRED+HIW"(ask diaochan about 白驼山) (help baituo)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
