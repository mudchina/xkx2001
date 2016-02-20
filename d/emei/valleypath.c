//Cracked by Roath
// d/emei/valley.c 山谷小径
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "山谷小径");
	set("long", @LONG
这是山谷中的小径，通向草木幽深之处。两旁生着各种花草树木，冬青草，
木槿，木莲花，莎椤花，蕙兰，木芙蓉¨¨¨散发着清幽的香气。
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
	    	"冬青草"	:
"冬青草的叶子呈长而椭园形，开着淡紫红色的小花。\n",
		"木莲花"	:
"木莲花枝条茂蔚，香气仿佛芙蓉花，。\n",
		"莎椤花"	:
"莎椤花根坚难易，不可把玩，古人赞之，以喻洁身自好之高贵品德。\n",
        ]));
        set("exits", ([
                "northeast" : __DIR__"grassland",
                "west" : __DIR__"valley",
        ]));

	set("cost", 2);
	set("flower_count", 10);
	setup();
}

void init()
{
	add_action("do_pick", "pick");
	add_action("do_pick", "zhai");
}

int do_pick(string arg)
{
	object me = this_player();
	object flower = new(__DIR__"obj/flower");

	if ( !arg || arg == "") return 0;

	if ( arg == "flower" ){
		if (query("flower_count") < 1) {
			tell_object(me, "能摘的花已经摘光了。\n", me);
			return 1;
		}
		else {
                	message_vision("$N摘下一朵野花。\n", me);
			flower->move(me);
			add("flower_count", -1);
	        	return 1;
		}
	}
	return 0;
}

