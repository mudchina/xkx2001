//Cracked by Roath
// jing.c 锐金旗教徒

#include <ansi.h>
inherit NPC;
string check();

void create()
{
	set_name("锐金旗教徒", ({"jing jiaotu","jiaotu"}));
	set("long", 
		"\n"
		"\n");
	set("age",  random(20)+25);
	set("gender", "男性");
	set("long", "\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 0);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
        set("inquiry", ([
                "摆阵" : (: check :),
                "飞斧阵" : (: check :),
        ]) );

        set("chat_chance_combat", 10);
	setup();
	carry_object(__DIR__"obj/duanfu")->wield();
//	carry_object(__DIR__"obj/")->wear();
}

string check()
{
	object ob = this_player();
	object me = this_object();
        mapping fam;
        if (mapp(fam = ob->query("family")) 
		&& fam["family_name"] != "明教" )
        {
		return RANK_D->query_respect(ob) + "并非我教中人，怎可以学我等摆阵。";
        }
	if (ob->query_skill("feifu-zhen") < 50)
	{	
		return RANK_D->query_respect(ob) + "的飞斧阵还学的不精，还没法布阵呢，快回去多学学吧！\n";
	}
	if (!(present("bai qi", ob)))
	{	
		return RANK_D->query_respect(ob) + "没有令旗怎能摆阵杀敌呢，快去拿吧！\n";
	}
	//ob->command("team invite jing");
        ob->add_team_member(me);
     	command("follow " + ob->query("id"));
        return "我们走罢！\n";
}
void destroy_it(object obj)
{
        destruct(obj);
}
