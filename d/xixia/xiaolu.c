//Cracked by Roath
// Room: /d/xixia/xiaolu.c

inherit ROOM;

void create()
{
	int i;
	set("short", "林中小路");
	set("long", @LONG
这是陡坡上的一条杂草丛生的羊肠小路，看起来平时没什么人迹，路边开着
不知名的野花，两边的松树依然高大、挺拔。阳光透下来照的你身上是斑斑驳驳
的影子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaolu2",
  "south" : __DIR__"dalu",
]));
	i = random (3);
        switch (i) {
        case 0:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/city/obj/branch4" : 1,
            "/d/quanzhou/npc/wuya" : 1,
        ]));
        break;
        case 1:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/wudang/npc/yetu" : 1,
        ]));
        break;
        case 2:
        set("objects", ([
            "/d/city/obj/branch3" : 1,
            "/d/xingxiu/npc/snake" : 1,
        ]));
        break;
        }
	set("cost", 2);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}