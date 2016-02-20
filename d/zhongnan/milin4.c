//Cracked by Roath
// road: /zhongnan/milin4.c

inherit ROOM;

void create()
{

set("short","树林");

set("long",@LONG
走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，自密
林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。不论往哪ㄦ走尽是茂
密的树林。附近有一团花丛(flowers)。
LONG);

set("item_desc",(["flowers" : "这花丛既深且密，你向后看去几忽看不到底，花间有些孔隙，似乎经常有些动物在丛中钻来钻去。\n",]));

set("exits",([ "north" : __DIR__"milin3",
               "northeast" : __DIR__"milin2",
               "west" : __DIR__"milin6",
]));

set("cost",2);
set("outdoors", "zhongnan");
setup();
//replace_program(ROOM);

}

void init()
{               
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_push", "zuan");
}

int do_push(){

	object room;
	object me=this_player();
	
	if (me->is_busy())
		return notify_fail("你现在正忙着哪！\n");

	if (this_object()->query("hide_person"))
		return notify_fail("你看见里面有影子晃动，还是不钻的好，别有什么猛兽。\n");

	tell_object(me, "你轻轻地推开花木，向里钻了进去。\n");
	
	room = load_object("/d/zhongnan/flowers");
	
	this_object()->set("hide_person",1);
	
	me->move(room);
    return 1;

}
