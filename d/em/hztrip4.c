//Cracked by Roath
//Jay 9/30/96

inherit ROOM;

void create()
{
        set("short", "小树林");
	set("long", @LONG
这是峨嵋山金顶华藏庵外的一片小树林。北边是峨嵋派女弟子们的寝宫的
窗户，窗下好像蹲着一个人。
LONG);
	set("exits", ([
		"northwest" : __DIR__"hztrip3",
		"north" : __DIR__"sleeproom",
	]));
	set("objects", ([
		__DIR__"npc/qingshu" : 1,
	]));

        set("outdoors", "emei" );

	set("cost", 2);
	setup();

}

int valid_leave(object me, string dir)
{
	if (dir=="north") {
	return notify_fail("你好大的胆子，想闯峨嵋女弟子的寝宫？\n");
	}
	   return ::valid_leave(me, dir);
}

