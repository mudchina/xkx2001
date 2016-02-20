//Cracked by Roath
inherit NPC;

void create()
{
        set_name("丫鬟", ({ "ya huan" }));
        set("gender", "女性");
        set("age", 18);
set("long", "生得仪容不俗，眉目清明，虽无十分姿色，却亦有动人之处。\n");

        set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
        set("shen_type", -1);
setup();

carry_object("/d/city/obj/qun")->wear();

}

