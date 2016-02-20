//Cracked by Roath
// /d/hangzhou/mh_book.c
// by aln  2 / 98

inherit ITEM;

void create()
{
        set_name("《明书辑略》", ({ "mingshi", "shi", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这是一本明史，乃湖州庄氏延请许多通士鸿儒根据朱国桢原稿增删而成。\n");
                set("value", 80);
                set("material", "paper");
        }
}
