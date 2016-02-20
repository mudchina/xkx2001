//Cracked by Roath
// jjhuoji. 聚金阁伙计

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("聚金阁伙计", ({ "huoji", "keeper" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 25);
	set("long", "他长得尖咀长脸，一副势利的样子。\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");

	setup();
}
