//Cracked by Roath
// room: shufang.c

inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这是天鹰教的书房，靠墙摆放着一溜书架，上面整齐地排列着各
种书籍。屋子正中是一张墨色小几，几上的香炉冒出缕缕轻烟，几前
有个蒲团可供你盘坐而读，除此之外别无他物。
LONG );

        set("exits", ([
                "west" : __DIR__"dating",
        ]));

        setup();
        replace_program(ROOM);
}
