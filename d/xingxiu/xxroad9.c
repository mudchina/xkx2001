//Cracked by Roath
// Room: /d/xingxiu/xxroad9.c

inherit ROOM;

void create()
{
        set("short", "山间荒地");
        set("long", @LONG
你站在两山间的荒地上，放眼望去，尽是枯树败草，朔风萧杀，吹得长草起
伏不定。东边是一片平地，北边进入山谷深处。
LONG
        );
	switch(random(4)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                break;
        case 1:
        case 3:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
	}

        set("exits", ([
  "northdown" : __DIR__"xxroad10",
  "eastup" : __DIR__"xxroad6",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 2);
	set("bing_can", 20);
        setup();
        replace_program(ROOM);
}
