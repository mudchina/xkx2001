//Cracked by Roath
// tu.c 厚土旗教徒

#include <ansi.h>
inherit NPC;
string check();

void create()
{
	set_name("厚土旗教徒", ({"Houtu jiaotu", "jiaotu"}));
	set("long", 
		"\n"
		"\n");
	set("age",  );
	set("gender", "男性");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("shen_type", 0);

	set("max_qi", 0);
	set("max_jing", 0);
	set("neili", 0);
	set("max_neili", 0);
	set("jiali", 0);
	set("combat_exp", 0);
	set("score", 0);


	set_skill("unarmed", 0);
	set_skill("dodge", 0);
	set_skill("parry", 0);
	set_skill("blade", 0);
	set_skill("force", 0);

	set_skill("mofu-wuzong", 0);

	map_skill("dodge", "mofu-wuzong");

        set("inquiry", ([
        ]) );

        set("chat_chance_combat", 10);
	setup();
//	carry_object(__DIR__"obj/duanfu")->wield();
//	carry_object(__DIR__"obj/")->wear();
}
