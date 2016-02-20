//Cracked by Roath
// /d/xingxiu/beijiang.c
// Jay 3/17/96
// Ryu
inherit ROOM;

void create()
{
        set("short", "城中心");
        set("long", @LONG
伊犁河谷，气候温和，雨水充沛，物产丰饶。大街小巷上，商　林立，
百货云屯，市肆繁华。人来人往，十分热闹。西边是巴扎集市，北边人声
鼎沸，好像在举行什麽比赛。东面有家院落，院门口有棵大树。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"store",
        "east" : __DIR__"house",
        "northwest" : __DIR__"saimachang",
        "south" : __DIR__"yili",
]));
        set("objects", ([
                __DIR__"npc/woman": 1,
                __DIR__"npc/shushi": 1
                 ]) );
		
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
