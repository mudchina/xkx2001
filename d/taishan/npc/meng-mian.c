//Cracked by Roath
// meng-mian.c 蒙面人

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("蒙面人", ({ "mengmian ren", "mengmian", "figure" }) );
	set("gender", "男性");
	set("age", 40);
	set("long",
		"一个黑布蒙面，神秘兮兮的家伙。\n");
	set("combat_exp", 200000 + random(100000));
        set("shen_type", -1);
	set("attitude", "heroism");

	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("str", 25);
	set("con", 25);
	set("int", 20);
	set("dex", 25);

	set("max_qi", 1000);
	set("eff_qi", 1000);
	set("qi", 1000);
	set("max_jing", 600);
	set("jing", 600);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 80);
	set("shen_type", 0);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("sword",   120);
	set_skill("blade",   120);
	set_skill("staff",   120);
	set_skill("club",    120);
	set_skill("whip",    120);
	set_skill("unarmed", 120);
	set_skill("parry",   120);
	set_skill("dodge",   120);

	setup();

	switch( random(5) ) 
	{
		case 0:
		       carry_object("/d/city/obj/gangjian")->wield();
		       break;
		case 1:
		       carry_object("/d/city/obj/gangdao")->wield();
		       break;
		case 2:
		       carry_object("/d/xingxiu/obj/gangzhang")->wield();
		       break;
		case 3:
		       carry_object("/d/shaolin/obj/qimeigun")->wield();
		       break;
		case 4:
		       carry_object("/d/shaolin/obj/changbian")->wield();
		       break;
	}
        carry_object("/d/taishan/obj/yexing")->wear();
        carry_object("/d/taishan/obj/mianzhao");
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

        if( this_object()->is_killing(this_player()) ) return;

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIR "蒙面人恶狠狠地说道：老子苦练几十年，凭你也当了武林盟主去！ 我宰了你！\n" NOR, 
		this_player());
		this_object()->kill_ob(this_player());
	}	
	else if( this_player()->query("id") == shangshan ) {
		message_vision(HIR "蒙面人冷笑几声，说道：你是赏善使者，怎么从不给老子上供！ 分明是个势力眼！ 看招！\n" NOR, 
		this_player());
		this_object()->kill_ob(this_player());
	}	
	else if( this_player()->query("id") == fae ) {
		message_vision(HIY "蒙面人死死瞪着$N瞧了会，奸笑道：老子是天下第一大恶人，你罚恶使者敢对付我吗？！\n" NOR, 
		this_player());
		this_object()->kill_ob(this_player());
	}
	else if( this_player()->query("combat_exp") < 100000 && random(10) == 0 ) {
		this_player()->tell_object("蒙面人正盯著你看，不知道打什么主意。\n");
		say("象你这麽三脚猫的功夫，也敢在老子面前招摇，还不给我滚一边去！\n");	
	}

}
