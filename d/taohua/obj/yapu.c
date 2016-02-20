//Cracked by Roath
//yapu.c

#include <ansi.h>

inherit NPC;

void create()
{
	int skill;
	skill = random(60);
	set_name("哑仆", ({ "ya pu","pu", "servant"}) );
	set("gender", "男性");
	set("age", 30);
	set("long",
"这是个桃花岛上的佣仆，是个忘恩负义，大奸大恶之徒，
被黄药师擒住后，割去舌头，刺聋耳朵，充当厮养.
他又聋又哑，神情木然。\n");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "peaceful");
	set("max_qi", 500);
	set("max_jing", 500);
	set("max_neili", 500);
	set("neili", 500);
	set_temp("apply/armor", 50);	

	set("str", 28);
	set("con", 28);
	set("dex", 28);

	set_skill("cuff", 30+skill);
	set_skill("parry", 30+skill);
	set_skill("force", 30+skill);
	set_skill("dodge", 30+skill);

	setup();

        carry_object("/clone/misc/cloth")->wear();

}

