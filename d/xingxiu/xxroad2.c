//Cracked by Roath
// Room: /d/xingxiu/xxroad1.c
//Modified by Sure 9/17/2000

inherit ROOM;

void create()
{
        set("short", "大道");

        set("long", 
"青石大道往西北方延伸。两旁并没有什么特别的景致可以吸引你驻足。东面
隐隐约约的可以看到扬州城的垛口。西面一条小路通向密林深处，树林中好像笼
罩着一层淡淡的白雾，让你觉得更加诡秘。\n"
        );
        set("exits", ([
  "east" : __DIR__"xxroad1",
  "northwest" : "/d/wudang/wdroad2",
                "west" : __DIR__"btroad",
]));
        set("objects", ([ 
            CLASS_D("baituo")+"/jiading" : 2,
        ]));
        set("outdoors", "xingxiuhai");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
