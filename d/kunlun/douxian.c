//Cracked by Roath
// room: /mingjiao/douxian.c

inherit ROOM;

void create()
{
        set("short", "兜衔山");
        set("long", @LONG
但见此山绵延曲折，看似拐了一个大弯。山路倒也平坦，然漫山遍野
布满不及腰高低矮灌丛。有些生满尖锐小刺，若不小心便会划的鲜血淋漓。
LONG );

        set("exits", ([
                "eastdown" : __DIR__"longquangu",
                "northwest" : __DIR__"yinan",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}