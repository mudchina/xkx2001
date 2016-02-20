//Cracked by Roath
// /d/forest/npc/cl_huoji.c  长乐帮伙计
// by aln 2 / 98

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("长乐帮伙计", ({ "huoji", "keeper" }));
        set("str", 20);
        set("gender", "男性");
        set("age", 25);
        set("long", "他是个勤劳的伙计，肚子里也有些墨水。\n");
        set("combat_exp", 2500);
        set("attitude", "friendly");

        setup();
}
