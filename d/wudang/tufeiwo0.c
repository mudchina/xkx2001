//Cracked by Roath
// tufeiwo0.c 林中小路
// by Cleansword 1996/2/2

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
	你走在一条僻静的林中小路上，两旁是阴森森的树林。只见左右前后，到处
都是铺天盖地的松树林。几十丈高的大松树簇在一块，密实的枝叶象一蓬蓬巨伞
般伸向天空，把阳光遮得丝毫也无。据说这里经常有土匪出没，不可久留。
LONG
	);
        set("outdoors", "wudang");

	set("no_sleep_room",1);

	set("exits", ([
		"southup" : __DIR__"tufeiwo1",
		"northdown" : __DIR__"wdroad7",
	]));

        set("objects", ([
                __DIR__"npc/yetu" : 1 ]));

	set("cost", 1);
	setup();
}
