//Cracked by Roath
// chuwu.c 储物间
// Shan: 96/06/22

#include <room.h>
inherit ROOM;

string look_door();

string* names = ({
        __DIR__"obj/changjian",
        __DIR__"obj/zhujian",
	__DIR__"obj/zhudao",
//        __DIR__"obj/changbian",
        __DIR__"obj/fuchen",
});

void create()
{
        set("short", "储物间");
	set("long", @LONG
这里便是峨嵋华藏庵的储物间，四周都是架子。一个架上放满了各样兵
器，有长剑，拂尘，长鞭等，琳琅满目。另一个架上放了各种防具。还有一
个架上摆了许多小柜子，原来是装满药品的药柜。一位师太负责管理这里的
物品，正忙碌着整理防具。后面好象有个小楼梯。门外就是斋堂了。
LONG
	);
	set("exits", ([
		"up" : __DIR__"cangjing",
		"north" : __DIR__"hz_zhaitang",
	]));

        set("objects",([
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
                CLASS_D("emei") + "/jingfeng" : 1,
        ]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        create_door("north", "木门", "south", DOOR_CLOSED);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

string look_door()
{
        return "一道小门连通斋堂与储物间。\n";
}

void reset()
{
	delete_temp("tianxiang");
	delete_temp("liuyedao");
	delete_temp("yaodai");
	delete_temp("ruanjian");
	return ::reset();
}
