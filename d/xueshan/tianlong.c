//Cracked by Roath

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "天龙殿");
	set("long", @LONG
殿中空无一物，只有北壁下一幅佛陀转法轮图(picture)，角落里点
有几盏酥油灯，闪着诡异的黄光，殿东西壁间挂着一根铁链，将空间分割
成幽冥二界。铁链微微晃动，发出吱吱的声响。
LONG
	);

	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("item_desc", ([
                "picture" : "佛结跏趺坐於莲座上，手结转轮印，座下有法轮和双鹿，喻示鹿野苑说法，顶\n"
			    "履华盖，背後饰帷帐，各路天神及众比丘及外道瑜迦行者跪坐两侧倾听说法。\n",
        ]));
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me=this_player();

	if( !arg || arg=="" ) return 0;

	if ( me->query_skill("lamaism", 1) < 150) return 0;

	if ( arg == "picture" ) {
	tell_object(me, "你朝壁画走去。\n");
	message("vision",
                        me->name() + "轻飘飘地朝壁画走去，身影便隐没在壁画中了。\n",
                        environment(me), ({me}) );
                me->move("/d/xueshan/wangyou");
                message("vision",
                        me->name() + "从外面走了进来。\n",
                        environment(me), ({me}) );
                return 1;
        }
}
