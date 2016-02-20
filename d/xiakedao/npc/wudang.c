//Cracked by Roath
// wudang.c 道童
#include <ansi.h>
inherit NPC;
string* menpai = ({
	"say 
          武当和少林乃武林的泰山北斗。武当张真人自创的“太极”
    是以柔克刚的武林绝学。武当功夫精简。只有一套剑法，一套拳法，
    和一套轻功身法。武当弟子都是道家中人故需精修道德经，以此长
    气。武当弟子在太极神功和道家心法有很高境界之时可与人还魂或
    自救。",
});
int ask_menpai(string* message);

void create()
{
	set_name("中伯", ({ "wudang dizi", "dizi", "zhongbo" }));
	set("long", 
		"他是武当山的小辈弟子。\n");
	set("gender", "男性");
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

	set("combat_exp", 200);
	set("score", 1000);


	create_family("武当派", 4, "弟子");
	set("inquiry", ([
			"武当"   :  (: ask_menpai, menpai:),
		]));

	setup();
	
	carry_object("/d/wudang/obj/greyrobe")->wear();
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
	{	command("hi " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + 
			"你有什麽问题问我就好啦。\n" +
		         HBRED+HIW"(ask dizi about 武当)"NOR +" 或试试 "+HBRED+HIW"help wudang"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
}

#include "/d/xiakedao/npc/xkdnpc.h"
