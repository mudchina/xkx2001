//Cracked by Roath
inherit NPC;

void create()
{
        set_name("狱卒", ({ "yu zu", "zu", "guard" }));
        set("long", 
"这个狱卒看起来颇为散漫，手里握着一把匕首正在修指甲，时不时的发出一阵阴笑。\n");
        set("gender", "男性");
        set("age", 48+random(30));
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 400);
        set("max_jing", 300);
        set("jiali", 10);
        set("combat_exp", 5000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 28);
        set_skill("sword", 32);
	setup();


         carry_object("/clone/armor/cloth")->wear();
        carry_object("/d/dali/npc/obj/dagger")->wield();

}


