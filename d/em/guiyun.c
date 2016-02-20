//Cracked by Roath
// /d/emei/guiyun.c 归云阁 
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "归云阁");
        set("long", @LONG
归云阁，原是唐代福昌达道禅师的道场。宋代绍兴年间，僧人士性又率众
重建。归云阁左有玉女峰，西上可抵纯阳殿，东下是观音堂。
LONG
        );
        set("exits", ([
		"southup" : __DIR__"yunu",
		"westup" : __DIR__"chunyang",
                "eastdown" : __DIR__"guanyin",
        ]));

        set("objects", ([
	          __DIR__"npc/m_dizi1" :2,
        ]));

	set("outdoors", "emei");

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
