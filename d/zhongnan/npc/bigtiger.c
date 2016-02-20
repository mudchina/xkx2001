//Cracked by Roath
// /clone/beast/bigtiger.c
// 山老虎
// sdong 08/98

#include <ansi.h>
inherit NPC;


void create()
{
		  set_name("山老虎", ({ "shan laohu", "laohu" ,"tiger"}) );
		  set("race", "野兽");
		  set("age", 1);
		  set("long", "一只又高又大的山老虎，它正气势汹汹地瞪着眼睛看着你。\n");
		  set("attitude", "peaceful");
		  set_weight(200000);
		  set("max_qi", 100);
		  set("max_jing", 100);
		  set("max_jingli", 100);


		  set("str", 30);
		  set("con", 80);
		  set("dex", 30);
		  set("int", 10);

		  set("combat_exp", 20000);

		  set_temp("apply/attack", 10);
		  set_temp("apply/damage", 10);
		  set_temp("apply/armor", 10);

		  setup();
}


void die()
{
		  object ob,ob2=this_object();

		  ob = new(DRUG_D("hugu"));
		  ob->move(environment(this_object()));
		  message_vision("$N惨嚎一声，死了！\n", this_object());
		  destruct(ob2);
}

