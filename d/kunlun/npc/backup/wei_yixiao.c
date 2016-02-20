//Cracked by Roath
// wei_yixiao.c 韦一笑

#include <ansi.h>
inherit NPC;
string check();

void create()
{
	set_name("韦一笑", ({"wei yixiao", "wei"}));
	set("nickname", "青翼蝠王");
	set("long", 
		"他身披青条子白色长袍。他削腮尖嘴，脸上灰扑扑地无半分血色。\n"
		"他发现你正在看他，裂嘴冲你一笑，露出一嘴雪白的牙齿，阴森森的吓了你一跳。\n");
	set("age",  45);
	set("gender", "男性");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("shen_type", 0);

	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 300);
	set("combat_exp", 1100000);
	set("score", 400000);


	set_skill("unarmed", 170);
	set_skill("dodge", 220);
	set_skill("parry", 170);
	set_skill("blade", 170);
	set_skill("force", 170);
	set_skill("mofu-wuzong", 220);

	map_skill("dodge", "mofu-wuzong");

        set("inquiry", ([
        ]) );

        set("chat_chance_combat", 10);
	setup();
//	carry_object(__DIR__"obj/duanfu")->wield();
//	carry_object(__DIR__"obj/")->wear();
}
