//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，雪山弟子
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          雪山派是密宗的一支，雪山派有两个主要人物：鸠摩智和
    金轮法王。鸠摩智住持在大雪山大轮寺，为土蕃国国师；金轮法
    王则在蒙古做国师。雪山派的日月轮法威力奇大，另外降伏法是
    雪山派绝学，可以驱赶被降伏的人攻击他人，朝任何方向行走，
    甚至在钱庄取钱给你，好玩极啦！想来我们雪山吗？先去大轮寺
    当喇嘛吧。",
});
int ask_menpai(string* message);

void create()
{
	set_name("大人物", ({ "xueshan dizi", "dizi", "lama" }));
	set("long", "一个十来岁的小喇嘛，眉目间一股杀气。他从不告诉别人自己的真实姓名，总是自称大人物。\n");
	set("gender", "男性");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", -1);

	create_family("雪山", 13 , "弟子");
	set("inquiry", ([
			"雪山"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/xueshan/obj/lamajiasha")->wear();
	carry_object("/d/qilian/obj/faling")->wield();
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
	        command("flirt " + me->query("id"));
		command("lama");
		command("say 这位" + RANK_D->query_respect(me) + "想来我们雪山当喇嘛吗？我们这儿吃喝玩乐什么都有。\n"+
	     "你有什麽问题问我就好啦。"+HBRED+HIW"(ask lama about 雪山) (help mizong)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
