//Cracked by Roath
// gate.c
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "萧府大门");
        set("long", @LONG
这里是晋阳大侠萧半和的家宅。院墙高丈许，中立朱漆大门(men)两扇。
门上张灯(deng)结彩，墙内传出贺寿之声好不热闹。不时有宾客来至，将贺礼
递给门口的佣人，然候整衣而入。西边一条小路通往山脚下。
LONG
        );

        set("objects", ([
	    __DIR__"npc/zhangma" : 1,
	]));

        set("exits", ([
                "east" : __DIR__"forest7",
		"west" : __DIR__"foot",
        ]));

	set("item_desc", ([
		"men" : "大门紧闭，非请莫入。\n",
		"deng" : "大红灯笼高高挂，上书寿字。\n",
	]));
	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

