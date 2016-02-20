//Cracked by Roath
// xiaoxiang.c

#include <ansi.h>

inherit NPC;

void create()
{
	object bang;

        set_name("潇湘子", ({ "xiaoxiang zi", "xiaoxiang" }) );
        set("title", "");
        set("gender", "男性" );
        set("shen_type", -1);
        set("age", 30);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("long",
                "这便是湘西名宿潇湘子。他身材高瘦，脸无血色，形若僵尸。\n" );

        set("combat_exp", 800000);
        set("attitude", "heroism");

	set("max_qi", 2000);
	set("max_jing", 1500);
	set("max_jingli", 2500);
	set("max_neili", 3000);
	set("neili", 3000);
	set("shen", -800000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("stick", 180);
	set_skill("claw", 190);
	set_skill("huagong-dafa", 190);
	set_skill("zhaixinggong", 190);
	set_skill("dagou-bang", 190);
	set_skill("jiuyin-zhao", 190);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "wuchang-zhang");
	map_skill("stick", "dagou-bang");
	map_skill("claw", "jiuyin-zhao");
	prepare_skill("claw", "jiuyin-zhao");
        
        setup();
        
        if (clonep()) {
	    bang=carry_object("/clone/unique/kusang-bang");
	    if (objectp(bang)) bang->wield();
 	}
        carry_object("/clone/armor/cloth")->wear();
}
