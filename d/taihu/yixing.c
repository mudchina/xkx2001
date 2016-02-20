//Cracked by Roath
// /d/taihu/yixing.c
// by aln  2 / 98

inherit ROOM;

void create()
{
    int i;
        set("short", "宜兴");
        set("long", @LONG
这儿便是天下闻名的陶都，青山绿水之间掩映着一堆堆紫砂陶坯，另
有一番景色。向东行，不远处就是太湖边。南方便是湖州府了。
LONG
        );

        set("exits", ([
                "southeast"  : __DIR__"field1-2",
		"south" : __DIR__"nanxun",
		"north" : "/d/city/wdroad1",
        ]));

	set("outdoors", "taihu");

	set("cost", 2);
        setup();

	replace_program(ROOM);
}

