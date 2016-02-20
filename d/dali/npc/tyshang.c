//Cracked by Roath
// tyshang.c 台夷商贩

inherit NPC;

void create()
{
	set_name("台夷商贩", ({ "shang fan", "fan", "shang" }) );
	set("long", "一位台夷族的商贩，正在贩卖一竹篓刚打上来的活蹦乱跳的鲜鱼。\n");

	set("age", 25);
	set("gender", "男性");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 1000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/tyduanqun.c")->wear();
	carry_object("/d/dali/npc/obj/tytoujin.c")->wear();
}
