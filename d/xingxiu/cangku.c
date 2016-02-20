//Cracked by Roath
// Room: /d/xingxiu/xxroad5.c

inherit ROOM;

void create()
{
        set("short", "星宿派储藏室");
        set("long", @LONG
这里原来是一个长在山壁上的天然溶洞，因为地点隐密而且洞中空气十分
干燥，星宿派把这里改造成了一个仓库。
LONG
        );
        set("exits", ([
  "out" : __DIR__"xxroad5",
]));
        set("objects", ([
                __DIR__"obj/hulu"  : 2,
                DRUG_D("menghan_yao")  : 1,
                __DIR__"obj/dujing_1"  : 1,
		__DIR__"obj/lianxin" : 1,
                DRUG_D("xxqingxin-san") : 1]));

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
        replace_program(ROOM);
}
