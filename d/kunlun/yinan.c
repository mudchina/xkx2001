//Cracked by Roath
// room: /mingjiao/yinan.c

inherit ROOM;

void create()
{
        set("short", "倚南山");
        set("long", @LONG
登山向西观望，视野十分开阔，却只见黄沙漫漫，渺无人烟。长啸一
声，空中只有尖锐的鹰唳回应，使人心中不禁涌起阵阵落寞孤独的感觉。
LONG );

        set("exits", ([
                "northdown" : __DIR__"yushuquan",
                "southeast" : __DIR__"douxian",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}

