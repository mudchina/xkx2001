//Cracked by Roath
// /d/forest/npc/cl_bangzhong.c  帮众
// by aln 2 / 98

inherit NPC;

void create()
{
	set_name("帮众", 
              ({ "changle bangzhong", "bangzhong" }));
        set("title", "长乐帮虎猛堂");
	set("long", 
		"这是一个惯于为非作歹的长乐帮众。\n"
		"他眼珠乱转，似乎正在想什么坏主意。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 300);
	set("max_jing", 200);
	set("max_neili", 100);
        set("neili", 100);
	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 50);
	set_skill("dodge", 40);
	set_skill("cuff", 50);
	set_skill("parry", 50);

        set("inquiry", ([
                "长乐帮" : "这里就是长乐帮总舵所在地。",
                "司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
                "虎猛堂" : "虎猛堂自从邱香主上任后，一日千里！",
                "邱香主" : "他在外面接待客人。",
                "邱山风" : "他在外面接待客人。",
                "香主" : "各位香主的任命由帮主老人家说了算。",
                "贝海石" : "贝大夫在弊帮劳苦功高，颇得帮主信任。",
                "帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
        ]));

	setup();

 	carry_object("/clone/weapon/changjian")->wield();
}
