//Cracked by Roath
// hz_zhaitang.c 华藏庵斋堂
// Shan: 96/06/22

#include <room.h>
inherit ROOM;

string look_door();

string* names = ({
        __DIR__"obj/mala-doufu",
        __DIR__"obj/bocai-fentiao",
        __DIR__"obj/shanhu-baicai",
        __DIR__"obj/liuli-qiezi",
});

void create()
{
        set("short", "华藏庵斋堂");
	set("long", @LONG
这里便是峨嵋华藏庵的斋堂。斋堂里摆满了长长的餐桌和长凳，几位小
师太正来回忙碌着布置素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美
味素食。斋堂后面有一道门通往华藏庵储物间，北边的走廊通向广场。
LONG
	);
	set("exits", ([
		"south" : __DIR__"chuwu",
		"north" : __DIR__"hz_donglang2",
	]));

        set("objects",([
                __DIR__"obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
        ]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        create_door("south", "木门", "north", DOOR_CLOSED);

	set("cost", 0);
	setup();
	replace_program(ROOM);

}

string look_door()
{
        return "一道小门连通斋堂与藏经阁。\n";
}

