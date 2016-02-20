//Cracked by Roath
// weishi2.c 黄衣卫士

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("黄衣卫士", ({ "wei shi", "shi", "guard" }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "　　这是位黄衣卫士，身着锦衣，手执钢刀，双目精光炯炯，警惕地巡视着四周\n的情形。\n");
	set("combat_exp", 80000);
	set("shen_type", 1);
	set("attitude", "heroism");
	set("str", 28);
	set("con", 23);
	set("int", 20);
	set("dex", 26);
	set("max_qi", 700);
	set("eff_qi", 700);
	set("qi", 700);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 25);
	set("shen_type", 0);
	set_temp("apply/attack",  40);
	set_temp("apply/defense", 40);
	set_skill("blade", 80);
	set_skill("unarmed", 60);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set("no_get", "你扛不动");
	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/dali/obj/ycloth")->wear();
}
#include "/kungfu/class/dali/condition.h"
