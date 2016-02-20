//Cracked by Roath
// room: /mingjiao/longquangu.c

inherit ROOM;

void create()
{
        set("short", "龙泉谷");
        set("long", @LONG
一条宽阔的山谷中，丛生的杂草几乎有一人多高。地势虽起伏不大，
道路却左盘右拐，湮没难辨。长草随风摇摆，呼啦啦地到也颇有节律。北
方是一座高山。
LONG );

        set("exits", ([
                "northeast" : __DIR__"qingshuigou",
                "westup" : __DIR__"douxian",
                "northup" : __DIR__"xingzi",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}