//Cracked by Roath
// goat.c 山羊

inherit NPC;

void create()
{
	set_name("山羊", ({ "shan yang", "yang", "goat" }) );
	set("race", "家畜");
	set("age", 10);
	set("long", "一头短角山羊，大理地区常见的家畜。\n");
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
