//Cracked by Roath
// ling-zhi.c 灵智上人

inherit NPC;

void create()
{
	set_name("灵智上人", ({ "lingzhi shangren", "lingzhi", "shangren" }));
//	set("nickname", "");
	set("long", 
"灵智上人身披大红袈纱，头戴一顶金光灿然的僧帽，是个藏僧。\n"
"他身材魁武之极，站着比四周众人高出了一个半头。\n");
	set("title", "吐蕃密宗僧人");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 23);
	
	set("max_qi", 900);
	set("max_jing", 500);
	set("neili", 850);
	set("max_neili", 850);
	set("jiali", 40);
	set("combat_exp", 330000);

        set_temp("apply/attack",  65);
        set_temp("apply/defense", 65);

	set_skill("force", 95);
	set_skill("dodge", 85);
	set_skill("parry", 95);
	set_skill("hand", 100);
	set_skill("blade", 100);
        set_skill("buddhism", 80);
        set_skill("literate", 30);
	set_skill("dashou-yin", 100);
	set_skill("xueshitiao", 100);

	map_skill("parry", "dashou-yin");
	map_skill("hand", "dashou-yin");
	map_skill("dodge", "xueshitiao");

	prepare_skill("hand", "dashou-yin");

        set("inquiry", ([
            "name" : "我的法名是灵智。",
            "here" : "我也不是中原人氏，不谙本地民情，抱歉。",
	    "密宗" : "密宗是佛法的一个宗派，又称金刚密宗。佛教的其他宗派还有"
		     "华严宗、律宗、禅宗、莲花宗、净土宗等。你们中原的少林寺"
		     "属禅宗。密宗与其他宗派的一个区别是密宗在修行中讲究密法"
                     "兼修。法是指佛法，密是指密咒。",
	    "吐蕃" : "吐蕃在西川以西，天竺以北，西域以南。",
	    "密咒" : "阁下非为密宗弟子，恕不传授。",
	    "佛法" : "你可以去少林寺学习。虽然他们的不及密宗的博大精深，入门"
		     "是够的。",
	    "少林寺" : "少林寺是中原的禅宗丛林。",
	    "丛林" : "佛教中丛林指寺院。",
       ]) );

	setup();
	carry_object("/clone/weapon/tongbo")->wield();
	carry_object(__DIR__"obj/dahong-jiasha")->wear();
}
