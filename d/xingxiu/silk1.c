//Cracked by Roath
// /d/xingxiu/silk1.c
// Ryu  

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这里是风沙弥漫的丝绸之路，一片荒凉景象。可是那有几人合抱之
粗的古老胡杨，仍然笑迎风沙，挺立在荒原上，为行人指引方向。东边
一座红色的高山，山下有路向东可至嘉峪关，西面则通往西域。
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
                "east" : "/d/qilian/danshan",
		"west" : __DIR__"silk2",
        ]));

	set("cost", 2);
        setup();
        replace_program(ROOM);
}

