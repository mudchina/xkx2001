//Cracked by Roath
// /d/changbai/npc/yu.c

inherit NPC;

void create()
{
        set_name("玉真子", ({ "yuzhen zi", "yuzhen", "zi" }));
        set("nickname", "护国真人");
        set("title", "铁剑门掌门人");
        set("long",
"他身上道袍葛中夹丝，灿烂华贵，道冠上镶着一块晶莹白玉，光华四射。\n"
"他一身清气，飘飘然有出尘之概，显是一位得道高人。\n");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 1800);
        set("max_jing", 1800);
        set("neili", 1800);
        set("max_neili", 1800);

        set("jiali", 80);

        set("combat_exp", 1100000);

        set_temp("apply/armor", 50);

        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("parry", 170);
        set_skill("sword", 180);
        set_skill("whip", 180);
        set_skill("cuff", 170);
        set_skill("ding-force", 180);
        set_skill("lingbo-weibu", 180);
        set_skill("wugou-jianfa", 180);
        set_skill("canglang-bian", 180);
        set_skill("wuxing-quan", 170);

        map_skill("cuff", "wuxing-quan");
        map_skill("force", "ding-force");
        map_skill("parry", "canglang-bian");
        map_skill("whip", "canglang-bian");
        map_skill("sword", "wugou-jianfa");
        map_skill("dodge", "lingbo-weibu");

        prepare_skill("cuff", "wuxing-quan");

        setup();

        carry_object("/clone/weapon/fuchen")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();
}




