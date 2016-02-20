//Cracked by Roath
// room: /mingjiao/yanan.c

inherit ROOM;

void create()
{
        set("short", "雅南山");
        set("long", @LONG
这里向前，便已经进入昆仑山脉，江湖上人人敬畏的明教也隐藏在昆
仑之中。山势渐高，疾风阵阵，你不禁打了个寒战。抬首望去，只见连绵
无尽的千山万岭，浩瀚无穷，不知隐藏了多少故事。
LONG );

        set("exits", ([
                "eastup" : __DIR__"lingjia",
//                "west" : __DIR__"???????",
        ]));

	set("objects",([
		__DIR__"obj/xiaohuangshi" : 2,
]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 3);

        setup();
        replace_program(ROOM);
}