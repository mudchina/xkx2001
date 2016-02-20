//Cracked by Roath
// kuli.c

inherit NPC;

void create()
{
	set_name("苦力", ({ "ku li", "worker" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long",
		"这是个老实巴交的苦力，长得膀阔腰圆，一身肌肉。\n");
//	set("shen_type", 1);
	set("combat_exp", 1200);
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
	set("attitude", "heroism");
        set_temp("apply/attack", 12);
        set_temp("apply/defense", 15);

	setup();
        carry_object("clone/misc/cloth")->wear();

}

