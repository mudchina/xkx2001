//Cracked by Roath
// /d/emei/npc/puren.c 仆人 
// Shan: 96/07/09

inherit NPC;

void create()
{
	int value;

	value = random(5);

	set_name("仆人", ({ "pu ren", "servant"}));
        set("long", 
"一个男仆，个子高高的，背着一个大包，忠心耿耿地跟在少奶奶后面。\n");
	set("gender", "男性");
	set("age", 14 + value * 2 );

        set("str", 20);
        set("dex", 18);
        set("con", 20);
        set("int", 18);
        set("attitude", "friendly");

	set("combat_exp", 800 + 20 * value);
	set("shen_type", 0);
	setup();
	add_money("silver", 1 + value);
}
