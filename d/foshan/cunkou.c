//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "麻溪铺");
        set("long", @LONG
这里是湘西沅陵南郊的一个小村庄。村子不大，民风淳朴。村东有
一条贯通南北的大道。西边有户人家，三间小瓦房，院里不时传出习武
的吆喝声。村子的南面有个小山包。
LONG
        );
        set("exits", ([
		"east" : __DIR__"road4",
		"west" : __DIR__"yard",
		"southup" : __DIR__"hill",
	]));

	set("objects", ([
		"/d/emei/npc/cow" : 1,
		"/d/xingxiu/npc/xiaoxiang-zi" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
