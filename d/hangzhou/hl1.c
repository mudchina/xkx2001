//Cracked by Roath
// Room: /d/hangzhou/hl1.c

inherit ROOM;

void create()
{
	set("short", "黄龙洞");
	set("long", @LONG
一进山门，松篁交翠，别有洞天。石壁陡削，苔痕常绿；回廊临
池，藤萝结。池後石涯上雕刻的黄龙头，泉水从龙口下注入池。池岩
之间有一小峰，上题：“有龙则灵”。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beishan1",
]));
	set("objects", ([
                "/d/xingxiu/npc/snake" : 1,
        ]));

	set("cost", 3);
	setup();
	replace_program(ROOM);
}
