//Cracked by Roath
// yang_xiao.c 杨逍

#include <ansi.h>
inherit NPC;
string check();

void create()
{
	set_name("范遥", ({"yang xiao", "yang"}));
	set("nickname", "光明右使");
	set("long", 
		"他是一个长发披肩的头陀，身材魁伟，满面横七竖八的都是刀疤，\n"
		"丑陋可怖。他头发作红棕之色，自非中土人氏。);\n"
	set("age",  45);
	set("gender", "男性");
	set("long", "\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("shen_type", 0);

	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 300);
	set("combat_exp", 1200000);
	set("score", 400000);


	set_skill("unarmed", 190);
	set_skill("dodge", 190);
	set_skill("parry", 190);
	set_skill("blade", 190);
	set_skill("force", 190);
	set_skill("xiaoyaoyou", 190);
	
	map_skill("dodge", "xiaoyaoyou");

    set("inquiry", ([
        ]) );

	setup();

//	carry_object(__DIR__"obj/")->wear();
}
