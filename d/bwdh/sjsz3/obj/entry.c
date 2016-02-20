//Cracked by Roath
// Entry for Group BWDH
// Apache 10/98

inherit ITEM;

void create() {
    set_name("小组", ({ "entry"}) );
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "小组记录\n");
        set("no_get",1);
        set("no_clean_up", 1);
    }
    setup();
}
