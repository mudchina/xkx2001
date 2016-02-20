//Cracked by Roath
// huanglong shi 黄龙使

inherit NPC;

#include <ansi.h>
#include <room.h>

int auto_perform();

void create()
{
	set_name("殷锦", ({ "yin jin", "huanglong shi", "shi", "yin" }));
	set("nickname", "黄龙使");
	set("long",
		"细眼尖脸，八成是个马屁精。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 26);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jingli", 1200);
	set("max_jingli", 1200);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 50000);
	set("shen", -20000);

	set_skill("force", 100);
	set_skill("dulong-dafa", 100);
	set_skill("dodge", 90);
	set_skill("lingshe-shenfa", 80);
	set_skill("strike", 70);
	set_skill("huagu-mianzhang", 90);
	set_skill("parry", 80);
//	set_skill("blade", 70);
	set_skill("digging", 90);
	set_skill("hook", 96);
	set_skill("ruyi-gou", 130);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("hook", "ruyi-gou");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("神龙教", 2, "使者");

        set("chat_msg_combat",({
                (:auto_perform:),
        }));

        set("chat_chance", 30);
        set("chat_msg",({
                (:random_move:)
        }));

	setup();

	carry_object("/clone/weapon/hook")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();

        if( interactive(this_player()) && !this_player()->query("sg/spy") )
                return kill_ob(this_player());
}




