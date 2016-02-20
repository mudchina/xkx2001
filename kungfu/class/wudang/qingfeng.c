//Cracked by Roath
// qingfeng.c 清风
// xQin 12/00

inherit NPC;

void create()
{
        set_name("清风", ({ "qingfeng", "daotong", "dao", "tong" }));
        set("long",
                "他是武当山的小道童，身穿道袍，头挽道髻，平时负责照顾俞岱岩的起居饮食。\n");
        set("gender", "男性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        
        set("max_qi", 250);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

        set("combat_exp", 5000);
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("cuff", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);

        create_family("武当派", 5, "弟子");
	set("inquiry", ([
		"清风" : "贫道便是清风，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"武当" : "贫道便是武当派弟子，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"武当派" : "贫道便是武当派弟子，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"张无忌" : "小师叔？唉，不知道他现在病好了没有，大家都好生挂念他。",
		"张三丰" : "祖师爷就在里面，不知这位"+ RANK_D->query_respect(this_player())
				+"是否有要事找我们祖师爷?",
	]));
	
        setup();
        
        carry_object("/d/wudang/obj/greyrobe")->wear();
}
