//Cracked by Roath
// /d/hangzhou/npc/hsbz.c  天鹰教众
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("天鹰教众", 
              ({ "tianying jiaozhong", "jiaozhong" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"他身穿青布短衫裤，头戴斗笠，身形壮实。\n");
        set("combat_exp", 5000);
        set("shen_type",  -1);

        set_skill("cuff", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}
