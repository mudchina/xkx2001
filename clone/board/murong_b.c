//Cracked by Roath
inherit BULLETIN_BOARD;

void create()
 {        set_name("燕子坞留言牌", ({ "board" }) );
        set("location", "/d/murong/qing4");
        set("board_id", "murong_b");
        set("long", "一块留言用的板子。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}