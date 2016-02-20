//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "长堤");
        set("long", @LONG
这里一边是一座小山，一边是莹莹的湖水，转了几个弯，遍地都是
梅树，老干斜横，枝叶茂密，想像初春梅花盛开之日，香雪如海，定然
观赏不尽。
LONG
        );
        set("exits", ([
		"west" : "/d/hangzhou/suti4",
		"east" : __DIR__"mzgate"
	]));

        set("no_clean_up", 0);

	set("cost", 2);
	setup();
	set("outdoors","quanzhou");
	replace_program(ROOM);
}


