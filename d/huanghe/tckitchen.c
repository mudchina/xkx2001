//Cracked by Roath
// /d/huanghe/tckitchen.c

inherit ROOM;

void create()
{
        set("short", "小茅舍");
        set("long", @LONG
推开门一看，原来这是一小小的厨房，左面有一个焦黑的土灶，看来已经
很久未用过了。灶边有一个大水缸（gang)。
LONG );

        set("exits", ([
		"east" : __DIR__"tcxiaolu",
        ]));

	set("item_desc",([
	    "gang" : 
"一囗盛满了水的大水缸，缸里的水好象刚倒进去不久，水缸看上去非常沉重。\n"
	]));

    	set("cost", 1);

        setup();
        // replace_program(ROOM);
}

int init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object me = this_player();

        if( !arg || arg != "gang" )
                return 0;

        if( query("exits/down") )
                return notify_fail("水缸已经被移开了。\n");

        if( me->query_str() < 22 ) {
                message_vision("$N使劲地推了一下水缸，结果水缸纹丝不动。\n", me);
                return 1;
        }

        message_vision("$N抱起水缸放在一旁，缸底便露出一个大铁环来。\n", me);
        message_vision("$N随即抓住铁环，往上一提，忽喇一声响，一块铁板应手而起，现出一个大洞。\n", me);
        set("exits/down", __DIR__"tctongdao");
        return 1;
}

void reset()
{
        ::reset();

        if( query("exits/down") ) {
                message("vision", "只见一名铁叉帮众过来将水缸移回原处。\n", this_object());
                delete("exits/down");
        }
}
