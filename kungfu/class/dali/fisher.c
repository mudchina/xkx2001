//Cracked by Roath
inherit NPC;

void create()
{
	set_name("点苍渔隐", ({ "diancang yuyin", "yuyin", "fisher"}));
	set("long", 
		"他四十来岁年纪，一张黑漆漆的锅底脸，虬髯满腮，根根如铁。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
//	set("combat_exp", 700000);

	set_temp("apply/armor", 50);
	set_skill("force", 140);
	set_skill("dodge", 180);
	set_skill("ding-dodge", 180);
	set_skill("ding-force", 140);
	set_skill("ding-unarmed", 140);
	set_skill("parry", 140);
	set_skill("unarmed", 140);
	set_skill("staff", 140);
	set_skill("duanjia-jian", 100);
	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");
	map_skill("staff", "duanjia-jian");

	setup();
	carry_object("/clone/weapon/tiejiang")->wield();
    carry_object("/d/city/obj/cloth")->wear(); 
}

int accept_object(object who, object ob)
{
	object thisroom;
	thisroom=find_object("/d/dali/yideng1.c");

	if((string)ob->query("name")=="金娃娃" && ob->query("race") == "野兽") {
		remove_call_out("destroying");
		call_out("destroying", 1, ob);

	write("点苍渔隐接过金娃娃，上上下下打量了你几眼，忽的将金娃娃抛\n");
	write("回水中，冷冷的说道：休想以此上去害我师父，拼着给师叔一顿\n");
	write("责骂。 \n");
	write("他转身抛金娃娃，加上说得口沫横飞，不小心把小船的入口让了出来。\n");
	thisroom->set("exits/enter", "/d/dali/smallboat.c");
	remove_call_out("closing");
	call_out("closing", 5, thisroom);
    return 1;
	}
}

void closing(object thisroom)
{
	say("点苍渔隐骂了几句，回到了他原来坐的地方。\n");
	thisroom->delete("exits/enter");
}

void destroying(object ob)
{
	destruct(ob);
	return;
}
