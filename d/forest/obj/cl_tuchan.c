//Cracked by Roath
// /d/huanghe/changle/obj/tuchan.c
// by aln 2 / 98

inherit ITEM;

void create()
{
        set_name("关东土产", ({ "tuchan" }));
        set("weight", 200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
"这是一包关东土产。\n");
                set("unit", "包");
                set("material", "wood");
                set("value", 300);
        }
        setup();
}
