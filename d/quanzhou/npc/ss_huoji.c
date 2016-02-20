//Cracked by Roath
// ss_huoji. 鸿翔绸缎庄伙计

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("鸿翔绸缎庄伙计", ({ "huoji", "keeper" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 25);
	set("long", "他是个勤劳的伙计，正愉快地向店里的顾客介绍各式花色和质地的绸缎。\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");

	setup();
}
