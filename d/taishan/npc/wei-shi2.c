//Cracked by Roath
// wu-shi2.c 盟主卫士

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("红衣武士", ({ "wei shi", "shi", "guard" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是位红衣武士，身披钢甲，手执长剑，双目精光炯炯，警惕地巡视着四周的情形。\n");
	set("combat_exp", 80000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("str", 28);
	set("con", 23);
	set("int", 20);
	set("dex", 26);

	set("max_qi", 700);
	set("eff_qi", 700);
	set("qi", 700);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 25);
	set("shen_type", 0);

	set_temp("apply/attack",  40);
	set_temp("apply/defense", 40);

	set_skill("sword", 80);
	set_skill("unarmed", 60);
	set_skill("parry", 80);
	set_skill("dodge", 80);

	set("no_get", "你扛不动红衣武士");

	setup();

        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}

void init()
{
	object ob1, ob2, ob3;
	string mengzhu, shangshan, fae;
	
	::init();
	if(!( ob1 = find_living("mengzhu")) )
	ob1 = load_object("/clone/npc/meng-zhu");
	mengzhu = ob1->query("winner");

	if(!( ob2 = find_living("shangshan")) )
	ob2 = load_object("/clone/npc/shang-shan");
	shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
	ob3 = load_object("/clone/npc/fa-e");
	fae = ob3->query("winner");

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIY "红衣武士举起长剑，向$N齐声大喊：盟主万岁，万岁，万万岁！\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == shangshan ) {
		message_vision(HIY "红衣武士举起长剑，向$N齐声大喊：赏善使者好！\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == fae ) {
		message_vision(HIY "红衣武士举起长剑，向$N齐声大喊：罚恶使者好！\n" NOR, 
		this_player());
	}	
}
