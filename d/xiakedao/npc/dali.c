//Cracked by Roath
#include <ansi.h>

inherit NPC;
string* menpai = ({
	"say 
          大理国位处中原西南方的云南。于五代后晋天福二年建国
。段氏一派是大理皇室。段氏原本出身中原武林世家，虽贵为皇族，
家传武功却从来不曾荒废，反而愈加勤奋。段氏的一阳指六脉神剑，
皆是江湖上赫赫有名的武功。",
});
int ask_menpai(string* message);

void create()
{
        set_name("流云", ({ "dali dizi", "dizi", "liuyun" }) );
        set("gender", "男性");
        set("age", 30);
        set("long",
"这是位大理人，身着锦衣，手执钢刀，双目精光炯炯，警惕地巡视着四周的情形。\n");
        set("combat_exp", 200);
        set("shen_type", 1);
        set("attitude", "heroism");

        set("str", 28);
        set("con", 23);
        set("int", 20);
        set("dex", 26);

        set("shen_type", 0);

	set("inquiry", ([
			"大理"   :  (: ask_menpai, menpai:),
			
		]));

        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/dali/obj/ycloth")->wear();
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
	{	command("hi " + me->query("id"));
		command("say " + RANK_D->query_respect(me) + "来我们大理来看看吧，我们那儿山清水秀。你有什麽\n" +
"问题问我就好啦。"+HBRED+HIW"(ask liuyun about 大理)"NOR+ "或"+HBRED+HIW"(help dali)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
		
 }

#include "/d/xiakedao/npc/xkdnpc.h"


