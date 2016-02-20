//Cracked by Roath
// room: /mingjiao/xinkaiquan.c

inherit ROOM;

void create()
{
        set("short", "新开泉");
        set("long", @LONG
这是夹在南北两侧高山间的峡谷，曲曲折折地向西延伸，也不知有多
长。每逢盛夏高山积雪溶化，谷中都形成涓涓溪流，秋冬之际却干涸无水。
正因如此，谷中没有高大树木，到处可见突出的碎石。
LONG );

        set("exits", ([
                "eastup" : __DIR__"xingzi",
                "west" : __DIR__"yushuquan",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/water", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}