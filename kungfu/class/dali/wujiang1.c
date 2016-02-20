//Cracked by Roath
// wujiang1.c 总管

inherit NPC;

void create()
{
	set_name("总管", ({ "zong guan", "zong", "guan"}));
    set("long","　　他是定安府的武官总管，负责管理官员升级和分派工作等事务。\n");
	set("title","大理国武将");
    set("gender", "男性");
    set("age", 35);
	set_skill("cuff", 65);
    set_skill("jinyu-quan", 65);
    set_skill("dodge", 65);
    set_skill("duanshi-shenfa", 65);
    set_skill("parry", 60);
    set_skill("force", 60);
    set_skill("staff", 65);
	set_skill("buddhism",70);
    set_skill("kurong-changong",60);
	set_skill("duanjia-jian",70);
    map_skill("cuff","jinyu-quan");
    map_skill("dodge","duanshi-shenfa");
    map_skill("force","kurong-changong");
	map_skill("staff","duanjia-jian");
	map_skill("parry","duanjia-jian");
	prepare_skill("cuff","jinyu-quan");
    set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);
    set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
    set("max_neili", 500);
    set("jiali", 30);
    set("combat_exp", 120000);
    set("attitude", "peaceful");
    set("shen_type", 1);
    setup();
	carry_object("/d/city/obj/tiejia")->wear();	
	carry_object("/d/city/obj/gangjian")->wield();
}
#include "/kungfu/class/dali/promote2.h"
