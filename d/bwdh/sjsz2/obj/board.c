//Cracked by Roath
// Board for Group BWDH
// Apache 10/98

inherit ITEM;

void create() {
    set_name("团体赛成绩版", ({ "board"}) );
    set_weight(10000);
    set_max_encumbrance(500000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "团体赛成绩版存着比武的玩家们的全部成绩。");
        set("value", 10000);
        set("material", "steel");
        set("no_get",1);
        set("no_clean_up", 1);
    }
    setup();
}
