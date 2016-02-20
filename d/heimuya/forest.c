//Cracked by Roath
// Room: /d/heimuya/forest.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "树林");
        set("long", @LONG
这是平定州郊外的树林，树林里时常有很多野兽出
没。林边有两三个猎人正骑着马，背负长弓，泼刺刺的
纵马疾驰，追赶着野兔。
LONG
        );

        set("exits", ([
                "east" : __DIR__"heimulin1",
                "south" : __DIR__"northgate",
        ]));

        set("objects", ([
                "/clone/beast/yetu" : 1,
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

