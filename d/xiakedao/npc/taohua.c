//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，桃花弟子
// Ssy

inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          桃花岛一派乃“东邪”黄药师所创。黄药师素来厌憎世俗
    之见，行事但求心之所适，因此上得了“东邪”雅号。但东邪之
    “邪”并非西毒之“毒”，这一点请桃花岛弟子牢记在心。桃花
    武功中对指法尤有独到造诣，桃花岛的弹指神通与大理一阳指各
    擅胜场。但是桃花岛最为精深的却是奇门遁甲、阴阳五行之术。
    新手可先拜于太湖归云庄陆乘风门下，学些桃花岛基本功夫，再
    图上岛拜黄药师为师。",
});
int ask_menpai(string* message);

void create()
{
	set_name("清云风", ({ "taohua dizi", "dizi", "qingyun" }));
	set("long", "一位二十来岁的青年人，眉目英俊，但似乎有点邪气。\n");
	set("gender", "男性");
	set("age", 28);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 200);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("桃花岛", 2 , "弟子");
	set("inquiry", ([
			"桃花岛"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/xixia/obj/robe")->wear();
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
	        command(" " + me->query("id"));
		command("say 桃花岛弟子个个博学多才，非其它门派所及。这位" + RANK_D->query_respect(me) + "\n来我们桃花岛一定不后悔！\n"+
	     "你有什麽问题问我就好啦。"+HBRED+HIW"(ask qingyun about 桃花岛) (help taohua)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
