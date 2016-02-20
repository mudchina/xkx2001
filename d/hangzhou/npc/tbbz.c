//Cracked by Roath
// /d/hangzhou/npc/tbbz 塘帮帮众
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("塘工", 
              ({ "tanggong", }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"这是一位修筑海堤的塘工。\n");
        set("combat_exp", 4000);
        set("shen_type",  -1);

        set_skill("cuff", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}
