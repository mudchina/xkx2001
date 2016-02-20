//Cracked by Roath
// bossxue.c 薛老板

#include <ansi.h>
#include <dbase.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("薛老板", ({ "xue laoban", "xue" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "　　这是一个经验老到的生意人，一双精明的眼睛不停的打量着你。\n");
	set("attitude", "heroism");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 0);
	set_skill("unarmed", 35 + random(10));
	set_skill("dodge", 35 + random(10));
	set_skill("parry", 35 + random(10));
	set_skill("blade", 35 + random(10));
	set_skill("force", 35 + random(10));
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	set("vendor_goods", ({
		"d/city/obj/flower_shoe",
		"d/city/obj/doupeng",
		"d/city/obj/guazi",
		"d/city/obj/jin_ao",
		"d/city/obj/qun",
		}));
	setup();
	carry_object("d/city/obj/cloth")->wear();
}
void init()
{
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
