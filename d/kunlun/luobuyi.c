//Cracked by Roath
// room: /mingjiao/luobuyi.c

inherit ROOM;

void create()
{
        set("short", "罗布绎");
        set("long", @LONG
此处是山脚下的密林，只有一线阳光从头顶的枝叶缝隙中零零星星投
洒下来。林内十分气闷，四周树干上亦爬满各种藤蔓，偶尔枝叶间松鼠跳
跃，发出扑簌一响。地上铺满落叶，踩上去直没脚面，一些草菌(caojun)
杂乱地生长着。
LONG );
        set("item_desc", ([
                "caojun"    : "这是一种白色的野生草菌，倒也
小巧可爱，只是不知是否有毒。\n",
        ]));

        set("exits", ([
                "northup" : __DIR__"jiuquan",
                "west" : __DIR__"yanrandu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}