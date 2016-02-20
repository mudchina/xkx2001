//Cracked by Roath
// /d/hangzhou/npc/hsbz.c  ÑÎèÉ
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("º£É³ÅÉÑÎèÉ", ({ "yanxiao" }) );
        set("gender", "ÄĞĞÔ");
        set("age", 25);
        set("long",
"ËûÉí´©Çà²¼¶ÌÉÀ¿ã£¬Í·´÷¶·óÒ£¬ÉíĞÎ×³Êµ¡£\n");
        set("combat_exp", 4500);
        set("shen_type",  -1);

        set_skill("unarmed", 30);
        set_skill("blade", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/city/obj/douli")->wear();
}
