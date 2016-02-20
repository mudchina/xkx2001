//Cracked by Roath
// /d/hangzhou/npc/yang.c   杨铁心
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("杨铁心", ({ "yang tiexin", "yang" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"一个白净面皮的汉子。\n"
"他是岳飞麾下名将杨再兴的后代。\n");
        set("combat_exp", 180000);
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
        set_skill("liuhe-qiang", 120);
        set_skill("pike", 120);
        set_skill("unarmed", 100);

        map_skill("pike", "liuhe-qiang");
        map_skill("parry", "liuhe-qiang");

        set("inquiry", ([
                "郭啸天" : "他是我义兄。",
                "包惜弱" : "她是我浑家。",
                "杨康" : "这是一个道人给我未出世的儿女取的名字。",
                "郭靖" : "这是我义兄郭啸天的骨肉。",
                "李萍" : "她是我嫂子",
        ]));

        setup();

        carry_object("/clone/weapon/qiang")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}
