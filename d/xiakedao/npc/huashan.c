//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，华山弟子
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          华山派原为五岳剑派中势力最强的一派，但因华山两位前
    辈岳肃和蔡子峰对武学的见解不同，华山派至此竟分裂为剑、气
    二宗。二宗各持己见，终于水火不容，同门操戈！高手伤亡怠尽
    ，华山因此式微。华山派男玩家可拜岳不群为师，女玩家则可拜
    宁中则为师。到武功具有一定的水平后，则可拜华山高矮两长老
    为师，或尝试寻找风清扬学习「独孤九剑」。风清扬为当世唯一
    身具「独孤九剑」的人物。独孤九剑，有进无退，招招都是进攻
    ，攻敌之不得不守！威力可想而知。",
});
int ask_menpai(string* message);

void create()
{
	set_name("凌逍", ({ "huashan dizi", "dizi", "lingxiao" }));
	set("long", "一位十来岁的少年，双唇紧闭，一股坚毅之气。\n");
	set("gender", "男性");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 120);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("华山", 14 , "弟子");
	set("inquiry", ([
			"华山"   :  (: ask_menpai, menpai:),
		]));

	setup();
	carry_object("/d/city/obj/cloth")->wear();
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
	        command("poem " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + "看上去一身正气，还是来我们华山吧！\n"+
	     "你有什麽问题问我就好啦。"+HBRED+HIW"(ask lingxiao about 华山) (help huashan)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
