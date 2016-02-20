//Cracked by Roath
// lake.c


inherit ROOM;

void create()
{
        set("short", "高山湖泊");
        set("long", @LONG
阿拉沟的源头在地势高峻的科雄隘口附近。这里有高山湖泊，贮
存了四时不竭的雪水。翻过隘口不远，又可以听见潺潺水响了。站在
山头，土地广阔的焉耆盆地就可以映入眼帘了。
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

        set("exits", ([
                "eastup" : __DIR__"gudao1",
                "southdown" : __DIR__"alagou2",
        ]));
        set("resource/water",1);
        set("outdoors","tianshan");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

