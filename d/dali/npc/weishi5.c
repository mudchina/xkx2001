//Cracked by Roath
// weishi5.c 副将

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("副将", ({ "fu jiang", "jiang", "general" }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "　　这是位大理国御林军的将领，位居副将之职，平时负责皇城的治安。他看起\n来身怀绝技。\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "heroism");
	set("str", 30);
	set("con", 30);
	set("int", 20);
	set("dex", 30);
	set("max_qi", 1500);
	set("qi", 1500);
	set("max_jing", 1000);
	set("jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 75);
	set("shen_type", 0);
	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_skill("sword", 120);
	set_skill("duanjia-jian", 130);
	set_skill("parry", 120);
	set_skill("cuff", 120);
	set_skill("jinyu-quan", 130);
	set_skill("dodge", 120);
	set_skill("duanshi-shenfa", 120);
	set_skill("force", 120);
	set_skill("kurong-changong", 120);
	map_skill("sword","duanjia-jian");
	map_skill("parry","duanjia-jian");
	map_skill("cuff","jinyu-quan");
    map_skill("dodge","duanshi-shenfa");
    map_skill("force","kurong-changong");
    prepare_skill("cuff","jinyu-quan");
	set("no_get", "你扛不动");
	setup();
	carry_object("/d/city/obj/gangjian")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}
#include "/kungfu/class/dali/condition.h"
