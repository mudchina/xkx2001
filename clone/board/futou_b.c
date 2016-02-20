//Cracked by Roath
// /clone/board/futou_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("斧头帮留言板", ({ "board" }) );
        set("location", "/d/city/ft_datang");
        set("board_id", "futou_b");
        set("long", "这是一个供斧头帮帮众交流的留言板。\n" );
        setup();
        set("capacity", 60);
        replace_program(BULLETIN_BOARD);
}
