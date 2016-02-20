//Cracked by Kafei
// road: /zhongnan/gumu.c

inherit ROOM;

void create()
{
        set("short","古墓");

        set("long",@LONG
    你走过了草地，眼前突然了一片开阔地，突兀地耸立着一座大墓，
墓上砌的石头已经班驳了，看的出来这是座古墓。墓前没有立碑，也
没有任何的标记，不知道这是前朝哪位王公大臣的墓穴。墓门口被一
块黑黝黝的大石头(shi)封闭得丝毫不透。
LONG);

		  set("exits",([

				//"enter" : __DIR__"zoudao1",
				"east" : __DIR__"milin3",
				"south" : __DIR__"milin6",
				"west" : __DIR__"milin8",
				"north" : __DIR__"milin5",

							 ]));
	set("item_desc", ([
		"shi": "这是块巨石，怕不有万斤上下，好象锩着断龙石三个字。\n"
	]) );

	set("objects",([
		  "/d/zhongnan/npc/maque" : 3,
	 ]));
	  set("cost",1);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
        add_action("do_move", "move");
}


int do_move(string arg)
{
        object me=this_player();

        if( !arg || arg != "shi" ) {
                return notify_fail("你要移动什么？\n");
        }

        if((int)me->query_str()>33) //膂力大于33
                {
                message_vision("$N站在石前，双掌发力推动巨石，只听得巨石吱吱连声，\n",this_player());
                message_vision("缓缓向后移去，现出一道门户来。\n", this_player());
                set("exits/enter", __DIR__"zoudao1");
                remove_call_out("close");
                call_out("close", 5, this_object());
                }
        else
                message_vision("$N试着推了推巨石，巨石纹丝不动，只得罢了。\n", this_player());
        return 1;
}

void close(object room)
{
        message("vision","只见巨石又吱吱地回到原地。\n", room);
        room->delete("exits/enter");
}
