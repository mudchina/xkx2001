//Cracked by Roath
//yapu.c

#include <ansi.h>

inherit NPC;

void create()
{
	int skill;
	skill = random(30);
	set_name("哑仆", ({ "ya pu","pu", "servant"}) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"这是个桃花岛上的佣仆，耳朵已被刺聋，舌头也被割去，神情木然。\n");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "peaceful");
	set("max_qi", 500);
	set("max_jing", 500);
	set("max_neili", 500);
	set("neili", 500);
	set_temp("apply/armor", 50);	

	set("str", 20);
	set("con", 20);
	set("dex", 20);

	set_skill("cuff", 30+skill);
	set_skill("parry", 30+skill);
	set_skill("force", 30+skill);
	set_skill("dodge", 30+skill);

	setup();

        carry_object("/clone/misc/cloth")->wear();

}

void init()
{
	::init();
	add_action("do_ask", "ask");
}

int do_ask(string arg)
{
	string arg1, arg2;

	if( !arg || sscanf(arg, "%s about %s", arg1, arg2) != 2 )
                return notify_fail("什么？\n");

	if( arg1 == "ya pu" || arg1 == "pu" || arg == "servant") {
		write(CYN"哑仆痛苦地摇了摇头，指了指自己的嘴巴，喉间发出几声嘶哑的呀呀声。\n"NOR);
		return 1;
	}
	return 0;
}
