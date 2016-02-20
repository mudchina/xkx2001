//Cracked by Roath
// fushou3.c 福寿庵斋堂

#include <room.h>
inherit ROOM;

string* names = ({
        __DIR__"obj/mala-doufu",
        __DIR__"obj/bocai-fentiao",
        __DIR__"obj/shanhu-baicai",
        __DIR__"obj/liuli-qiezi",
});

void create()
{
        set("short", "福寿庵斋堂");
	set("long", @LONG
这里便是峨嵋福寿庵的斋堂。福寿庵本不大，但由于经常接待其他庵的弟子，
斋堂倒也不小。只见厅内摆满了长长的餐桌和长凳，几位小师太正来回忙碌着布置
素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。北面有一扇门(door)。
LONG
	);
	set("exits", ([
		"northup" : __DIR__"fushou2",
		"east"    : __DIR__"fushou1",
	]));

        set("item_desc",([
                "door"  : "一扇小门通往北面楼上的休息室。\n",
        ]));

        set("objects",([
                __DIR__"obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
        ]));

        create_door("northup", "木门", "southdown", DOOR_CLOSED);

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
