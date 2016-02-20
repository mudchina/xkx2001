//Cracked by Roath
// /d/hangzhou/npc/guo.c   郭啸天
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("郭啸天", ({ "guo xiaotian", "guo" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"他身材魁梧，浓眉大眼。\n"
"他是梁山泊好汉地佑星赛仁贵郭盛的后代。\n");
        set("combat_exp", 160000);
        set("shen_type",  1);
        set("attitude", "friendly");

        set("str", 28);
        set("con", 30);
        set("int", 20);
        set("dex", 27);

        set("max_qi", 800);
        set("max_jing", 300);
        set("max_neili", 1000);
        set("neili", 1000);
        set("jiali", 30);

        set_temp("apply/armor", 40);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("liuhe-qiang", 100);
        set_skill("pike", 100);
        set_skill("unarmed", 100);

        map_skill("pike", "liuhe-qiang");
        map_skill("parry", "liuhe-qiang");

        set("inquiry", ([
                "杨铁心" : "他是我义弟。",
                "李萍" : "她是我浑家。",
                "郭靖" : "这是一个道人给我未出世的儿女取的名字。",
                "杨康" : "这是我义弟杨铁心的骨肉。",
                "包惜弱" : "她是我弟媳。",
        ]));

        setup();

        carry_object("/clone/weapon/sangucha")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}
