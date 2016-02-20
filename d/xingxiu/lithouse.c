//Cracked by Roath
// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96
// Ryu 5/10/97

inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long", @LONG
这是一间简陋的小木屋，屋里臭烘烘地，让人觉得十分不舒服。
在昏暗的光线下，你看见屋里有一个石头做成的箱子(box)。不
知道有什么用处。
LONG
        );
        set("exits", ([
            "east" : __DIR__"tianroad2",
]));
        set("resource/grass", 1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("item_desc",([
                "box"         :       "一个棺材大小的箱子，里面隐隐的有一些血迹。\n",
        ]));
	
        set("cost", 3);
        setup();
//      replace_program(ROOM);
}
