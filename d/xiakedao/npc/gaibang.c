//Cracked by Roath
// gaibang.c 乞丐
#include <ansi.h>
inherit NPC;
string* menpai = ({
	"say 
          丐帮是武林第一大帮，洪帮主的降龙十八掌以刚猛为主，
    故如果你想学降龙十八掌需有较高的臂力。丐帮的打狗棍更是武
    林一绝，要想学打狗棍只有拜洪帮主。只有丐帮六袋弟子才能拜
    洪帮主，或者是。。。丐帮弟子不能在钱庄里存钱，但可以向别 
    人乞讨(beg)，丐帮弟子可以随地睡觉，还可以查(check)别人功
    夫的深浅。丐帮的密道四通八达，让丐帮弟子行动方便。
    (help beg, help check)", 
});
int ask_menpai(string* message);

void create()
{
	set_name("小泰", ({ "begger", "qigai", "tai"}));
	set("long", 
		"他是丐帮的小乞丐。\n");
	set("gender", "男性");
	set("title", "丐帮一袋弟子");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 100);
	set("score", 1000);

	create_family("丐帮", 20, "一袋弟子");
	set("inquiry", ([
			"丐帮"   :  (: ask_menpai, menpai:),
		]));

	setup();
	
        carry_object("/d/gaibang/obj/budai")->wear();
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
	{	command("say 这位" + RANK_D->query_respect(me) + 
			"，做乞丐最逍遥啦。你有什麽问题问我就好啦\n" +
			"。"+HBRED+HIW"(ask begger about 丐帮)"NOR+" 或" +HBRED+HIW"(help gaibang)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}

 }

#include "/d/xiakedao/npc/xkdnpc.h"

