//Cracked by Roath
// bywoman.c 摆夷商贩

inherit NPC;

void create()
{
	set_name("摆夷商贩", ({ "shang fan", "fan", "shang" }) );
	set("long", "一个摆夷妇女，背着个竹篓贩买些丝织物品和手工艺品。\n");

	set("age", 30);
	set("gender", "女性");
	set("dalivictim",1);

	set("str", 15);
	set("cor", 15);

    set("combat_exp", 2000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 3);
	set_temp("apply/armor", 3);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/byskirt.c")->wear();
}
