//Cracked by Roath
// gushou.c 鼓手

inherit NPC;

void create()
{
        set_name("星宿派鼓手", ({ "gushou" }));
        set("long", 
                "他是星宿派的吹鼓手。\n"
                "他面前放着一只铜鼓，一边敲一边扯着嗓子唱些肉麻的话。\n");
        set("gender", "男性");
        set("age", 43);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);
        set("combat_exp", 4000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);

//      create_family("星宿派", 3, "吹鼓手");

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
"鼓手敲着铜鼓，高声唱道，“星～宿～老～仙，威～震～寰～宇”。\n",
"鼓手敲着铜鼓，高声唱道，“星～宿～老～仙，德～配～天～地”。\n",
"鼓手敲着铜鼓，高声唱道，“星～宿～老～仙，古～今～无～比”。\n",
        }) );

        carry_object("/d/xingxiu/obj/tonggu")->wield();
}

