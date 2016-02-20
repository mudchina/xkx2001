//Cracked by Roath
// /clone/board/wumiao_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("武庙告示板", ({ "board" }) );
        set("location", "/d/city/wumiao");
        set("board_id", "wumiao_b");
        set("poster_level", "(apprentice)");
        set("long", "这是供巫师贴告示用的，玩家不能张贴。\n");
        set("intermud", 1);
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

