//Cracked by Roath
// 玉泉
// Dong  11/03/1996.
// modified by aln  2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "玉泉");
   set("long", @LONG
玉泉寺建在玉泉山上，原名清涟寺。走进玉泉寺，只见这里有几个水池(pond)。
朝东就是出寺下山的路。
LONG
        );

   set("exits", ([ /* sizeof() == 1 */ 
                  "eastdown" : __DIR__"road15", 
                  "west" : __DIR__"shuyuan",
                ])
       );
	set("objects", ([
                "/d/huashan/npc/youke" : 1,
        ]));
       
	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
}

void init()
{
   add_action("do_look","look");
   add_action("do_fishing","看");
   add_action("do_fishing","fishing");
   add_action("do_fishing","钓鱼");

}
int do_look(string arg)
{  
   if( !arg || arg=="" ) return 0;
   if( arg=="pond" )
   {   switch (random(3)) {
   	 case 0:
   		write("池旁的石碑刻着“鱼乐国”，池里养了百条数十斤重的大鱼(fish)。\n");
		write("鱼儿沉浮上下，游客们纷纷投饵喂鱼。\n");
		break;
	 case 1:
   		write("池旁的石碑刻着“古珍珠泉”，池内偶有小水泡上涌，好象一串珍珠\n");
		break;
	 case 2:
   		write("池旁的石碑刻着“晴空细雨池”，阳光照射在池水上，看上去好像落\n");
		write("着细雨。\n");
		break;
	return 1;
   }
   if( arg=="fish" )
   {	int f;
	f = (int)((int)this_player()->query("food") / (int)this_player()->max_food_capacity() * 100);
	if (f > 50)
	{   write("这是一条红鲤鱼，它自由自在游来游去。真可爱．\n");
	}
	else
	{   message_vision("$N盯着一条红鲤鱼，不停的咽着快要流出来的口水\n", this_player());
	}
   }
   return 1;
}
}
int do_fishing()
{  message_vision("$N从袋里掏出一条鱼竿，在游客诧异的眼光下开始钓鱼。。。\n", this_player());
   message_vision("哇！不一会儿一条大红鲤鱼上钩了。$N兴高采烈的抓着鱼，游客们\n", this_player());
   message_vision("却都愤怒瞪着$N，在众目窥窥之下$N只好灰溜溜的把鱼放回池中。\n", this_player());
   return 1;
}
