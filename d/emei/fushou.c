//Cracked by Roath
// /d/emei/fushou.c 福寿庵
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "福寿庵");
	set("long", @LONG
福寿庵在神水庵南，是一个名叫天性的僧人建造的。庵前有九曲渠、流杯
池，古人曾据在此饮酒流杯，观景赋诗，歌咏兴叹，不知夕日。庵旁有株大海
棠树，数百苍龄，高达十余丈。
LONG
	);
	set("exits", ([
		"north" : __DIR__"shenshui",
		"enter" : __DIR__"fushou1",
	]));

        set("objects", ([
		CLASS_D("emei") + "/jingzhen" :1,
		__DIR__"npc/f_dizi1" :1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
