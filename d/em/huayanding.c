//Cracked by Roath
// huayanding.c 华严顶
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "华严顶");
        set("long", @LONG
华严顶挺拔高峭，古刹云深，殿宇孤耸，风景奇险。这里视野开阔，仰可
见金顶巍巍，俯可望群峰罗列，许多蹲伏山间的寺院也在眼底。由此向西过数
坡，即到莲花石，东下过十二盘可到万年寺。北面是一间马厩。
LONG
        );
        set("exits", ([
                "westup" : __DIR__"lianhua",
		"down" : __DIR__"pan12",
		"north" : __DIR__"majiu2",
        ]));

        set("objects",([
                __DIR__"npc/f_dizi1" : 1,
                CLASS_D("emei") + "/li" : 1,
        ]));

        set("no_clean_up", 0);

        set("outdoors", "emei");

        setup();
        replace_program(ROOM);
}
