//Cracked by Roath
// /d/xingxiu/silk2.c
// Ryu 

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是一条中原和西域之间的商道。一个个沙包展现在你的眼前，每
一个沙包上都长有一丛枝叶茂繁的红柳，看上去宛若一个个苍翠的小岛，
星罗棋布於荒原之上。南面连绵的祁连山脉在阳光的照射下好像是一条
玉带。东边是中原，西面则通往西域。
LONG
        );
        switch(random(3)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        }
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "east" : __DIR__"silk1",
		"northwest" : __DIR__"silk3",
        ]));

	set("cost", 2);
        setup();
        replace_program(ROOM);
}

