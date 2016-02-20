//Cracked by Roath
// hz_donglang2.c 华藏庵东廊
// Shan: 96/06/22

#include <room.h>
inherit ROOM;


void create()
{
        set("short", "华藏庵东廊");
	set("long", @LONG
这里是峨嵋华藏庵东廊。走廊往南通往斋堂，北边通往广场。
LONG
	);
	set("exits", ([
		"north" : __DIR__"hz_donglang1",
		"south" : __DIR__"hz_zhaitang",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);

}


