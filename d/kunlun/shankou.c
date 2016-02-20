//Cracked by Roath
// room: /mingjiao/shankou.c

inherit ROOM;

void create()
{
        set("short", "光明顶山口");
        set("long", @LONG
此处乃是明教根本之地－－光明顶。山势开阔，北面大片的房屋便是
总舵。明教传至中土已近百年，行事颇有诡秘难测之处。武林中人常常称
之为“魔教”。
LONG );

        set("exits", ([
                "north"     : __DIR__"damen",
                "southdown" : __DIR__"shanlu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
