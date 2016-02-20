//Cracked by Kafei
// Room: /d/quanzhou/nanhu.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖");
	set("long", @LONG
这里是嘉兴南湖。节近中秋，荷叶渐残，莲肉饱实。一阵轻柔
婉转的歌声，飘在烟水蒙蒙的湖面上。湖边一个道姑在一排柳树下
悄立已久。湖边有几个农人在打水。
LONG
	);

	set("exits", ([
                "west" : __DIR__"jiaxing",
		"south" : __DIR__"tieqiang",
                "southeast" : __DIR__ "nanhu1",
	]));

        set("resource/water", 1);


	set("outdoors", "quanzhou");
        set("objects", ([
            "/kungfu/class/gumu/limochou" : 1,
            "/kungfu/class/gumu/hong" : 1]));

	set("cost", 2);
	setup();
	replace_program(ROOM);
}

