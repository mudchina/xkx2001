//Cracked by Roath
// yang_xiao.c 杨逍

#include <ansi.h>
inherit NPC;
string check();

void create()
{
	set_name("杨逍", ({"yang xiao", "yang"}));
	set("nickname", "光明左使");
	set("long", 
		"他是个中年书生，相貌俊雅，只是双眉略向下垂，嘴边露出几条深深\n"
		"皱纹，不免略带哀老凄苦之相。他站在那里，不言不动，神色漠然，\n"
		"似乎心驰远处，正在想甚麽事情。\n");
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
