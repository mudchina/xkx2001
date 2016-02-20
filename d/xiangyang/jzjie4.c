//Cracked by Roath
// Room: /d/xiangyang/jzjie1.c

inherit ROOM;

void create()
{
        set("short", "荆州街");
        set("long", @LONG
走到此处，已是到了荆州路底，再向南去，可以望见一扇府第大门，面住着一位
了不起的人物。附近有不少的江湖豪士逗留，俱说是为了襄阳存亡天下气运从四方相聚
而来。
LONG
        );
        set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -1 ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dongjie2",
  "south" : __DIR__"guofu",
]));
        set("outdoors", "xiangyang");

        setup();
        replace_program(ROOM);
}
