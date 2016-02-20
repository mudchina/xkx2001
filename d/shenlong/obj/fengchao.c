//Cracked by Roath
// /d/shenlong/obj/fengchao.c
// by aln 4 / 98

inherit ITEM;

void create()
{
        set_name("蜂巢", ({ "fengchao", "chao" }));
        set("unit", "只");
        set("long", "这是一只六角形的毒蜂巢，是稀有的药材。\n");
        set("value", 2000);
        setup();
}

