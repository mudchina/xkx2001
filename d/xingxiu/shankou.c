//Cracked by Roath
// Ryu 5/10/97
inherit ROOM;

void create()
{
        set("short", "山口");
        set("long", @LONG
天山又名凌山、三弭山，天山之称始於西汉，但那时天山与祁连
山被混为一谈，匈奴人呼天作“撑犁”，“祁连”即“撑犁”之音转。
直到唐代，天山和祁连山才被区分开来，天山的范围才被明确，即从
玉门关外，直到伊塞克湖以西。从这里有两条路进山，从西面的银山
道可到星宿海，北面的阿拉沟则可至灵山天池。
LONG
        );
        set("exits", ([
            "northup" : __DIR__"alagou1",
            "eastdown" : __DIR__"tianroad1",
            "westup" : __DIR__"yinshan",
]));

	set("objects", ([
                __DIR__"npc/wu"  : 1,
        ]) );

        set("cost", 3);
        set("resource/grass", 1);
        setup();
        replace_program(ROOM);
        set("outdoors", "xingxiuhai");

}
