//Cracked by Roath
// Room: /d/village/alley1.c

inherit ROOM;

void create()
{
        set("short", "小巷");
        set("long", @LONG
这是一条黑暗、肮脏的小巷，空气中仿佛飘扬着一股罪恶的气息，西北边通
向小巷深处，正人君子是不会往那边走去的。往东走就会回到村中大路了。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sroad3",
  "northwest" : __DIR__"alley2",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}


