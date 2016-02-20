//Cracked by Kafei
// NPC gan.c
// AceP

#include <ansi.h>

inherit NPC;

int do_say(string arg);

void create()
{
	set_name("干光豪", ({ "Gan guanghao","gan" }) );
	set("gender", "男性");
	set("age", 30);
	set("long", "这位是无量剑东宗掌门左子穆的弟子，名叫干光豪。\n");
	set("combat_exp", 35000);
	set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  60);
	set("apply/defense", 60);

	set_skill("sword", 75);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
	::init();
	add_action("do_say","say");
}

int do_say(string arg)
{
	object me;
	me = this_player();

	if( arg=="恭喜" && present("Ge guangpei", environment(me))) {
		message_vision("$N一拱手，小声道：“恭喜二位。祝两位白头偕老。呵呵。”\n"
			"葛光佩的脸唰的一下红了。干光豪“嘻嘻嘻”地傻笑了几声。\n", me);
		"/d/dali/yubi"->set("exits/west", "/d/dali/xuanya");
		return 1; }
	return 0;
}
