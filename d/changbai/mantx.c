//Cracked by Roath
// Room: mantx.c

inherit ROOM;

void create()
{
	set("short", "满天星");
	set("long", @LONG
这里是一片开阔的平原，附近不但没有任何小山丘陵，就连一棵树也找
不到。抬眼望去，地平线笔直的将蓝天与雪原分隔在两边。据说夜间因这里
无物遮挡，可遍观满天星斗。进山的人们多在此祈求上苍的保佑。
LONG	);
	set("exits", ([ 
              "west" : __DIR__"ermk",
              "southeast" : __DIR__"gucd",
        ]));
	
        set("objects",([
        //      "kungfu/class/shenlong/lu" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}
