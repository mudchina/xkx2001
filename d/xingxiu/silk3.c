//Cracked by Roath
// /d/xingxiu/silk3.c
// Ryu 

inherit ROOM;

// int do_climb();

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这条中原和西域的通道，在沙包遍地、红柳丛生的大沙漠上，弯弯曲
曲地向前延伸。朝远处眺望，但见无边无际的茫茫沙海上，被旋风卷起的
沙柱，时而蓦地腾空而起，如狂奔野马，顶天立地，呼啸而来。一会儿又
似袅袅炊烟渐渐远行，徐徐散去。
LONG
        );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "southeast" : __DIR__"silk2",
		"west" : __DIR__"silk4",
        ]));
        set("item_desc", ([
                "mount" : 
        "这是一座黄沙堆积形成的山。微风吹动，沙山发出嗡嗡的响声。你\n" 
	"不禁对自然的造物发出由衷的赞叹。\n"
        ]) );

	set("cost", 2);
        setup();
}

/*void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="mount") {
                message("vision",
		me->name() + "吭吃吭吃向沙山上爬去。\n",
                environment(me), ({me}) );
                me->move("/d/xingxiu/shashan");
                message("vision",
                me->name() + "从沙山下爬了上来，粘了一身沙子。\n",
                environment(me), me );
                return 1;
        }
}
*/
