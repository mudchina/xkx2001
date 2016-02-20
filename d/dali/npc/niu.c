//Cracked by Roath
// niu.c 水牛

inherit NPC;

void create()
{
	set_name("水牛", ({ "shui niu", "niu", "cow" }) );
	set("race", "家畜");
	set("age", 10);
	set("long", "一头南方山区常见的水牛，是耕作的主力，也用来拉车载物。由于水草茂盛，长得十分肥壮。\n");
	set("str", 25);
	set("cor", 25);
	set("dalivictim",1);
    set("combat_exp", 1000);
	set("max_qi", 200);
	set("qi", 200);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	setup();
}
