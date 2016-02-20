//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "三元宫");
        set("long", @LONG
此处是历代高僧法骨所置之地。一座紫檀木的灵塔立在殿中，高四丈五尺，
分十三层，呈六边形，端重庄严。四周站了八座二丈余高的护法金刚。瞠目狞牙。
大殿内光线灰暗，松香味刺鼻，一片寂静。殿中央唯矗一尊释加摩尼的铜像。
LONG
        );
        set("no_clean_up", 0);
        set("cost", 3);
        set("exits", ([
		"northwest" : __DIR__"tianls9.c",
        "south" : __DIR__"tianls5.c",		]));
setup();
        replace_program(ROOM);
}


























