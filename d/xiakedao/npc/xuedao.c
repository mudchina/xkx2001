//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，血刀门弟子
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          血刀门同雪山派都属于密宗。血刀门是一个小门派，掌门
    人是血刀老祖。血刀的绝招“祭血神刀”威力巨大，先砍自己一
    刀，刀上涂血，可一招毙敌，且负神越高，威力越大。雪山派和
    血刀门的武功有很多共同之处，身为喇嘛，在这两个门派同时学
    习武功也是允许的。",
});
int ask_menpai(string* message);

void create()
{
	set_name("蓝布衣", ({ "xuedao dizi", "dizi", "blue" }));
	set("long", "一个二十来岁的汉子，身着粗布蓝衣，像貌威武，但透着一股杀气。\n");
	set("gender", "男性");
	set("age", 28);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 125);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("血刀门", 4 , "弟子");
	set("inquiry", ([
			"血刀门"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/qilian/obj/lamajiasha")->wear();
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
        if (me->query_temp(this_object()->query("id")) == 0 )
	{	
	        command("rob");
		command("say 这位" + RANK_D->query_respect(me) + "缺钱花吗？看你身上也没甚么油水，干脆咱俩一起去抢钱吧，来俺们血刀门最好啦！"+
	     "你有什麽问题问我就好啦。"+HBRED+HIW"(ask blue about 血刀门) (help mizong)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
