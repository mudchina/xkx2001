//Cracked by Roath
// room: /mingjiao/monan.c

inherit ROOM;

void create()
{
        set("short", "末南山");
        set("long", @LONG
此山位处昆仑北麓，早先命名之人从北面行至此处，误以为已经
到了昆仑尽头，故称之为“末南”。这里也是山势巍峨，却似一个不
怒而威的巨人。侧耳倾听时，东面传来阵阵水声，想必是一条大河。
LONG );

        set("exits", ([
                "eastdown" : __DIR__"tongtianhe",
                "southdown" : __DIR__"bailongdui",
                "northdown" : __DIR__"tushantai",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}