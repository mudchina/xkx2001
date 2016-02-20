//Cracked by Roath
// /d/emei/fuhu.c 伏虎寺
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "伏虎寺");
        set("long", @LONG
伏虎寺是入山第一大宝刹，隐伏在高大的乔木林间，四周楠木参天，多达
十万余株。伏虎寺气象庄严，规模宏盛，殿堂宽敞，势度巍峨。寺刹虽掩覆于
翠绿浓黛之中，但屋瓦却无一片落叶。出寺西上解脱坡便是观音堂。
LONG
        );
        set("exits", ([
                "east" : __DIR__"fuhuroad",
		"westup" : __DIR__"fuhuroad2",
        ]));

        set("objects", ([
                __DIR__"npc/m_dizi1": 1,
                __DIR__"npc/f_dizi1": 1,
        ]));

	set("outdoors", "emei");

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
