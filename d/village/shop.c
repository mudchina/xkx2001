//Cracked by Roath
// Room: /d/village/shop.c

inherit ROOM;

void create()
{
        set("short", "杂货店");
        set("long", @LONG
这是一间小小的杂货店，经营些油、盐、酱、醋及日用百货，村子里的人多数
是很穷，除了生活必需品，这里很少贩卖其它物品。小店的老板李四不是个喜欢说
话的人，平时总是一付笑咪咪的样子。西面是一间马厩。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"eroad3",
                "west" : __DIR__"majiu",
        ]));
        set("no_clean_up", 0);

        set("objects", ([
                "/clone/npc/xiejian": 1
        ]) );

        setup();
        replace_program(ROOM);
}
