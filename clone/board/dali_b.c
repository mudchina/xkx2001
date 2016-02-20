//Cracked by Roath
inherit BULLETIN_BOARD;

void create()
{
        set_name("王府告示牌", ({ "board" }) );
        set("location", "/d/dali/wangfu1");
        set("board_id", "dali_b");
        set("long", "一块白杨木的牌子。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

