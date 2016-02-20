//Cracked by Roath
// /d/changbai/npc/juren1.c

inherit NPC;

void create()
{
        set_name("忽伦三虎", ({ "san hu", "ju ren" }));
        set("nickname", "巨人");
        set("long",
"他就是忽伦三虎，是辽东宁古塔人氏。\n"
"七尺以上身材，比常人足足要高两个头，身子粗壮结实，实是罕见的巨人。\n");

        set("gender", "男性");
        set("age", 25);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 50);
        set("int", 10);
        set("con", 40);
        set("dex", 15);

        set("max_qi", 800);
        set("max_jing", 300);

        set_temp("apply/damage", 60);
        set_temp("apply/attack", 40);

        set("combat_exp", 40000);

        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("unarmed", 60);

        set_skill("force", 60);

        setup();
}
