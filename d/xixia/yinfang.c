//Cracked by Roath
// Room: /d/xixia/yinfang.c

inherit ROOM;

void create()
{
	set("short", "营房");
	set("long", @LONG
这里是骠骑营的营房，一排排木屋煞是齐整, 门口空地许多军士
们围成个圈在喧闹，西夏军中崇尚勇力，佩服的是英雄，士兵个个都
是彪形大汉。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"biaoqiyin",
]));
	set("objects", ([
                __DIR__"npc/xxbing2" : 3,
        ]));
	set("cost", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
