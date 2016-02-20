//Cracked by Roath
// /d/shenlong/obj/yaofang.c  药方
// by aln  10 / 97

inherit ITEM;

void create()
{
        set_name("药方", ({"yaofang"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",
                        "上面密密麻麻写满了字，列出各类药草，配制方法和服法用途。\n");
                set("material", "paper");
        }
}
