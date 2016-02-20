//Cracked by Roath
// puren.c 侠客岛厮仆
// Long, 6/13/97
// Update Ssy 5/3/98

#include <ansi.h>

inherit NPC;

int ask_leave();
int ask_food();
int ask_daozhu();
void greeting(object);

void create()
{
	set_name("厮仆", ({ "si pu", "pu"}));
	set("long", "他是岛上的一个仆人，手底下似乎很有两下子。\n");
	set("gender", "男性");
	set("age", 24);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 10000);
	set("score", 1000);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("cuff", 70);
	set_skill("sword", 70);
	
	set("inquiry", ([
			"腊八粥"   :  (: ask_food :),
			"中原"   : 	(: ask_leave :),
			"岛主"   : 	(: ask_daozhu :), 
		]));
	set("food_count", 3);
	setup();
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
		command("bow " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + 
			"你来迟一步，早些你就可赶上十年一次的腊八\n" +
			"粥大会。");
		me->set_temp(this_object()->query("id"), 1);
	}
}
int ask_leave()
{	command("shake ");
	command("say 没有岛主同意，你可不能私自离岛。");
	return 1;
}
int ask_food()
{	int i;
	object you = this_player();
	object food;
	object here = environment(this_object());
	if (here->query("food_count") < 1)
	{	say("厮仆转身走到几张桌子前找了找，回头报歉地笑了笑说道：对不起，\n" +
			"都被人喝光了。\n");
		return 1;
	}
	
	if (  present("laba zhou", you) )
	{	say("厮仆皱了皱眉头说道：有了还要，你太贪心了吧。\n");
		return 1;
	}
	else if (present("laba zhou", environment(you)))
	{	say("厮仆往地上一指：地上不是有一碗吗，你要喝的话就捡起来吧。\n");
		return 1;
	}
	food = new("/d/xiakedao/obj/zhou");
	food->move(this_object());

//	say("厮仆转身从旁边的桌上端起一" + food->query("unit") + food->query("name") + "，递了给你。\n");
	say("厮仆转身从旁边的桌上端起一" + food->query("unit") + food->query("name") + "。\n");
	command("give " + food->query("id") + " to " + you->query("id"));
	//food->move(you);
	here->add("food_count", -1);
	return 1;
}
int ask_daozhu()
{	object me = this_player(), here;
	string desc;
	here = environment(me);
	desc = here->query("long");
	if ( (int)here->query_temp("opened") == 0)
	{	say("厮仆微一躬身说道：两位岛主正在石室中苦思。\n");
		say("厮仆招了招手，其他几位厮仆走了过来，四人抓住两块大屏风的边缘\n");
		say("向旁缓缓拉开，露出一条长长的甬道。\n");
		here->set("exits/enter", "/d/xiakedao/yongdao10");
		here->set_temp("opened", 1);
		desc = sprintf(desc + "    屏风已被拉开，露出一条长长的甬道。\n");
		here->set("long", desc);
	}
	else
	{	say("厮仆微一躬身说道：两位岛主正在石室中苦思，你进去找他们吧。\n");
	}
	return 1;
}
