//Cracked by Roath
inherit BULLETIN_BOARD;

void create()
{
        set_name("侠客岛告示牌", ({ "board" }) );
        set("location", "/d/xiakedao/dadong");
        set("board_id", "xkd_b");
        set("long", "一块白杨木的牌子。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

