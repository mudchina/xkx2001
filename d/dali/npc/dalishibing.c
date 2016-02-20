//Cracked by Roath
// dalishibing.c 士兵

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("士兵", ({ "shi bing", "shi", "bing" }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "　　这是一个大理国禁卫军士兵，身着锦衣，手执钢刀，双目精光炯炯，警惕地\n巡视着四周的情形。\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "heroism");
	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);
	set("max_qi", 600);
	set("eff_qi", 600);
	set("qi", 600);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 400);
	set("max_neili", 400);
	set("jingli", 300);
	set("max_jingli", 300);
	set("jiali", 20);
	set("shen_type", 0);
	set_temp("apply/attack",  30);
	set_temp("apply/defense", 30);
	set_skill("blade", 60);
	set_skill("unarmed", 80);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set("no_get", "你扛不动");
	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/dali/obj/ycloth")->wear();
}
#include "/kungfu/class/dali/condition.h"
